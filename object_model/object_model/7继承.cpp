//�̳�

/*
	�̳��й��캯���������������õĴ���
	���캯�����Զ������ࣩ���£������ࣩ���죬���ȹ�����࣬�ٹ���������
	�����������Եף������ࣩ���ϣ����ࣩ�������������������࣬����������
*/

#include<iostream>

using namespace std;

class Base
{
public:
	Base(int b) :b1{ b } { cout << "Base is constructed..." <<"b1="<< b1 << endl; }
	~Base() { cout << "Base is destructed" << endl; }
	void f(int i) { cout << "Base::f(int i)" << endl; }
	void f(string s) { cout << "Base::f(string s)" << endl; }
	Base& operator=(const Base&);
	int operator=(int a) { return 8; }
			//���캯�������������Լ����ظ�ֵ����������ܼ̳е�������֮��
	Base& operator++() { ++this->b1; return *this; }

public:
	int b1;
};

Base& Base::operator=(const Base& b)
{
	this->b1 = b.b1;
	return *this;
}

class Derived1 :public Base {
public:
	Derived1(int d) :Base(d), d1{d}, b1(d), b2(d){ 
		cout << "Derived1 is constructed..." << "d1=" << d << endl; 
		b2 = b1;
	}
					//���캯���ĳ�ʼ���б���û�ж����г�Ա����ͻ������Ĺ��캯�����е���֮ǰ���޷�����ù��캯���塣
					//C++����Ϊ�����г�Ա�����ڹ��캯����������֮ǰ�ͱ���ʼ���ˣ�һ�����������ţ�����Ϊ�����Ӷ��������ȷ
					//��ʼ����
	~Derived1() { cout << "Derived1 is destructed" << endl; }
	 //Derived1& operator=(Derived1&) = delete;
private:
	int d1;
	Base b1;
	Base b2;
public:
	void f(int i) { cout << "Derived1::f(int i)" << endl; }
			//�������أ��κ�ʱ�����¶����˻����һ�����غ������������е����������İ汾���Զ�����
								//����Base�е�void f(string s)����������Derived1�б����أ��޷�ʹ��

};

class Derived2 :public Derived1 {
public:
	Derived2(int d) :Derived1(d), d2{ d }, b(d) { cout << "Derived2 is constructed..." << "d2=" << d << endl; }
	~Derived2() { cout << "Derived2 is destructed" << endl; }
private:
	int d2;
	Base b;
};

class Base7
{
	virtual void b_func1() {}
	virtual void b_func2() {}
	void b_func3() {}
};

class Derived71 :public Base7
{
	virtual void d1_func1() {}
	virtual void d1_func2() {}
};

class Derived72 :virtual public Base7
{
	virtual void d2_func1() {}
	virtual void d2_func2() {}
	virtual void d2_func3() {}
	virtual void d2_func4() {}
};

void TestClass()
{
	Base b1{ 1 }, b2{ 2 };
	b1.b1 = b2.b1;
	cout << "b1=" << b1.b1 << endl;
	Derived2 d(1);
	Derived1 d1(2);
	Derived1 d2(3);
	d2 = d1;  //�����˻����operator=
}

void main7()
{
	Derived71 d71;
	Derived72 d72;
	static Base7 b1;
	void* p = &b1;
	//������void*��ָ��������������Ϊvoid*��ָ��ֻ�ܹ�����һ����ַ��һ���׵�ַ�����������ǲ���֪�����ĵ�ַ�ռ䣨����ַ���ĵ��ģ�
	cout << "sizeof(Derived71)=" << sizeof(Derived71) << endl;
	cout << "sizeof(Derived72)=" << sizeof(Derived72) << endl;
	cout << "sizeof(static Base7)=" << sizeof(b1) << endl;
	TestClass();
	system("pause");
}

/*
	���н����
	Base is constructed...b1 = 1
	Base is constructed...b1 = 1
	Derived1 is constructed...d1 = 1
	Base is constructed...b1 = 1
	Derived2 is constructed...d2 = 1
	Derived2 is destructed
	Base is destructed
	Derived1 is destructed
	Base is destructed
	Base is destructed
*/