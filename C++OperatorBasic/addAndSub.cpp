
#include <iostream>
using namespace std;
//运算符重载函数的语法：返回值 operator 运算符(参数列表)
//重载函数分为非成员函数、成员函数版本。
//非成员函数需要friend ，成员函数的参数中有隐性类成员可以省略不写
// 
//注意：
//（1）返回自定义数据类型的引用可以让搓个运算符表达式串联起来。（不要返回局部变量的引用）
//例如 CGril& operator+(CGril& g, int score)   写法： g - 20-5-3
//（2）重载函数参数列表中的顺序决定操作数的位置。
//例如 CGril& operator+(CGril& g, int score)   写法：g + 30 + 30
//参数位置改变 CGril& operator+( int score,CGril&g)  写法：30 + 30 +g+30;
//参数的类型需要对应 CGril& operator+(CGril& g, CGril& g1)  写法: g+g;
//（3）重载函数的参数列表中至少有一个是用户自定义类型，防止程序员为内置数据类型重载运算符。（编程规范尽可能遵守）
//（4）如果运算符重在既可以是成员函数也可以是全局函数，应该优先考虑成员函数，这个样更符合运算符重载的初衷。
//（5）重载函数不能违背运算符原来的含义和优先级。
//（6）不能创建新的运算符
// (7) 以下运算符只能通过成员函数进行重载
// = () [] ->


class CGril   //定义类
{
	string m_name;
	int m_xw;
	int m_score;
	//friend int operator+(CGril& g, int score);  //非成员函数访问私有成员需要声明友元函数friend
	//friend int operator-(CGril& g, int score);

	friend CGril& operator+(CGril& g, int score);
	friend CGril& operator+(int score, CGril& g);
	friend CGril& operator+(CGril& g, CGril& g1);
	//friend CGril& operator-(CGril& g, int score);
public :
	CGril(string m_name = "西施", int m_xw = 87, int m_score = 60)
	{
		this->m_name = m_name;
		this->m_xw = m_xw;
		this->m_score = m_score;
	}
	void show() { cout << "姓名 ：" << m_name << " 胸围 : " << m_xw << " 分数 : " << m_score << endl; };

	void operator=(int score)  //=运算符必须是成员函数
	{
		this->m_score = score;

	}
	
	CGril& operator-( int score)//成员函数重载
	{
		m_score = m_score - score;
		return *this;   //成员函数自带隐式class 
	}


};

//非成员函数重载+运算符     语法操作： g+10
//void operator+(CGril& g, int score)
//{
//	g.m_score = g.m_score + score;
//}
////非成员函数重载-运算符	语法操作： g-10	
//void operator-(CGril& g, int score)
//{
//	g.m_score = g.m_score - score;
//}

//重载函数带返回值
//int operator+(CGril& g, int score)
//{
//	g.m_score = g.m_score + score;
//	return g.m_score;
//}
//int operator-(CGril& g, int score)
//{
//	g.m_score = g.m_score - score;
//	return g.m_score;
//}

//返回引用		语法操作：g + 30 + 30;
CGril& operator+(CGril& g, int score)
{
	g.m_score = g.m_score + score;
	return g;
}
//参数列表的顺序决定重载时参数的位置   30 + 30 +g+30;
CGril& operator+( int score,CGril&g)
{
	g.m_score = g.m_score + score;
	return g;
}
CGril& operator+( CGril& g, CGril& g1)
{
	g.m_score = g1.m_score +g.m_score;
	return g;
}
//g - 20-5;
//CGril& operator-(CGril& g, int score)
//{
//	g.m_score = g.m_score - score;
//	return g;
//}

int main()
{
	CGril g;
	g.show();
	30 + 30 +g+30+g;
	g.show();
	g=g - 20-5-3; //等效于 operator-(operator-(operator-(g,20),5),3) 这种写法不美观
	g.show();
	return 0;
}