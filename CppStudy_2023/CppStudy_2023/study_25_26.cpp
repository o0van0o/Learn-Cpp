/* [ C++ study with TCP school 25~27part]
topic : �迭�� ������

* �ּҰ� 
	�������� ù ���� �޸� �ּҷ�, ��� ������ ����� ���� �� 1byte�� �ش� ������ �ּҰ��� ������ �ִ�. 
	��, int�� 4����Ʈ��, ���� ù��° 1����Ʈ�� �ش� int �����Ǵ� ����� '�ּҰ�'�� �ǹ���


* �����Ͷ�
	�������� �ּҰ��� �����ϴ� ����

* ������ ������
	- * : ���� ������ 
		'������' �տ� ����
		'�����Ϳ� �����' �ּҰ��� ����� '��'�� ��ȯ
	- & : �ּ� ������ 
		'����' �տ� ����
		�ش� '����'�� �ּҰ��� ��ȯ

* ������ ������ ũ�� 
	�������� ũ��� �տ� ���̴� Ÿ�԰� �������. > ������ '�ּҰ�'�� �����ϴ� �ִϱ�

	���� ������ ���� ũ��� CPU�� ���� ������
		- ���� 32bit�� ������ ���� ũ�� = 4byte
		- ���� 64bit�� ������ ���� ũ�� = 8byte

* �����Ͱ��� ����
	- *,/ �� �ȵ�
	- +, - �� ����. -> �� �����Ͱ��� �Ÿ��� ��Ÿ����.
	- �����ͳ��� ����, �� ���� 

	int num;   > ���� �ּҰ��� 1�̶�� ���� 
	int* ptr = &num; > ptr�ȿ� 1�� ��. 
	ptr + 1 �� 5 ��� �ּҰ��� ����. ��? int�ϱ� 4byte�� �������°���. 
	�����Ϳ� ���ϰų� ���� ����� �ǹ��ϴ� ���� byteũ��� ������ ������ Ÿ�Կ� ���� ������ 
	��, 
		int arr[3];
		int* arr_ptr = arr;

		arr[1]�� �ּҰ��� arr_ptr + 4�� �ƴ϶� arr_ptr + 1�̴�. ���⼭ 1�� 4byte�� �ǹ��ؼ� [ arr_ptr�� ����� �ּ� + 4 ] �� �ּҰ��� ��ȯ��

	���� ) ���ϱ�, ����, ����, �� ���� 

* �迭�� ������
	- ���� ���� ����ϸ�, ���� ��ü ���� 

	- ��� �迭�� �̸��� �迭�� ���۵Ǵ� ù �ּҸ� �ǹ���. 
	int* arr[3] �̸� arr�� arr[0]�� �ּҰ��� �ǹ��Ѵ�. 
	arr + 4 == arr[1]�� �ּҰ�
	arr + 8 == arr[2]�� �ּҰ�

	�׷��ϱ� �ݴ�� *(arr+4) �� arr[1]�� �ּҰ��� ����� �����͸� �ǹ��Ѵ�. 
	�� *(arr+4) == arr[1] 

*/
#include <iostream>

using namespace std;

int main() {
	// [ ������ ���� ]
	{
		int num = 100;
		int* ptr = &num; // ������ ���� ����

		int* ptr2, ptr3; // ptr2�� int* , ptr3�� int�� �����
		int* ptr4, * ptr5; // �Ѵ� int*�� �����

		int test = 100;
		int* ptr6 = &test;
		int** ptr7 = &ptr6; // ���� ������ 
	}

	// [ �������� ũ�� ]
	{
		// �������� ũ��� �տ� ���̴� Ÿ�԰� �������. > ������ '�ּҰ�'�� �����ϴ� �ִϱ�

		/* ���� ������ ���� ũ��� CPU�� ���� ������
			- ���� 32bit�� ������ ���� ũ�� = 4byte
			- ���� 64bit�� ������ ���� ũ�� = 8byte
		*/
		int num = 1;
		int* ptr = &num;
		int** ptrr = &ptr;

		cout << "int size(byte): " << sizeof(num) << endl;
		cout << "pointer size(byte): " << sizeof(ptr) << endl; //8����Ʈ
		cout << "���� pointer size(byte): " << sizeof(ptrr) << endl;//8����Ʈ
		cout << endl;
	}

	// [ ������ ���� ] 
	{
		int i1 = 100;
		double d1 = 3.14;

		int* int_ptr = &i1;
		double* double_ptr = &d1;
		
		int** int_ptrr = &int_ptr;

		cout << "i1�� �ּҰ�: " << &i1 << endl;
		cout << "int_ptr�� ������ �ִ� �ּҰ� : " << int_ptr << endl;
		cout << "int_ptr�� ������ �ִ� �ּҰ��� ����� ��: " << *int_ptr << endl;
		cout << endl;
		cout << "d1�� �ּҰ�: " << &d1 << endl;
		cout << "double_ptr�� ������ �ִ� �ּҰ� : " << double_ptr << endl;
		cout << "double_ptr�� ������ �ִ� �ּҰ��� ����� ��: " << *double_ptr << endl;
		cout << endl;
		cout << "int_ptr�� �ּҰ�: " << &int_ptr << endl;
		cout << "int_ptrr�� ������ �ִ� �ּҰ� : " << int_ptrr << endl;
		cout << "int_ptrr�� ������ �ִ� �ּҰ��� ����� �� : " << *int_ptrr << endl;
		cout << "int_ptrr�� ������ �ִ� �ּҰ��� ����� �ּҰ��� ����� �� : " << **int_ptrr << endl;
	}

	// [ �����Ϳ� �迭 ]
	{
		cout << endl;
		
		int arr[] = { 10,20,30 };
		int* arr_ptr = arr;		// arr�� �̷��� ������ �迭�� ù ���� �ּҰ� �������.

		// �����͸� �̿��ؼ� �迭�� ��������ϱ�
		cout << "�迭 �׳� �̾ƺ��� �ּҰ� ���´�: " << arr+0 << ", " << arr + 1 << ", " << arr + 2 << endl;
		cout << "�迭�� �ּҰ��� ���ؼ� �迭 ����: " << *(arr + 0) << ", " << *(arr + 1) << ", " << *(arr + 2) << endl;
		cout << "�����͸� �̿��� �迭 ����: " << arr_ptr[0] << ", " << arr_ptr[1] << ", " << arr_ptr[2] << endl;
		cout << "�����͸� �̿��� �迭 ����: " << *(arr_ptr + 0) << ", " << *(arr_ptr + 1) << ", " << *(arr_ptr + 2) << endl;
		
		// ��! �迭�� ũ�⸦ �� �������� ũ���� �����ؼ� �ȵȴ�. 
		cout << "�迭 ũ�� : " << sizeof(arr) << endl;
		cout << "�����͸� �̿��� �迭 ũ�� ���..�� �ȵ�: " << sizeof(arr_ptr) << endl; // arr_ptr�� �������� ������ ������ �翬�� 8byte�� ���� 
		
	}
}