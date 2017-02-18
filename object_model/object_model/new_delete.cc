//new��delete

/*
	new��delete�Ļ��ƣ�
	new��delete�����Ǻ�������C++�еĹؼ���
	����new����һ������ʱ�������ڶ���Ϊ��������ڴ棬Ȼ��Ϊ����ڴ���ù��캯����
	������һ��ָ��new������ұ����͵�ָ�롣
	����delete�ͷ�һ������ʱ�����ȵ�������������Ȼ���ͷ��ڴ棻ע�⣺delete���ʽ��Ҫ
	һ������ĵ�ַ��
	new��������ʽ��C++��һ�����Խṹ���������ء����û�������operator new()������

	�ο����ͣ�http://www.cnblogs.com/hazir/p/new_and_delete.html
*/

#include<iostream>

using namespace std;

class Time {
public:
	Time(int h, int m, int s);
	~Time();
private:
	int hour;
	int min;
	int sec;
	char *name;
};

Time::Time(int h, int m, int s) :hour{ h }, min{ m }, sec{ s } {
	name = new  char[h];
	cout << "Construct object " << endl;
	cout << "Time is " << hour << ":" << min << ":" << sec << endl;
}

Time::~Time()
{
	delete[] name;
	cout << "Destructing object" << endl;
}

void main6()
{
	Time *p1 = new Time(1, 2, 3);
	delete p1;   //delete p1��֪��p1��һ��Time�������Ի������������
	void *p2 = new Time(3, 2, 1);       //delete�ᵼ���ڴ�й©
	delete p2;   //delete p2�� ���ǲ�֪��p2�����ͣ�ֻ���ͷ�p2������ڴ棬���ǲ��������������
	//ע����ʹ��void*����ɾ����֮ǰһ��Ҫ����ת�����ʵ����ͽ����ͷ�
	void* p3 = new Time(2, 3, 4);
	delete (Time*)p3;

	int *p4 = new int(14);
	cout << *p4 << endl;
	delete p4;
}