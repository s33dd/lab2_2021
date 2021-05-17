#ifndef ARRAY_H
#define ARRAY_H
#define ZERO_INDEX 0
#define NO_ELEMENT -1

#include "file.h"
#include <ctime>

//����� Array ��� ������ � ��������. �������� � ���� ��������� �� ������ ������� ������� � ������ �������,
//������ ��� ����� �������, ���������� �������, ������ ������� � ��������� ������ �������� � �������
class Array {
	int m_arraySize;
	int *m_array;
	int m_sought;

public:
	//����������� ������. ������� ��������� ������ �������
	Array(int size);

	//���������� ������
	~Array();

	//������� ���������� �������. ������� ��������� ������ ������� �������� � ������ �������
	void ArraySort(int firstIndex, int size);
	
	//������������ �������� ������� �������� � ����������. ������� ��������� ������ ��������
	void ArrayManualInput(int index);

	//���������� ������� ���������� �������. ������� ��������� ������ �������
	void ArrayRandomInput(int size);

	//����������� ������� �� �����. ������� ��������� ��� �����
	bool ArrayFileInput(std::string);

	//���������� �������� ������ � ����. ������� ��������� ��� �����
	void ArraySaveInput(std::string path);

	//���������� ���������� ������ � ����. ������� ��������� ��� �����
	void ArraySaveOutput(std::string path);

	// ����� �������. ������� ��������� ������ �������
	void ArrayOutput(int size);

	//�������� �����. ������� ��������� ������ �������, ���������� ����������� �� ������� ������ �������� ��������, ���� -1
	int BinarySearch(int size);

	//���������� ��������� [] ��� �������� ������ m_array
	int operator[](int index);
	
	//���� � ����������� �������� �����
	int SoughtInput();

	//����������� �������� �����
	int GetSought();
	
	//������� ��� ������

	void First();

	void Second();

	void Third();

	void Fourth();

	void Fifth();
};

//�������� ������������ ��������� ������� �������. ������� ��������� ������ ������� 
bool SizeNormal(int size);
#endif // !ARRAY_H