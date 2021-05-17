#include "tests.h"

bool FirstTest() {
	Array test(5);
	test.First();
	test.ArraySort(ZERO_INDEX, 5);
	int testAnswer = test.BinarySearch(5);
	int rightAnswer = 1;
	if ( testAnswer != rightAnswer) {
		std::cout << "Ошибка в выполнении первого теста! Исходные данные: " << std::endl;
		test.ArrayOutput(5);
		std::cout << "Искомое число: " << 0 << std::endl;
		std::cout << "Ожидаемый ответ: " << rightAnswer << std::endl;
		std::cout << "Полученный ответ: " << testAnswer << std::endl;
		std::cout << std::endl;
		return false;
	}
	else {
		return true;
	}
}

bool SecondTest() {
	Array test(7);
	test.Second();
	test.ArraySort(ZERO_INDEX, 7);
	int testAnswer = test.BinarySearch(7);
	int rightAnswer = 1;
	if (testAnswer != rightAnswer) {
		std::cout << "Ошибка в выполнении второго теста! Исходные данные: " << std::endl;
		test.ArrayOutput(7);
		std::cout << "Искомое число: " << -14 << std::endl;
		std::cout << "Ожидаемый ответ: " << rightAnswer << std::endl;
		std::cout << "Полученный ответ: " << testAnswer << std::endl;
		std::cout << std::endl;
		return false;
	}
	else {
		return true;
	}
}

bool ThirdTest() {
	Array test(3);
	test.Third();
	test.ArraySort(ZERO_INDEX, 3);
	int testAnswer = test.BinarySearch(3);
	int rightAnswer = NO_ELEMENT;
	if (testAnswer != rightAnswer) {
		std::cout << "Ошибка в выполнении третьего теста! Исходные данные: " << std::endl;
		test.ArrayOutput(3);
		std::cout << "Искомое число: " << 1 << std::endl;
		std::cout << "Ожидаемый ответ: " << "Отсутствие элемента" << std::endl;
		std::cout << "Полученный ответ: " << testAnswer << std::endl;
		std::cout << std::endl;
		return false;
	}
	else {
		return true;
	}
}

bool FourthTest() {
	Array test(6);
	test.Fourth();
	test.ArraySort(ZERO_INDEX, 6);
	int testAnswer = test.BinarySearch(6);
	int rightAnswer = 3;
	if (testAnswer != rightAnswer) {
		std::cout << "Ошибка в выполнении четвёртого теста! Исходные данные: " << std::endl;
		test.ArrayOutput(6);
		std::cout << "Искомое число: " << -11 << std::endl;
		std::cout << "Ожидаемый ответ: " << rightAnswer << std::endl;
		std::cout << "Полученный ответ: " << testAnswer << std::endl;
		std::cout << std::endl;
		return false;
	}
	else {
		return true;
	}
}

bool FifthTest() {
	Array test(7);
	test.Fifth();
	test.ArraySort(ZERO_INDEX, 7);
	int testAnswer = test.BinarySearch(7);
	int rightAnswer = 2;
	if (testAnswer != rightAnswer) {
		std::cout << "Ошибка в выполнении пятого теста! Исходные данные: " << std::endl;
		test.ArrayOutput(7);
		std::cout << "Искомое число: " << 0 << std::endl;
		std::cout << "Ожидаемый ответ: " << rightAnswer << std::endl;
		std::cout << "Полученный ответ: " << testAnswer << std::endl;
		std::cout << std::endl;
		return false;
	}
	else {
		return true;
	}
}

void MakeTests() {
	int testsPassed = 0;
	if (FirstTest() == true) {
		testsPassed++;
	};
	if (SecondTest() == true) {
		testsPassed++;
	};
	if (ThirdTest() == true) {
		testsPassed++;
	};
	if (FourthTest() == true) {
		testsPassed++;
	};
	if (FifthTest() == true) {
		testsPassed++;
	};
	if (testsPassed == 5) {
		std::cout << "Тестирование прошло успешно!" << std::endl << std::endl;
	}
}