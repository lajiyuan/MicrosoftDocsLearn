//
// Created by root on 3/18/21.
//
#include <iostream>
using namespace  std;

class cs
{
public:
	cs(int i): i_(i)  { cout << "cs(" << i <<") constructor!" << endl; }
	~cs() { cout << "cs destructor,i(" << i_ << ")" << endl; }

	cs& operator=(const cs& other)
	{
		i_ = other.i_;
		cout << "cs operator=()" << endl;
		return *this;
	}

	int get_i() const { return i_; }
	void change(int i)  { i_ = i; }

private:
	int i_;
};

cs get_cs()
{
	static int i = 0;
	return cs(i++);
}

void func(cs& c)
{
	cout << "c:" << c.get_i() << endl;
}

int main()
{
	
	//RFC : https://segmentfault.com/a/1190000003793498 , https://www.cnblogs.com/catch/p/3500678.html
// 在C语言中的定义 左值是一个表达式，可能出现在赋值操作的左边或右边，但右值只能出现在右边


// 在C++中的理解，左值是一个表达式，它表示一个可被标识的内存位置，可以使用&操作获取地址。如果不是左值，就是右值

// 非const左值引用不能使用右值对其赋值，比如某些构造函数 data(string &x) 不能，但是data(const string &x)就可以通过右值赋值

// C++存在带CV限定的右值，左值转右值时会保留CV属性 const volatile
// c++ 11 之后，允许右值引用，并可以通过成员函数来修改他的值, 比如上面的cs

// yes
	(get_cs() = cs(2)).change(323); // 右值引用并修改值
	get_cs() = cs(2);// operator=()
	get_cs().change(32);

	//func(get_cs()); no , get_cs() 得到右值，不是右值引用
	func(get_cs() = get_cs()); // yes operator = 返回右值引用
	cs a = get_cs();
	func(a); // yes 左值引用

}