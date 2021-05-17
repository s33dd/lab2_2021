#ifndef ARRAY_H
#define ARRAY_H
#define ZERO_INDEX 0
#define NO_ELEMENT -1

#include "file.h"
#include <ctime>

//Класс Array для работы с массивом. Содержит в себе указатель на первый элемент массива и размер массива,
//Методы для ввода массива, сортировки массива, вывода массива и двоичного поиска элемента в массиве
class Array {
	int m_arraySize;
	int *m_array;
	int m_sought;

public:
	//Конструктор класса. Функция принимает размер массива
	Array(int size);

	//Деструктор класса
	~Array();

	//Быстрая сортировка массива. Функция принимает индекс первого элемента и размер массива
	void ArraySort(int firstIndex, int size);
	
	//Присваивание элементу массива значения с клавиатуры. Функция принимает индекс элемента
	void ArrayManualInput(int index);

	//Заполнение массива случайными числами. Функция принимает размер массива
	void ArrayRandomInput(int size);

	//Заполонение массива из файла. Функция принимает имя файла
	bool ArrayFileInput(std::string);

	//Сохранение исходных данных в файл. Функция принимает имя файла
	void ArraySaveInput(std::string path);

	//Сохранение результата работы в файл. Функция принимает имя файла
	void ArraySaveOutput(std::string path);

	// Вывод массива. Функция принимает размер массива
	void ArrayOutput(int size);

	//Двоичный поиск. Функция принимает размер массива, возвращает увеличенный на единицу индекс искомого элемента, либо -1
	int BinarySearch(int size);

	//Перегрузка оператора [] для массивов класса m_array
	int operator[](int index);
	
	//Ввод и возвращение искомого числа
	int SoughtInput();

	//Возвращение искомого числа
	int GetSought();
	
	//Функции для тестов

	void First();

	void Second();

	void Third();

	void Fourth();

	void Fifth();
};

//Проверка корректности введённого размера массива. Функция принимает размер массива 
bool SizeNormal(int size);
#endif // !ARRAY_H