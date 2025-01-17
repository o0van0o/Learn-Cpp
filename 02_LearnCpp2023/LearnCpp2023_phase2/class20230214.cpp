/*TOPIC: static / 
* 
static은 해당 클래스의 모든 객체가 공유하는 메모리가된다. 
엄연히 말하면 정적 매버들은 해당 클래스의 맴버가 아니다! 약간 주소만 옮겨놓은 것 마냥. 
그래서 정적 함수에서는 일반 맴버 변수를 못부르는거다. 맴버가 아니니까 
걍 static은 해당 클래스의 모든 객체가 공유하는 메모리니까 ..거 알지? 니 아는 그거 개념맞음. 

static 맴버 변수(클래스변수, 정적맴버 변수), static맴버 함수 (클래스 함수 ,정적맴버 함수 ) // 사실 '맴버'라고 이름 붙이는것도 좀 ㅡ렇긴함. 근데 다들 그렇게 부르니까 
static 함수를 난발하면 캡슐화의 의미가 사라진다. 이런 함수들은 보통 범용적으로 사용할만한 기능을 모아둔 클래스를 만들때, 거기의 함수들을 static으로 많이 한다. 
ex_ 충돌 처리를 하는 함수가 필요함. 이걸 몬스터, 플레이어, npc기타 등등 각 클래스에 똑같은 함수를 다 넣어주면 엄청 불필요한 코드가 길어짐. 
그러면 그냥 충돌이란 클래스를만들고, 충돌처리 함수를 static으로 설정해서, => 충돌 클래스를 따로 객체 생성할 필요도 없이 해당 함수를 쓰자. 이런식으로 쓰임 


static을 0 초기화 하면 bss안거치고, 그게 아니면 bss거쳤다가 나중에 초기화됨. 

레퍼런스 카운트(주소값을 복사하는 갯수) - 스마트 포인터 - 쉐어드포인터
래퍼런스 카운트 변수로staitc을 쓰는게 좋다. (그냥 static쓰는예시임)
쉽게 말해서 객체가 몇개 생성되는지 누적횟수를 카운팅 해야한다면 쓰라는말임
----------------------------------------------------------------------------------------------
복사 생성자 

복사 생성자를 쓸때 이득보는 경우 >> 맴버 변수가 엄청 많을때, 
									일반 생성자는 맴버 변수 1:1단위로 다 초기화함
									복사 생성자는 메모리 블록대 블록으로 초기화함. 
									(메모리 블록단위로, 통째로 복사해서 넣음) >> 맴버 변수가 엄청 많은 클래스간의 복사라면 이 방법이 더 빠르다. 
									다수의 같은 타입의 객체를 대량으로 생성할때는 복사 생성자가 좋음. 그리고 맴버 변수가 많을수록 복사 생성자가 좋음. 그게 아니면..그닥 이득은 아님. 
Class(const Class& rhs)	//rhs는 그냥... 복사 생성자의 매개변수로 자주 이름붙이는 거임. right hand side..? 뭐 그런거래 
복사 생성자와 일반 생성자는 맴버 변수를 1:1로 초기화하는지, 메모리 블록 단위로 초기화 하는지, 그 차이가 있는 것이다. 
	차이가 존재하긴함!!

복사 생성자가 호출되는 예시 상황
	1. 원본 객체를 매개 변수로 넣어서 객체 생성하는 경우
		Class c1;
		Class c2(c1);
	2. c1.print(c2);	
		print (Class src) { .. } // 매개변수로 value를 보내는건 "복사"다!! 이때 그 타입이 객체라면 복사 생성자가 불린다. ( 매개변수를 레퍼런스로 넘기면 원본 그대로를 넘기니까 복사 생성자를 쓰지 않아 이런 문제는 발생하지 않음. 포인터도 아마 마찬가지. )
	3. 함수에서 값을 반환할때  (return ...) 이것도 임시 메모리에 해당 값을 복사한다. 따라서 그 타입이 객체인 경우 (함수에서 객체 타입을 반환하는 경우), 복사 생성자가 호출된다. 

	근데 보통 함수의 매개변수로 우리가 레퍼런스나 포인터를 많이 쓰기 때문에 2번 경우에서 오류는 많이 안날수있는데, 마지막은 
	우리가 get함수같은거에서 객체를 막 반환하잔ㅇ하. 이때 안만들어줬으면 디폴트 복사 생성자를 호출하는거고, 뭔가 선언을 했ㅇ면 그 복사 생성자를 호출하는것이다. 

	
네오플 문제는 얕은 복사의 문제. 소멸시점때문에 문제가 발생한거임(두번 같은 메모리를 해제해서)
	매개변수로 객체를 얕은 복사 해온 그 함수가 끝나버리면 소멸자를 호출하면서 메모리를 해제함. 근데 얕은 복사니까 원래 객체의 맴버 포인터가 가리키던 메모리가 사실상 다 반환된거임.
	그러니까 그 뒤에 프로그램이 종료되면서 객체의 소멸자가 불리면서 >> 또 같은 heap메모리를 해제하라고 하니까, 두번이나 같은 메모리를 해제해서 오류가 남. 
얕은 복사가 일어나서 >> 얕은 복사한걸 이미 해제했기때문에 소멸자에서 또 원본을 해제할려고하니까 뭐라하는거임.

이걸 해결하기 위해서 깊은 복사가 일어나도록 해주면됨.>>깊은 복사를 실행하도록 사용자 정의 복사 생성자를 만들어주면됨.

구조체 안에 string넣고, memcpy하면 string만 얕은 복사가 일어남. 왜? string은 사실상 char*니까 깊은 복사를 해왔는데 그게 주소값인거임. 그래서 결국 얕은 복사가됨.
그래서 string을 깊은 복사 할려면 memcpy말고 대입연산자 쓰기 

------------------------------------------------------------------------------------------------------------------------1

this-> (디스 포인터. 상수 포인터임.)
생성된 객체의 주소를 가지고있다. 원래 모든 맴버 함수 안에서 맴버 변수 쓸때 앞에 this->이거 생략되어있는거임 
Get_this(){return this}

delete c1.Get_this() 쌉가능. 
맴버 함수안에서 
delete this 이렇게 해도 쌉가능. 

Class* clone(){
return new Class(*this)	//이러면 자기를 복사하는거임. 
}


*/

#include "stdafx.h"

using namespace std;

class CTest1 {
	static int a;
};

class CTest2 {
private:
	static const int m_iData = 10;
};

class CTest3 {
private:
	static int m_iData;
	static void Display() { cout << "private static" << endl; }
};

class CTest4 {
private:
	int m_iData;
	static int m_iSrc;
public:
	static void Print() {
		//cout << m_iData << endl;	// ERROR
		cout << m_iSrc << endl;		// OK
	}
};

void Display(int a, int b) {
	cout << a << "," << b << endl;
}

int num = 10;
class CTest6 {
public:
	static const int* iptrA ;
	static const int i ;

	const int* const Func(const int* const param)const {
		// 와 const 5개도 붙일수있다 와 
		int* ptr = new int;
		return ptr;
	}

};

const int CTest6::i = 10;
const int* CTest6::iptrA = new int(5);

class CTest7 {
private:
	char* szName = nullptr;
public:
	CTest7() { szName = new char[10]; strcpy_s(szName, 10, "hello"); };
	~CTest7() { delete szName; }
	void Draw() { cout << szName << endl; }
};

void Print(CTest7 test) {
	test.Draw();
}


int main(){

	{
		CTest7 ct1;
		Print(ct1);
		//ct1.Draw();
	}
	/*
	{
		CTest1 t;
		cout << sizeof(t) << endl;	//static은 맴버로서 크기계산은 안된다. 
		cout << endl;
	}

	// 함수 포인터 잠깐 실행해봄 갑자기 생각나서 
	{
		void (*Displayptr)(int, int) = Display;

		Displayptr(3,4);
	}*/
}