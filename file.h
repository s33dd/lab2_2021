#ifndef FILE_H
#define FILE_H

#include "menu.h"
#include <filesystem>
#include <fstream>

//����� ��� ������ � �������. �������� � ���� ���� � ����� � ������, ������� ��������� ��� �����, ���������� � ����, ������ �� �����
class FileWork {
	std::string m_path;
public:
	//����������� ������ FileWork
	FileWork(std::string path);

	//�������� �� ����������� ����� ������
	bool NameForbidden();

	//����� ����� ����� � ����������� ������ �����
	std::string ChangeName();

	//��������� ����� �����
	//std::string GetName();

	//�������� �� ������������� �����
	bool FileExist();

	bool FileReadOnly();

	//������� ������� ���� ��� ��������
	bool SaveFileNormal();

	//���� ������� ������� �� �����
	int GetSize();
};
#endif // !FILE_H