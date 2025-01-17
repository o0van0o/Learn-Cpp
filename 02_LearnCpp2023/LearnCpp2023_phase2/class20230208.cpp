/*
[과제 피드백]--------------------------------------------------------------------------------------------

* class안에 함수 이름짓기는 보통 이렇게 짓는다. 
	* Initialize() : 생성자가 아닌! 인스턴스 생성 후에 초기화 하고싶을때 만드는 함수의 이름
	* Update(): 매 프레임마다 업데이트
	* Release(): 동적할당 메모리를 풀어주는 함수 

* Define.h 헤더파일
	이 이름의 헤더파일은 사용자 정의 헤더 파일로, 보통 사용자 정의 타입(struct), 메크로 등을 모아놓은 헤더파일로많이 쓴다. 
	물론, 나중에 가면 이것도 기능별로 연관별로 나눠서 함. 

* 동적 변수나 배열을 해제할 때, 메크로 함수를 쓰기도 한다. (보통 많이 씀) 
	#define SAFE_DELETE(p) {delete p; p = nullptr;}	
	#define SAFE_DELETE_ARRAT(p) {delete[] p; p=nullptr;}

* 앞으로 점점 코드를 짤 때 함부로 접근할 수 없도록 폐쇠적으로 만들것이다. 유지보수를 위해 
  정해져있는 루틴을 만들것이란 소리. (객체를 생성하려면 이렇게 해야하고, 해제하려면 이렇게 해야하고 등) 

* 기존 배열 복사 > memcpy()함수 사용해서 해보기! 
* 참고로 memcpy()는 string 타입에서는 원하는대로 동작하지 않을거임.
	- string은 <string>를 포함시켜야함. <string>과 <string.h>는 다르다. <string.h>는 c언어 시절, <string>은 c++에서 등장
	- string은 STL 탬플릿이다. 
	- 참고로 string str = "hello"라고 했을 때, str은 hello가 아니라 'h'의 주소값을 가지고 있다. 마치 문자열 포인터 마냥. 
	  그래서 string을 파일에 읽기쓰기 해버리면 "hello"가 아니라 주소값을 써버리면서 다시 읽어왔을때 "hello"로 복구할수없다.

[수업진도~!]--------------------------------------------------------------------------------------------
* 생성자 *
* 객체 생성과정 : 1.메모리할당 2.생성자 호출 => 이거 둘중에 하나라도 성립 안하면 그건 객체생성이 아님! 
* 생성자 필요한이유 (반드시 필요함)
	1. 객체 생성을 하기 위함
	2. 맴버 변수 초기화 하기 위함. 

* 생성자는 여러개 존재 가능 (생성자 오버로딩 가능) 

* 구조체도 객체다. 왜냐, 똑같이 메모리가 할당되고나서 생성자가 호출되거든. 구조체도 생성자가있다!!

* class의 자료형은 몇바이트일까
	아무 맴버도 없으면 1 바이트(이거 struct랑 똑같음)
	short하나를 가지고있으면 2바이트
	함수를 넣으면? > 2바이트. 메모리크기 정의할때는 함수는 뺌.
	short, int이렇게 두개면 -> 8바이트 ( struct랑 똑같음!) 

	class의 바이트는 struct랑 거의 똑같은데 할당 방식이 블록단위데이터는 아니다. 
	이건 중괄호 초기화(유니폼초기화같은거) 안되잖아 => 이 말이 즉 블록단위데이터로 할당되는건 아니라는 것이다. 
	물론 클래스 바이트 크기 계산은 엄청 신경쓸문제는 아니다. 

* 소멸자 *
* 객체 소멸과정:1. 소멸자 호출 2. 메모리 반환
* 소멸자는 오버로딩 안됨. (하나만 존재가능) 

*/

#include "stdafx.h"

using namespace std;

struct tagText {
	string str;
	tagText();	// 이렇게 하면 구조체 생성자인것임
};

class cTest {
private:
	int m_iData;
	int m_iSrc;
public:
	cTest();
	cTest(int _iData);
};

// 생성자 1. 
cTest::cTest() {
	m_iData = 10;	// [대입을 통한 초기화] => 엄연히 말하면 이것도 할당과 동시에 초기화는 아님. 이미 우리가 m_iData라고 쓴거 자체가 메모리는 잡혔다는거임.
					//그래도 초기화라고 말하는건, 어쨌든 표면적으로 인스턴스 객체는 생성자가 끝난후에 인스턴스로서의 사용이 가능함.
					// 할당과 동시에 초기화는 초기화 리스트 사용해야함. 
}

//생성자 2.
cTest::cTest(int _iData) {
	m_iData = _iData;
}

int main() {
	{
	cTest cT1; // 이건 객체를 생성한게 맞다.
	cTest* cT2 = new cTest; //이것도 생성한게 맞다. heap에 생성한것. // new는 기본적으로 생성자 호출하는 것까지 동작을 포함시키기 때문에 이건 동적할당만 한게아니라 생성한거임!
	cTest* cT3 = (cTest*)malloc(sizeof(cTest));/* 이건 객체를 생성한게 아니다.malloc은 생성자를 호출하지 않음.이건 걍 4바이트짜리 공간을 할당한것뿐이다.
												  그래서 객체는 무조건 new, delete 만 써야함. */
	}

	{
		cTest t1(10);
		cTest* t2 = new cTest(10);
	}
}

/*
과제
class활용한 text rpg
*/