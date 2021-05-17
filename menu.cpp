#include "file.h"

void StartInformation(void) {
	std::cout << "________________________" << std::endl;
	std::cout << "Лабораторная работа по программированию №2" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "Вариант 5" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "Напишите программу двоичного поиска заданного значения в упорядоченном массиве." << std::endl;
	std::cout << "Программа должна возвращать индекс искомого элемента в массиве или информировать об отсутствии искомого элемента в массиве." << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "Выполнил студент 403 группы ";
	std::cout << "Суховериков Денис Дмитриевич.  2021 год" << std::endl;
	std::cout << "________________________" << std::endl << std::endl;
}

bool RightMenuChoice(MENU choice) {
		if ((choice == MENU::NO) || (choice == MENU::YES)) {
			return true;
		}
		else {
			std::cout << "Используйте указанные варианты!" << std::endl;
			return false;
		}
}

bool RightInputChoice(INPUT_TYPE choice) {
	if ((choice == INPUT_TYPE::RANDOM) || (choice == INPUT_TYPE::MANUAL) || (choice == INPUT_TYPE::FILE)) {
		return true;
	}
	else {
		std::cout << "Используйте указанные варианты!" << std::endl;
		return false;
	}
}

MENU ModularTestsAsk(void) {
	std::cout << "Желаете выполнить модульные тесты?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
	MENU decision = (MENU)GetInput<int>();
	while (!RightMenuChoice(decision)) {
		decision = (MENU)GetInput<int>();
	}
	return decision;
}

INPUT_TYPE InputAsk(void) {
	std::cout << "Как вы желаете заполнить массив?" << std::endl;
	std::cout << "2 — Случайными числами / 1 — Из файла / 0 — С клавиатуры" << std::endl;
	std::cout << "Ваш выбор: ";
	INPUT_TYPE decision = (INPUT_TYPE)GetInput<int>();
	while (!RightInputChoice(decision)) {
		decision = (INPUT_TYPE)GetInput<int>();
	}
	return decision;
}

MENU SaveInputAsk(void) {
	std::cout << "Желаете сохранить исходные данные в файл?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
	MENU decision = (MENU)GetInput<int>();
	while (!RightMenuChoice(decision)) {
		decision = (MENU)GetInput<int>();
	}
	return decision;
}

MENU OutputFileAsk(void) {
	std::cout << "Желаете сохранить результат в файл?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
	MENU decision = (MENU)GetInput<int>();
	while (!RightMenuChoice(decision)) {
		decision = (MENU)GetInput<int>();
	}
	return decision;
}

MENU RewriteAsk(std::string path) {
	std::ifstream checkFile;
	checkFile.open(path);
	MENU decision = MENU::NO;
	if (checkFile.is_open()) {
		std::cout << "Файл с таким именем уже существует!" << std::endl;
		std::cout << "Что вы желаете сделать с файлом?" << std::endl;
		std::cout << "1 — Создать новый / 0 — Перезаписать существующий" << std::endl;
		std::cout << "Ваш выбор: ";
		decision = (MENU)GetInput<int>();
		while (!RightMenuChoice(decision)) {
			decision = (MENU)GetInput<int>();
		}
		checkFile.close();
		return decision;
	}
	else {
		checkFile.close();
		return decision;
	}
}

MENU RepeatAsk(void) {
	std::cout << "Желаете ли вы повторно выполнить программу?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
	MENU decision = (MENU)GetInput<int>();
	while (!RightMenuChoice(decision)) {
		decision = (MENU)GetInput<int>();
	}
	return decision;
}