#ifndef FILE_H
#define FILE_H

#include "menu.h"
#include <filesystem>
#include <fstream>

//Класс для работы с файлами. Содержит в себе путь к файлу и методы, которые проверяют имя файла, записывают в файл, читают из файла
class FileWork {
	std::string m_path;
public:
	//Конструктор класса FileWork
	FileWork(std::string path);

	//Проверка на запрещённые имена файлов
	bool NameForbidden();

	//Смена имени файла и возвращение нового имени
	std::string ChangeName();

	//Получение имени файла
	//std::string GetName();

	//Проверка на существование файла
	bool FileExist();

	bool FileReadOnly();

	//Попытка создать файл для проверки
	bool SaveFileNormal();

	//Ввод размера массива из файла
	int GetSize();
};
#endif // !FILE_H