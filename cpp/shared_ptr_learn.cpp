//
// Created by root on 3/17/21.
//

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct MediaAsset
{
	virtual ~MediaAsset() = default;
};

struct Song : public MediaAsset
{
	std::wstring artist;
	std::wstring title;
	Song(const std::wstring& artist_, const std::wstring& title_) : artist(artist_), title(title_)
	{
	}
};

struct Photo : public MediaAsset
{
	std::wstring date;
	std::wstring location;
	std::wstring subject;
	Photo(const std::wstring& date_, const std::wstring& location_, const std::wstring& subject_) :
		date(date_), location(location_), subject(subject_)
	{
	}
};

using namespace std;
int main()
{
	auto sp1 = make_shared<Song>(L"ZhaoLei", L"Chengdu");
	shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));
	shared_ptr<Song> sp5(nullptr);
	sp5 = make_shared<Song>(L"LiuHuan", L"HaoHanGe");

	auto sp3(sp2);
	auto sp4 = sp2;
	shared_ptr<Song> sp7(nullptr);
	sp1.swap(sp2);

	vector<shared_ptr<Song>> v{
		make_shared<Song>(L"A", L"A"),
		make_shared<Song>(L"A", L"B"),
		make_shared<Song>(L"C", L"C")
	};
	vector<shared_ptr<Song>> v2;
	remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](const shared_ptr<Song>& s)
	{
		return s->artist == L"C";
	});
	for (const auto&s : v2)
	{
		wcout << s->artist << L": " << s->title << endl;
	}

	vector<shared_ptr<MediaAsset>> assets {
		make_shared<Song>(L"LiuDeHua", L"BingYu"),
		make_shared<Song>(L"PGONE", L"Kill The One"),
		make_shared<Photo>(L"2008-08-08", L"BeiJing", L"OOOOO")
	};

	vector<shared_ptr<MediaAsset>> photos;
	copy_if(assets.begin(), assets.end(), back_inserter(photos), [] (const shared_ptr<MediaAsset> p) -> bool
	{
		shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
		return temp != nullptr;
 	});

	for (const auto& p: photos)
	{
		wcout << "Photo location: " << (static_pointer_cast<Photo>(p)->location) << endl;
	}

	auto song1 = new Song(L"A", L"A");
	auto song2 = new Song(L"A", L"A");
	shared_ptr<Song> p1(song1);
	shared_ptr<Song> p2(song2);
	// Unrelated shared_ptr are never equal.
	wcout << "p1 < p2 = " << std::boolalpha <<(p1 < p2) << endl;
	wcout << "p1 == p2 = " << std::boolalpha << (p1 == p2) << endl;

	// Related shared_ptr instances are always equal.
	shared_ptr<Song>& p3(p2);
	wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;
	return 0;
}
