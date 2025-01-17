/*
	복습: 구조체 포인터, c와 c++의 구조체 차이(맴버 함수라던가), 구조체 메모리 할당 방식

	자료형 바이트 외우기, 


*/

#include <iostream>

using namespace std;

//구조체
struct tagInfo {
	int x;
	int y;
};

// 공용체
union myUnion
{
	char varChar;
	int varInt;
	long varLong;
	float varFloat;
	double varDouble;
};

// 열거체



int main() {

	{
		tagInfo pos = { 10,20 };

		tagInfo* pos_ptr = &pos;

		cout << (*pos_ptr).x << endl;	// 값으로 접근해서 이렇게 가야 값에 접근 가능. 근데 불편함
		cout << pos_ptr->x << endl;	// 이렇게 ->로 접근 가능.
		// -> : 사용자 정의타입의 '주소값'을 통해 맴버에 접근하는 방법

		cout << (&pos)->x << endl;	

		// 구조체의 첫번째 맴버 변수가 있는 공간 == 해당 구조체의 주소(이름)
		// 즉, 이거 아래 두개는 같다.
		cout << &pos << endl;
		cout << &pos.x << endl;

		pos_ptr->x = 100;

		//근데 이게 배열과는 
	}

	//사용자 정의타입 = 구조체, 공용체, 열거채 (여기까지는 c시절) / (c++)에서 추가된거 class
	// 즉, c++에서는 구조체, 공용체, 열거체, class이렇게 4개임. 

	// [ 공용체 ] 
	// 공용체 : 공용체는 가장 큰 맴버변수의 크기만큼 할당받고, 그 할당받은걸 모든 맴버들이 같이 공유함.
	/* int2개가 맴버면, 4바이트 할당하고 두개의 int변수가 그 4바이트안에 다 들어감. 구조체라면 int2개가 맴버일경우 8바이트를 할당했을것이다.
	
	int, float 이렇게 맴버가 있으면 4바이트할당받음.
	
	uInfo.x = 200;
	uInfo.y = 3.14;
	cout << uInfo.x<<endl;이렇게 하면 이상한 값이 나온다.
	제일 마지막에 float를 넣었기 때문에 메모리도 float형태로 바뀜. 그래서 3이 아니라 부동소수점 3을 출력해버림

	cout << (&uInfo.x) << (&uInfo.y);	// 둘이 같은 주소 나옴. 메모리 공유하니까 

	공용체는 메모리가 부족하던 옛날시절에 나왔음. 지금은 많이는 안씀 
	옛날에는 4바이트 밖에 없던 시절.. 8바이트 타입이 필요하면 그 타입을 만들어써야했음.
	그때 공용체 안에 구조체를 넣어서, 구조체 안에 4바이트 맴버 2개를 넣어서!
	이렇게 해어 8바이트 타입을 만들어썼음.

	*/

	/* [ 열거체 ]
	열거체는 상수를 정의하는 문법

	열거체는 초기화 하지 않으면 맨 위에부터 0으로 시작해서 1씩 증가함

	*/
	
	//---------------------------------------------------------------------------------------------------------------------------------------
	/* [ 동적할당 ] 
	
	포인터 = heap메모리 사용
	heap메모리를 사용하려면 -> pointer를 사용해야만함
	*/
	{
		// c시절 malloc()
		int* p = (int*)malloc(4);

		// 댕글링 포인터 발생하지 않도록 항상 nullptr초기화해야함

		// calloc

		//free하기
	}
}


/*
숙제1
(heap메모리랑은 상관없는 과제)
text rpg




*/