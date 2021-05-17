#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <limits>

//Содержит перечисления, функции и процедуры необходимые для функционирования интерфейса

//Перечисление для вариантов ответа
enum class MENU {
	NO = 0,
	YES = 1
};

//Перечисление для типов заполнения
enum class INPUT_TYPE {
	MANUAL = 0,
	FILE = 1,
	RANDOM = 2
};

//Верхний и нижний предел случайных чисел
enum CONSTS_FOR_RANDOM {
	LOWER_BORDER = -100,
	UPPER_BORDER = 100
};

//Ввод с клавиатуры
template <typename ElementType>
ElementType GetInput(void) {
	ElementType input;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "Введены некорректные данные! Повторите ввод." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl;
	return input;
}

//Стартовая информация
void StartInformation(void);

//Запрос на проведение модульных тестов
MENU ModularTestsAsk(void);

//Выбор типа ввода
INPUT_TYPE InputAsk(void);

//Запрос на сохранение исходных данных в файл
MENU SaveInputAsk(void);

//Запрос на сохранение результата в файл
MENU OutputFileAsk(void);

//Запрос на перезапись существующего файла
MENU RewriteAsk(std::string path);

//Запрос на повторное выполнение программы
MENU RepeatAsk(void);

#endif // !MENU_H