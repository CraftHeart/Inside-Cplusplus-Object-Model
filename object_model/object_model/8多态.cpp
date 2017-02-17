//��̬
/*
	�ο����ӣ�
	http://blog.jobbole.com/101583/
	http://www.cnblogs.com/clor001/p/3313589.html
	http://www.cnblogs.com/clor001/p/3329652.html
	��C++��ѧ�̡̳�P470~P472
	��C++���˼�롷��һ�� ��15��
*/

/*
	��̬�󶨣�
	����ʱ�󶨣�ͨ��������ã�����Ա��������virtual����ͨ�����������ض������
	ʹ��Բ���Աѡ�������������ʱ�������ĸ������ڱ���ʱ���Ѿ������ˡ�

	��̬�󶨣�
	����ʱ�󶨣�ͨ����ַʵ�֣��������ͨ��ָ��������Ļ���ָ�����ָ��������
	����Ļ������õ����麯������ô����������ָ��������Ͷ�����ָ������ͣ�
	��̬��ѡ����ȷ�������ຯ������ִ��ʱѡ����ʵĵ��ú�����Ϊ��̬�󶨡�

	**������ָ��ָ��������������ͼͨ���û���ָ����ý��������ຬ�еĳ�Ա�����±������

	**��Ҫ�ڹ��캯�������������е����麯�����������ˣ�����ʵ������ơ�

	**���캯������ʹ�麯����
	1.�Ӵ洢�Ƕ�������
	���캯�����ڴ���һ�������ʱ�ŵ��ã���vfptr�洢���������ڴ��У�����ִ�й��캯����
	����������vfptr�����麯����ͨ��vfptr�����õģ�������캯������ģ�����Ҫͨ�� vtable�����ã�
	���Ƕ���û��ʵ������Ҳ�����ڴ�ռ仹û�У���ô��vtable�أ����Թ��캯���������麯����
	2.��ʵ�ֽǶ�������
	vfptr�ڹ��캯�����ú�Ž�����������캯�������ܳ�Ϊ�麯�������ҹ��캯�����������ṩ��ʼ����
	�ڶ���������ִֻ��һ�Σ����Ƕ���Ķ�̬��Ϊ��Ҳû�б�Ҫ��Ϊ�麯��
*/
#include<iostream>
#include<typeinfo>

using namespace std;

class MyBase 
{
public:
	MyBase(int i) :b{ i } { cout << "Base construct" << endl; }
	  ~MyBase() { cout << "Base destruct" << endl; }
	virtual void func1() { cout << "Base::func1()" << endl; }
	virtual void func2() { cout << "Base::func2()" << endl; }
	virtual void func3() { cout << "Base::func3()" << endl; }
private:
	int b;
};

class MyBase1
{
public:
	MyBase1(int i) :b{ i } { cout << "Base1 construct" << endl; }
	~MyBase1() { cout << "Base1 destruct" << endl; }
	virtual void func1() { cout << "Base1::func1()" << endl; }
	virtual void func2() { cout << "Base1::func2()" << endl; }
	virtual void func3() { cout << "Base1::func3()" << endl; }
private:
	int b;
};

class MyDerived1:public MyBase
{
public:
	MyDerived1(int d) :d1{ d }, MyBase(d){ 
		func1();//ִ�н��Ϊ��Derived1::func1()
/*
	�ڹ��캯���е����麯����������ڹ��캯���в�����
	ԭ�򣺹��캯���Ĺ���������һ���������κι��캯���У�����ֻ�ǲ����γɶ��󡪡�����
	ֻ��֪�������ѱ���ʼ����������֪���ĸ����Ǵ��������̳ж����ġ�Ȼ���麯���ڼ̳в����
	�ǡ���ǰ���͡����⡱���е��á������Ե������������еĺ�������������ڹ��캯����Ҳ����������
	�п��ܵ���δ����ʼ���ĳ�Ա���⽫�������Ѻ����
	ͬʱ��VFPTR��״̬���ɱ������õĹ��캯��ȷ���ġ������Ϊʲô���캯���ĵ���ʱ�ӻ��ൽ�����ࡣ
*/
		cout << "Derived1 construct" << endl; }
	 ~MyDerived1() {
		//MyBase::func1();
		cout << "Derived1 destruct" << endl; 
	}
/*���������������麯��
	��������Ѿ�֪������ʲô���ͣ����ڹ����ʱ��֪������һ�������ѹ��죬����VPTR���ѱ���ʼ����
	�����ܷ����麯�������ڼ̳��У�������ѻ����������������Ϊ�麯�������׳����ڴ�й©����
	���һ���������麯���������Ҫ�ṩһ����������������ʹ��������������һ���Ǹ�����Ҫ�ġ�
	����Ա�֤��һ��������Ķ���ͨ������ָ��ɾ��ʱ������Զ�������������������ᱻ���á�
*/
	virtual void func1() { cout << "Derived1::func1()" << endl; }
	virtual void d1_func2() { cout << "Derived1::d1_func2()" << endl; }
	virtual void d1_func3(int i) { cout << "Derived1::d1_func3()" << endl; }
	void d1_func4() { 
		//����ͨ��Ա�����е����麯���������Ҳ������
		func1(); //ִ�н��Ϊ��Derived1::func1()
		}
private:
	int d1;
};

class MyDerived2 :public MyBase
{
public:
	MyDerived2(int d) :d2{ d }, MyBase(d) { cout << "Derived2 construct" << endl; }
	//virtual ~MyDerived2() { cout << "Derived2 destruct" << endl; }
	virtual void func1() { cout << "Derived2::func1()" << endl; }
	virtual void d2_func2() { cout << "Derived2::d2_func2()" << endl; }
	virtual void d2_func3() { cout << "Derived2::d2_func3()" << endl; }
	virtual ~MyDerived2() { cout << "Derived2 destruct" << endl; }
private:
	int d2;
};

class MyDerived3 :public MyDerived1
{
public:
	MyDerived3(int d) :d3{ d }, MyDerived1(d) { cout << "Derived3 construct" << endl; }
	virtual void d3_func1() { cout << "Derived3::func1()" << endl; }
	virtual void d1_func2() { cout << "Derived3::d1_func2()" << endl; }
	virtual void d3_func3() { cout << "Derived3::d3_func3()" << endl; }
	virtual void d3_func4() { cout << "Derived3::d3_func4()" << endl; }
	virtual void d3_func5() { cout << "Derived3::d3_func5()" << endl; }
	virtual ~MyDerived3() { cout << "Derived3 destruct" << endl; }
private:
	int d3;
};

//��̳�
class MyDerived4 :public MyBase, public MyBase1
{
public:
	MyDerived4(int d4) :MyBase(d4), MyBase1(d4), d4_{ d4 } { cout << "Derived4 constructor" << endl; }
	virtual void func1() { cout << "Derived4::func1()" << endl; }
	virtual void d4_func2() { cout << "Derived4::d2_func2()" << endl; }
	virtual void d4_func3() { cout << "Derived4::d2_func3()" << endl; }
	~MyDerived4() { cout << "Derived4 destructor" << endl; }
private:
	int d4_;
};

void test_derived4()
{
	MyBase* b0_1 = new MyDerived4(10);
	MyBase1* b1_1 = new MyDerived4(12);

	b0_1->func1();//Derived4::func1()
	b0_1->func2();//Base::func2()
	b0_1->func3();//Base::func3()
	//b0_1->d4_fun2();

	b1_1->func1();//Derived4::func1()
	b1_1->func2();//Base::func2()
	b1_1->func3();//Base::func3()
}

typedef void(*func)(void);

class B
{
public:
	B(int i) :i{ i } { 
		func1();
		cout << "B constructor" << endl;
	}

	virtual void func1() { cout << "B::func1()" << endl; }
	virtual void func2() { cout << "B::func2()" << endl; }

	void func3() { 
		func1();
		cout << "B::func3()" << endl; 
	}
	static void func4() { cout << "B::func1()" << endl; }
	virtual ~B() {}
private:
	int i;
	static int j;
};
int B::j = 1;

void test()
{
	MyBase *b = new MyDerived1(1);
	MyDerived1* d = new MyDerived1(1);
	
	b->func1();//������Ϊ��MyDerived1::func1()
	cout << "typeinfo is " << typeid(*b).name() << endl;
	d->func1();
	
	delete b;
	delete d;
}

class A {
	A() {}
	~A() {}
};


void main()
{
	//A a;
	test_derived4();
	test();
	size_t m = sizeof(A);
	B b(1);
	MyBase base(1);
	MyDerived1 d1(2);// ���̳�
	MyDerived2 d2(3);// ���̳�
	MyDerived3 d3(4);//���̳�
	MyDerived4 d4(5);// ��̳�

	d1.d1_func4();
	cout << "vfptr�ĵ�ַ=" << (int*)&d3 << endl;
	cout << "vftable�ĵ�ַ=" << (int*)*(int*)&d3 << endl;
	cout << "vftable��һ�������ĵ�ַ=" << (int*)*(int*)*(int*)&d3 << endl;
	cout << "������Ϣ��ַ=" << (int*)*(int*)&d3 - 1 << endl;
	for (int i = 0; i < 5; ++i)
	{//���ܵ����ĸ���������Ϊclass derived1��d1_fun3(int)�ĺ���ָ��������˴�������
		//���벻�ᱨ���������лᱨ��
		func p = (func)*((int*)*(int*)&d1 + i);
		p();
	}
	
	
	system("pause");
}