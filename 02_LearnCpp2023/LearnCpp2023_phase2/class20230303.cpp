/*
[array]
stl �����̳�
stl���� �����ϴ� �迭 

������ ������.
���� �迭�� �迭 ��ü�� �ű���� memcpy�� ������ݾ�. �ٵ� �׳� = �� ���� ���� 

.data()	= array�� ù��° �ּ�. 
���� �迭�� �迭�� �̸��� �׳� ù��° �ּҿ���. stl array�� .data�� ���ؼ� �����ü�����. 

.fill(999);	//	��� ���ҵ��� ���� 999�� �ʱ�ȭ. 

iterator�� �翬�� �ִ�. ����� �ݺ����ε� 

��� �����迭�̶� �߰������� �ȵȴ�. �����迭�̶� �ϳ����߰��� �ְ�, �� �� �ֵ��� �ڷ� �̴°� �Ұ����ϴ�.
���������� erase�� �ȵȴ�.(�߰� ����) �����迭�̶� �ֵ��� ������ ��� �� ����. 
------------------------------------------------------------------

[c++11 ����]

* ���ٽ�
	���ٽ��̶� 
		- stl�˰������� �����ڸ� �����ϴ� ������� �Լ� ��ü�� ������ �����ϱ� ���� ����

	�Լ� ��ü�� ����
		- �ۼ��� �������� ���ϰ� 
		- �Ϲ��Լ����� ������ ��ƴ�.
		- �Լ� ��ü�� �ᱹ ��ü��. ������ ȣ��, �Ҹ��� ȣ���� �� �߻��Ѵ�. (�Լ� ��ü�� �Լ� �����ͷ� ���۽�Ű�°ͺ��ٴ� ����. )
			���ٽ��� ������ ���ϸ� �ζ����Լ������Ŷ� ��ü ����,�Ҹ����� ���ϼ��ִ�.���ٽ��� ġȯ���� ������.

	���ٽ� ����
		[] : ���� �Ұ���. �����Ϸ��� �긦 ���� ���ٽ��̶�� ���� ����
		() : �Ķ�ϸ� ������. �Ϲ� �Լ��� �Ű������� ���� �ǹ�
		{} : ���� ��ü. �Լ� ��ü�� ���� �ǹ�

		[](){cout << " hello world";}	//�̷��� �ϸ� ���� ���� ����Ű�, �Լ��� ȣ�����Ϸ��� �Լ� ȣ�� ������ ()�� ���̸��
		[](){cout << " hello world";}();	//�̷����ϸ龲����

		�ؿ� �����ڷ� ���ٽ� ������ ���� ()�Ⱥ����ݾ�. 
		�װ� �ζ����Լ�..?�Լ� ������..?�� ���ŷ�. �Լ� �����;ƴϰ� �ζ����Լ� ���ϴµ�..? ����� ������

		��ȯŸ���� ���������ε� ����. �׷��� ���������� �Ҽ����� �ϴ°� ����. 
		-> �� ��ȯŸ�� ���������� ��������
		[]()->int {}	//�̷���

		���� �Ұ���[] �� �ٸ����� ĸó���̶���� �θ���. 
		�� ĸó���� ���� �ܺε����͸� ������ �� �ִ�. 

		int iEvenSum(0);
		int iOddSum(0);
		for_each(vec.begin(), vec.end(), [iEvenSum, iOddSum](int n) {	// iEvenSum, iOddSum�� ĸ���ϰڴٴ� ����.
				if (0 == n % 2) iEvenSum += n;
				else iOddSum += n;
		});	
		�̷��� ĸó���� ������ �׳� �����縦 �ع���. �׷��� ���⸦�ϸ� ��������. 
		const�� ��ȯ�Ǽ� �׷��µ� �׷��� mutable�� ���� ���� ������ �ȳ�. 
		�׷��� ���� iEvenSum, iOddSum�� ������ ������ ����. 

		�׷��� &�� �����;��ϴ°Ŵ�. 
		int iEvenSum(0);
		int iOddSum(0);
		for_each(vec.begin(), vec.end(), [&](int n) {	
				if (0 == n % 2) iEvenSum += n;
				else iOddSum += n;
		});
		�̷��� �ؾ� �������� ���� ���°� ��. 

		�̰� ĸó���ȿ� �����ִ°Ͱ� ���°� ����. (÷�� ���� ����) 
		[] : �ƹ��͵� ĸó ����
		[&x]: �ܺ� �����߿� x��� �̸��� ������ ���۷� ĸó .. 
		... 

		static, ����, class�� �ɹ� ������ ĸó�� �Ұ���. 
		���ٽ��� �ζ����Լ��� ������ 

		�ٵ� ���ٽĿ��� �ɹ� ������ ĸó�Ϸ���, �ϴ� ���������� ����, �°� �ɹ� ���� ���� ������ �ϰ�, �� �������� ���������� ���ٰ� �����ϰ� �ϱ� 


R-value���۷���
	���� ���۷����� l-value�� ������ �����ϴ�.
	int& iref = 10;�̰Ǿȵȴٰ�. 

	�ٵ� ���ϰ������� const�� �ٿ��� �б� ���� ���۷����� ���� ������. 
	const int& r2 = 10;	
	��� �������� �� ���� ����. r2 = 20;	�̷��� ���� �ȵ�
	�̰� ������� => �̵������ڿ��� �� 


�̵������� 
	�ؿ� ����

decltype
	auto�� ����Ҽ��ִ� ����

	int x = 10;
	decltype(x) y = x;		//�˾Ƽ� int�� �ν���. 
		
	tag t;
	decltype(t.memver)	Test = 3.14; // �˾Ƽ� double�� �ν���
	cout << Test<<endl;

	...�ٵ� ��.. auto���� �� 
	
*/

#include "stdafx.h"
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

void Swap(int& a, int& b) {
	int itemp = a;
	a = b;
	b = itemp;
}

class CTest {
public:
	CTest() :m_pArray(nullptr), m_iSize(0) {}
	CTest(int a) : m_pArray(new int[m_iSize]), m_iSize(a) {}
	CTest(const CTest& _t) {
		// ���� ���� �ϴ� ���� ������
	}

	// �̵�������
	CTest(CTest&& rvr) {
		m_pArray = rvr.m_pArray;
		m_iSize = rvr.m_iSize;
		rvr.m_pArray = nullptr;	// ������ nullptr�� ��������. ���� ��ü�� �ּҴ� ����� �Ұ����ϰ� ��. 
								// �̰� "�̵� ��, ������ ����"�� �ߴٰ� ��. 
								// �̰� ��������ڿ��� ������
		// (����) �̵��������� ���� �����϶�. 
	}

	~CTest() {
		if (m_pArray) {
			delete m_pArray;
			m_pArray = nullptr;
		}
	}



private:
	int* m_pArray;
	int m_iSize;
};

int main() {
	
	/* Array */
	{
		int iArray[5] = { 1,2,3,4,5 };
		array<int, 5> arrEx = { 1,2,3 };
		array<int, 5> arrEx2 = arrEx;

		auto iter = arrEx.begin();
		iter += 2;

	}

	/* ���ٽ� */
	{
		vector<int> vec{ 10,20,30,40,50 };

		for_each(vec.begin(), vec.end(), [](int n) {cout << n << ","; });	//�̰� �����ڷ� ���ٽ��� ���� ��. 
		cout << endl;

		//for_each(vec.begin(), vec.end(), [](int n)->bool {return (n%2!=0) });	//�̰� �����ڷ� ���ٽ��� ���� ��. 

		int iEvenSum(0);
		int iOddSum(0);
		for_each(vec.begin(), vec.end(), [&](int n) {	// iEvenSum, iOddSum�� ĸ���ϰڴٴ� ����. 
														/*	���⼭ &�� ������ ������ ���µ� 
															iEvenSum, iOddSum��
															
														*/
			if (0 == n % 2) iEvenSum += n;
			else iOddSum += n;
		});	//�̰� �����ڷ� ���ٽ��� ���� ��. 
		cout << iEvenSum << ", " << iOddSum << endl;
		
		[](int i) {cout << i<<" hello world"<<endl; }(10);

		[](int i = 100) {cout << i << " hello world" << endl; }();	//����Ʈ �Ű����� ���� 

		int iResult = [](int a, int b) {return a + b; }(10, 20);	// ���ϰ� ���������൵ ���������� �����Ϸ��� �Ǵ���. �ٵ� �����������ϴ°� ���⵵ ����, ȿ���� ����. 
		cout << iResult << endl;
	}
	
	/* R - value ���۷��� */
	{
		int iA(10), iB(20);

		cout << iB << ", " << iA << endl;
		Swap(iA, iB);
		cout << iA << ", " << iB << endl;

		//Swap(10, 20);	//�̰� �ȵ�. r-value�� ����Ÿ�Կ� ���� �������ϱ�.  

		// r-vlaue���۷��� 
		int& r = iA;
		int&& rR = 999;	// r-value�� ���� ���� 
		//int&& rR = iA // ��� l-value�� ���� �Ұ��� 
		rR = iB;	//l-value�� ���Ե� ���� 
		
	}

	/* �̵� ������  */
	{
		// ���� ���� ������ ������ٰ� ��������.. 
		CTest t(4);
		CTest temp(t);

		CTest t2(100000000);	// �����迭�� 100000000�̸�ŭ ����
		CTest t3(t2);			// �̰� ��ü �����ϴµ� �ð��� �󸶳� �ɸ��� => 0.156sec ���� ����. �̰� �ǰ� �����ɸ��°���. 

		// �̷��� �����ؼ� ��°� �ƴ϶� ������ �״�� �̵���Ű�� �������ϰڴٴ°���. 
	
		// �̵������� ȣ��
		CTest MoveCon(std::move(t2));	//�̵������� ������ move()��� �Լ� ȣ���ؾ���. 
										// move(): �Ű������� ���޹��� ����� R-value ���۷����� ĳ�����ϴ� �Լ� 
										// �̷��� �ؾ��� �̵������� ȣ���� �������� 
										// �̷��� �����ϴ°� ���� t3���� �����ںҷ��� �����ϴ°ͺ��� �ξ� ���� ���� �����ð��� ���. 

		/* ���Ͱ� Ŭ����(�����Ͱ� �ƴ�) �� �����ٰ� ��. vec.push_back(CTest(10000000))�̷�������. 
		* �̰� ���ſ��� CTest(1000000000)�� �ӽð�ü�� ����� -> �װ� �ٽ� ������. 
		* �׷��ϱ� 1000000��ŭ �������ϰ�, �װ� ������� �� ��. 
		* �׸��� 10000000�� �� ������. (�ӽð�ü�ϱ� �� ������ �P���� ��) 
		�̰� ��û �����ɸ�. �ٵ� �̵������ڷ� �ϴϱ� 
		�ϴ� ���簡 �Ͼ�� �ʰ�, ������ ������ �ʿ䵵 ���°���. ������ü�� �� �Ű� �����Ŵϱ� ������ �����ϸ�ȵǴ°���. 
		��û �ð��� �پ���. 

		���縦 �� �ؾ��ϴ°� �ƴϸ� �̵������� ���°� ����. 

		*/
	}
}