/*
부모 클래스에 가상함수를 만든다는거는, 사실 오버라이딩한 가상함수를 사용하지 부모클래스의 가상함수를 쓰는일이 많지 않다.
그러면 결국 부모 클래스의 가상함수는 프로토타입만 필요하고 내용은 없어도 되는것아닌가?
-> 일단 문제가 되는건아니다. 근데 이런 깡통함수를 계속만드는걸 방지하는 법이 있다.
	virtual void Func() = 0;	//이렇게 쓰는것. 이걸 [ 순수 가상함수 ] 라고 한다. 
	이건 오로지 오버라이딩을해서 쓸 수 있는 함수로, 선언부만 존재하고, 몸체가 불완전한 함수이다. 
	순수 가상함수가 있는 부모를 상속받은 자식은, 무조건 순수 가상함수를 오버라이딩 해야만한다. 
	안하면 "추상 클래스를 인스턴스화 할 수 없습니다"라는 에러가 나는데, (인스턴스란 메모리에 실제적으로 등록된 상태를 말함)
	여기서 추상클래스란 순수 가상함수가 한개로 있는 클래스를 추상 클래스라고 한다. 
	(추상 클래스는 그 클래스 자체만으로 존재할 수 없다. 객체 생성이 불가능함. 추상클래스는 인스턴스화 할 수 없기 때문에) 

	추상 클래스는 객체 생성이 불가능하다. 왜?
	순수 가상함수는 실질적으로 바이너리화를할때, 컴파일러한테 이런 프로토타입의 함수가 있어~라고 알려주는 것 까지만한다. 
	그래서 몸체도 없는 상태로 순수 가상함수를 호출하려고하면 이어줄 몸체가 없어서 에러가 나는 것이다. 
	순수 가상함수는 오버라이딩한 함수가 무조건 존재해야만한다.
	
	이때, 추상 클래스를 상속받은 모든 자식클래스는 무조건 다 오버라이딩해야함!! 
	A추상 클래스를 B,C가 상속받았으면, B,C는 각각 A의 순수가상함수를 오버라이딩하고있어아햠. => 그러니까 모든 자식이 다 해당 함수를 오버라이딩해야한다면 부모에 순수가상함수를 써도 되는데, 그게 아니면 그냥 깡통함수 써야함.
																							안그러면 해당 함수를 오버라이딩할필요도없는 모든 자식새끼들이 그걸 쓸데없이 다 오버라이딩해야함. 																		

- 앞으로 상속 구조를 만들면, 부모 객체를 직접 생성하는 일은 거의 없음. 


- 오버라이딩 한 함수 뒤에 override; 이렇게 붙여도 문제 없음. (걍 표기법임.)

- 상속받을때 protected로 받으면 형변환 허락안함 Parent* p = new child 이거 안됨. 
  private이랑 protected 둘다 그런지 확인해봐 public은 확실히 형변환 허락하는거 알고. 


- 객체를 동적할당이 아니라 정적할당으로 선언해도, 그 객체를 통해 가상함수를 호출하면 동적바인딩이래.. 정적바인딩인줄..
  어쨌든 가상테이블에서 가져오는거라 그런거같음. 
  ---------------------------------------------------------------------------------
 - 버추얼 소멸자 그거 배움.  
	상속구조만들면 부모 소멸자에 virtual 왠만해서 꼭 붙이기!!! 
=========================================================================================  ---------------------------------------------------------------------------------
다형성 문법 2_ 캐스팅
Parent* p = new Child
((Child*)p)->childFunc();	// 이렇게 클래스도 타입캐스팅 가능함.
보편적으로
공통적으로, 누구나 사용할법한 함수는 오버라이딩으로 사용하고 
개별적인 기능들(player만 가지고있는 기능)을 사용하고자 할때는 캐스팅으로 통해서 접근을한다.

오버라이딩, 캐스팅 모두 다형성을 위해 쓰는 문법이지 둘다 효율적인건 아니다. 
컴파일러 입장에서는 캐스팅도 어쨌든 변환을 하는 시간이 들고, 안정성 측면에서는 떨어진다.

다운캐스팅 : 부모를 자식으로 형변환하는것
업캐스팅: 자식을 부모로 형변환하는것

Parent* p = new Child1;
((Child2*)p)->child2Func();	// 이래도.. ㅋㅋㅋㅋ 가능하다!! ㅋㅋㅋㅋ
근데 이게 말도안되고 객체라는 개념을 파괴하는 행위이기 때문에 이런 비논리적인 형변환은 하지 않는다. (우리가 알아서 안해야함!)
이게 왜 되냐.. 포인터라..주소만 있으면 사실 뭐든 가능하긴함. 
어쨌든 이런 "비논린적인 형변환"은 c시절에 막지 못했다. 그래서 c++에서는 논리적인 형변환만하기 위해 [캐스팅 연산자]를 제공한다

[ 캐스팅 연산자 ]
- 다이나믹 캐스트 : rtti=런타임 타입 아이텐티피케이션	
					typeid, typeinfo
캐스팅 연산자 4가지
- static_cast
		- 논리적인 형변환 수행하는 연산자
		- c스타일의 캐스트와 같은 역할
		- 컴파일 시점에 수행해서, 정석 캐스팅이라고도 부름
		int iNum = (int)2.1f;	// 이게 c언어 시절 캐스팅
		int iNum = static_cast<int>(2.1f);	//이게 static_cast사용하는 방법. bitset이랑 쓰는법 비슷하지
		- C랑 다른게 있다면, 이건 논리적인 형변환은 허용하지 않음. 
		  Child* ch = new Child;
		  Parent* p = (Parent*)ch;	// 이런거 c는 허용하는데 static_cast는 허용안함
		  근데 업케스팅은 안되는데, 다운케스팅은 허용함. => 이거 아닌듯?! 둘다 됨. 
		  어쨌든 다운케스팅도 상속관계에서만 형변환을 허용한다. ( 다운이면 당연히 상속이겠지만)

		- 위험성: 자식 객체 포인터가 부모 객체ㄹ 포인터를 받는 것이 논리적이라 할지라도 실제 안전한 캐스팅인지는 알수가없다. 
			static_cast는 컴파일 시점에ㅅ 캐스팅을 하기 때문에 런타임 시점에 위험한 변환을 했는지 알 수가 없다. 
			얘의 논리적이다 비논리적인지의 기준은 "상속을 했냐 안했냐" 인것이지 인간 입장에서의 논리 비논리, 안전 불안전이 아님. 
- dynamic_cast
		- 동적인 타이밍에 캐스팅 수행하여 다형성의 문법을 사용할 수 있게 해줌. 
		- 조건
			1. 일반 자료형이나 일반 포인터를 대상으로는 동작하지 않는다. 
			2. 클래스의 상속 상태의 포인터일 때ㅁ 동작하며, 다운 캐스팅(다형성)을 하기 위한 용도로 쓴다. 
			3. 반드시 부모 클래스에 가상 함수가 한 개 이상 있어야 사용 가능하다. => 이거 만족안되면 에러나면서 "다형 형식이 아닙니다" 이렇게 나옴. 
					소멸자에만 버추얼 있어도 괜찮음. 뭐가 되었든 가상화가 일어나면 가능. 오버라이딩안해도 괜찮은가? 이거 확인하기 아마 될듯 

		- 이게 그래서 안전한 캐스팅인가?
			안전하지 않은 캐스팅이라고 판단하면 nullptr을 반환함.
			Parent* p = new Parent
			Child* ch = dynamic_cast<Child*>p;		
			ch == nullptr이 들어감. 
			이 안정성 테스트를 런타임에 바로 확인해서 ㅇ안전하지 않으면 nullptr을 반환하는거임. 

		- 언제쓸까?
			다운케스팅을 하기위해 쓴다. 
			오버라이딩하지 않고, 자식 함수에 접근하려고 할때 이걸 쓴다. 
			스테틱도 쓰긴 하는데 둘이 장단점이 있다. 
			스테틱은 다이나믹보다는 좀 덜 안전한데
			컴파일 타임에 다 결정하니까 다이나믹보다는 빠름 ( 전반적으로 정적인 모든 것들이 동적인 것보다는 빠름)
			다이나믹 장점은 - 안전하다. 
			다이나믹 단점은 - 런타임에 안정성을 확인하니까 속도가 느림

			근데 여튼 보통은 다이나믹 씀. 그래도 안전한게 더 좋은 경우가 많이 때문에. 
			그래서 보통 다이나믹쓰고 문제 없으면 그걸 static으로 바꾸는 경우가 많음. (속도를 위해)

		- 업캐스팅도 허용함. 
			어쨌든 상속이니까. 
			업케스팅은 다이나믹이건 스테틱이건 모두다 허용해버린다. 업캐스팅할거면 static이건 다이나믹이건 똑같다. 
			ㅈㅇ요한건 다운케스팅할때 뭘쓰냐. 

		* 사실 원래 캐스팅 자체가 불안전한 문법이다. 그래도 그게 필요하니까 쓰는거임.. 그니까 무슨 케스팅이 더 안전하니 물어보면
		일단 모든 캐스팅이 다 불안정하지만, 다형성때문에 꼭 사용해야만 한다면 상대적으로 다이나믹이 더 안전합니다.. 라고 말하는게 맞다. 

- const_cast
- reinterpret_cast

- 자식새끼가 오버라이딩안했는데, 부모 포인터에 자식 객체를 new로 동적할당하면
  동적바인딩이일어나는데, 가상함수를 호출하면 자식께 아니라 부모꺼가 나옴. 자식이 오버라이딩안했으니까
  어쨌든 동적바인딩임 

*/


/* 과제
* 배운거 다 써서
상점 만들고, 아이템 보여주기 (초급상점, 중급상점, 고급상점) 
보여주기까지만 만들기 

*/

#include "stdafx.h"

using namespace std;

class CParent {
public:
	void Dispaly() { cout << "Parent" << endl; }
};

class CParent_withVirtual {
public:
	virtual ~CParent_withVirtual() {}
};

class CChild: public CParent {
public:
	void Dispaly() { cout << "Child" << endl; }
};

class CChild2 : public CParent_withVirtual {
public:
	void Dispaly() { cout << "Child" << endl; }
};

class CTest {
public:
	void Dispaly() { cout << "Test" << endl; }
};

int main() {

	// C타입 cast 가능한 것들
	{
		/* 1. 포인터 이외의 타입 - 포인터 이외의 타입끼리 변경 가능 
			  그러나 객체 타입은 불가능 */
			int iData = 10;
			float fData = (float)iData;

			float fData2 = 10.f;
			int iData2 = (int)fData2;

			CParent p;
			//CChild ch = (CChild)p;	// ERROR 객체 타입 - 객체 타입간의 변경 불가능. 


		/* 2.포인터 타입- 포인터 타입 캐스팅 가능 (제약없음)*/
			int iData3 = 10;
			float* fData3 = (float*)&iData3;// 일반 포인터 - 일반 포인터

			float fData4 = 10.f;
			int* iData4 = (int*)&fData4;	// 일반 포인터 - 일반 포인터

			CTest t;
			int* iData5 = (int*)&t;			// 객체 포인터 - 일반 포인터 

			int iData6 = 10;
			CTest* t2 = (CTest*)&iData6;	// 일반 포인터 - 객체 포인터 

			CParent p1;
			CTest* t3 = (CTest*)&p1;			// 비상속관계

			CParent p2;
			CChild* ch2 = (CChild*)&p2;		// 상속관계 down cast

			CChild ch3;	
			CParent* p3 = (CParent*)&ch3;	// 상속관계 up cast

		/* 3. 포인터 타입 - 포인터 이외의 타입  (제약없음)*/
			int iData7 = 10;
			float* fData7 = (float*)iData7;

			float* fData8 = new float(10.f);
			int iData8 = (int)fData8;

			float* fData9 = new float(10.f);
			int iData9 = (int)*fData9;

			int i = 10;
			CTest* t4 = (CTest*)i;

			CTest t5;
			//CParent* p4 = (CParent*)t5;	//ERROR

			// 그냥 별게 다됨....
	}

	// static cast 가능한 것들 
	{
		/* 1. 포인터 이외의 타입 - 포인터 이외의 타입끼리 변경 가능
			  그러나 객체 타입은 불가능 */
		int iData = 10;
		float fData = static_cast<int>(iData);

		CParent p;
		//CChild ch = static_cast<CChild>(p);	// ERROR 객체 타입 - 객체 타입간의 변경 불가능. 

	/* 2. 포인터 타입은 "상속관계" 객체간의 포인터 끼리만 가능.
		  그 외의 포인터 타입- 포인터타입 간의 변경 불가능*/

		int iData1 = 10;
		//float* f = static_cast<int*>(&iData1);	// ERROR 포인터-포인터 변경 불가능

		CParent p1;
		//CTest* t = static_cast<CTest*>(&p1);	// ERROR 포인터-포인터 변경 불가능

		CParent p2;
		CChild* ch = static_cast<CChild*>(&p2);	// down cast

		CChild ch2;
		CParent* p3 = static_cast<CParent*>(&ch2);// up cast

		/* 3. 포인터 타입 - 포인터 이외의 타입 (아예 불가능)
			  애초에 포인터 타입 - 포인터 타입간의 변경이 객체아니면 다 안되기 때문*/
		int iData2 = 10;
		//float* fData6 = static_cast<float*>(iData2); // ERROR 일반->포인터 안됨

		CTest* t = new CTest;
		//CParent p = static_cast<CParent>(*t);		// ERROR 포인터->일반 안됨
	}

	// dynamic cast 가능한 것들 
	{
		/* 1. 포인터 이외의 타입 - 포인터 이외의 타입 => 아예 불가능 */
		int iData = 10;
		//float fData = dynamic_cast<int>(fData);	//ERROR

		CParent p;
		//CChild ch = static_cast<CChild>(p);	// ERROR 객체 타입 - 객체 타입간의 변경 불가능. 

	/* 2. 포인터 타입은 "상속관계" 객체간의 포인터 끼리만 가능.
		  그 외의 포인터 타입- 포인터타입 간의 변경 불가능*/

		int iData1 = 10;
		//float* f = dynamic_cast<int*>(&iData1);	// ERROR 포인터-포인터 변경 불가능

		CParent p1;
		//CTest* t = dynamic_cast<CTest*>(&p1);	// ERROR 포인터-포인터 변경 불가능

		CParent_withVirtual p2;
		CChild2* ch = dynamic_cast<CChild2*>(&p2);	// down cast

		CChild2 ch2;
		CParent_withVirtual* p3 = dynamic_cast<CParent_withVirtual*>(&ch2);// up cast

		/* 3. 포인터 타입 - 포인터 이외의 타입 => 아예 불가능
			  애초에 포인터 이외의 타입은 절대 불가능하다.*/
		int iData2 = 10;
		//float* fData6 = static_cast<float*>(iData2); // ERROR 일반->포인터 안됨

		CTest* t = new CTest;
		//CParent_withVirtual p = dynamic_cast<CParent_withVirtual>(*t);		// ERROR 포인터->일반 안됨
	}

	

	
}