
#include <iostream>
using namespace std;
//��������غ������﷨������ֵ operator �����(�����б�)
//���غ�����Ϊ�ǳ�Ա��������Ա�����汾��
//�ǳ�Ա������Ҫfriend ����Ա�����Ĳ��������������Ա����ʡ�Բ�д
// 
//ע�⣺
//��1�������Զ����������͵����ÿ����ô����������ʽ��������������Ҫ���ؾֲ����������ã�
//���� CGril& operator+(CGril& g, int score)   д���� g - 20-5-3
//��2�����غ��������б��е�˳�������������λ�á�
//���� CGril& operator+(CGril& g, int score)   д����g + 30 + 30
//����λ�øı� CGril& operator+( int score,CGril&g)  д����30 + 30 +g+30;
//������������Ҫ��Ӧ CGril& operator+(CGril& g, CGril& g1)  д��: g+g;
//��3�����غ����Ĳ����б���������һ�����û��Զ������ͣ���ֹ����ԱΪ���������������������������̹淶���������أ�
//��4�������������ڼȿ����ǳ�Ա����Ҳ������ȫ�ֺ�����Ӧ�����ȿ��ǳ�Ա�������������������������صĳ��ԡ�
//��5�����غ�������Υ�������ԭ���ĺ�������ȼ���
//��6�����ܴ����µ������
// (7) ���������ֻ��ͨ����Ա������������
// = () [] ->


class CGril   //������
{
	string m_name;
	int m_xw;
	int m_score;
	//friend int operator+(CGril& g, int score);  //�ǳ�Ա��������˽�г�Ա��Ҫ������Ԫ����friend
	//friend int operator-(CGril& g, int score);

	friend CGril& operator+(CGril& g, int score);
	friend CGril& operator+(int score, CGril& g);
	friend CGril& operator+(CGril& g, CGril& g1);
	//friend CGril& operator-(CGril& g, int score);
public :
	CGril(string m_name = "��ʩ", int m_xw = 87, int m_score = 60)
	{
		this->m_name = m_name;
		this->m_xw = m_xw;
		this->m_score = m_score;
	}
	void show() { cout << "���� ��" << m_name << " ��Χ : " << m_xw << " ���� : " << m_score << endl; };

	void operator=(int score)  //=����������ǳ�Ա����
	{
		this->m_score = score;

	}
	
	CGril& operator-( int score)//��Ա��������
	{
		m_score = m_score - score;
		return *this;   //��Ա�����Դ���ʽclass 
	}


};

//�ǳ�Ա��������+�����     �﷨������ g+10
//void operator+(CGril& g, int score)
//{
//	g.m_score = g.m_score + score;
//}
////�ǳ�Ա��������-�����	�﷨������ g-10	
//void operator-(CGril& g, int score)
//{
//	g.m_score = g.m_score - score;
//}

//���غ���������ֵ
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

//��������		�﷨������g + 30 + 30;
CGril& operator+(CGril& g, int score)
{
	g.m_score = g.m_score + score;
	return g;
}
//�����б��˳���������ʱ������λ��   30 + 30 +g+30;
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
	g=g - 20-5-3; //��Ч�� operator-(operator-(operator-(g,20),5),3) ����д��������
	g.show();
	return 0;
}