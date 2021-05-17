#include "tests.h"
#include <Windows.h>

int main(void) {
	setlocale(LC_ALL, "Russian");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);
	WORD standart = csbi.wAttributes;

	MENU wantTests = MENU::YES;
	MENU wantContinue = MENU::YES;
	MENU wantSave = MENU::YES;
	MENU wantRewrite = MENU::YES;
	INPUT_TYPE inputType = INPUT_TYPE::RANDOM;
	bool dataReaded = false;

	do {
		StartInformation();

		std::string filePath = "nothing";
		int arraySize = 0;
		int find = 0;

		wantTests = ModularTestsAsk();
		if (wantTests == MENU::YES) {
			MakeTests();
		}

		//Запрос типа заполнения массива
		inputType = (INPUT_TYPE)InputAsk();

		//Получение размера массива из файла
		if (inputType == INPUT_TYPE::FILE) {
			std::cout << "Введите имя файла: " << std::endl;
			filePath = GetInput<std::string>();
			FileWork tempFile(filePath);
			while(tempFile.NameForbidden()) {
				std::cout << "Введите новое имя файла:" << std::endl;
				filePath = tempFile.ChangeName();
			}
			arraySize = tempFile.GetSize();
			while (!SizeNormal(arraySize)) {
				std::cout << "Проверьте содержимое файла!" << std::endl;
				std::cout << "Введите имя файла: " << std::endl;
				filePath = tempFile.ChangeName();
				arraySize = tempFile.GetSize();
			}
		}
		else {
			std::cout << "Введите размер массива: " << std::endl;
			std::cout << "При вводе дробного числа будет взята только его целая часть." << std::endl;
			arraySize = GetInput<int>();
			while (!SizeNormal(arraySize)) {
				std::cout << "Введите размер массива: " << std::endl;
				arraySize = GetInput<int>();
			}
		}

		FileWork file(filePath);
		Array array(arraySize);

		//Осуществление заполнения
		if (inputType == INPUT_TYPE::RANDOM) {
			array.ArrayRandomInput(arraySize); //Заполнение случайными
		}
		else {
			if (inputType == INPUT_TYPE::FILE) {
				dataReaded = array.ArrayFileInput(filePath);
				while (!dataReaded) {
					std::cout << "Введите новое имя файла:" << std::endl;
					filePath = file.ChangeName();
					dataReaded = array.ArrayFileInput(filePath);
				}; //Заполнение из файла
			}
			else {
				for (int i = 0; i < arraySize; i++) {
					array.ArrayManualInput(i); //Заполнение вручную
				}
			}
		}

		//array.ArrayOutput(arraySize); //Вывод не отсортированного массива
		array.ArraySort(ZERO_INDEX, arraySize); //Сортировка массива
		array.ArrayOutput(arraySize); //Вывод отсортированного массива

		//Ввод искомого числа
		find = array.SoughtInput();

		//Поиск числа в массиве и вывод ответа
		int findIndex = array.BinarySearch(arraySize);
		if (findIndex == NO_ELEMENT) {
			SetConsoleTextAttribute(consoleHandle, BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); //Изменение цвета вывода на фоновый красный, текст белый
			std::cout << "Элемента " << find << " в массиве нет.";
			SetConsoleTextAttribute(consoleHandle, standart); // Возвращение к стандартным цветам
			std::cout << std::endl;
		}
		else {
			SetConsoleTextAttribute(consoleHandle, BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); //Изменение цвета вывода на фоновый зелёный, текст белый
			std::cout << "Число " << find << " находится в массиве под номером " << findIndex;
			SetConsoleTextAttribute(consoleHandle, standart); // Возвращение к стандартным цветам
			std::cout << std::endl;
		}

		//Запрос на сохранение исходных данных и само сохранение
		if (inputType != INPUT_TYPE::FILE) {
			wantSave = SaveInputAsk();
			if (wantSave == MENU::YES) {
				std::cout << "Введите имя файла:" << std::endl;
				filePath = GetInput<std::string>();
				FileWork inputSaveFile(filePath);
				while (!inputSaveFile.SaveFileNormal()) {
					std::cout << "Введите новое имя файла:" << std::endl;
					filePath = inputSaveFile.ChangeName();
				}
				wantRewrite = RewriteAsk(filePath);
				if (wantRewrite == MENU::YES) {
					std::string newFilePath = filePath;
					FileWork newInputSave(newFilePath);
					while (newFilePath == filePath) {
						std::cout << "Введите новое имя файла:" << std::endl;
						newFilePath = newInputSave.ChangeName();
						while (!newInputSave.SaveFileNormal()) {
							std::cout << "Введите новое имя файла:" << std::endl;
							newFilePath = newInputSave.ChangeName();
						}
					}
					array.ArraySaveInput(newFilePath);
				}
				else {
					while (inputSaveFile.FileReadOnly()) {
						std::cout << "Введите новое имя файла:" << std::endl;
						filePath = inputSaveFile.ChangeName();
					}
					array.ArraySaveInput(filePath);
				}
			}
		}

		wantSave = OutputFileAsk();
		if (wantSave == MENU::YES) {
			std::cout << "Введите имя файла:" << std::endl;
			filePath = GetInput<std::string>();
			FileWork outputSaveFile(filePath);
			while (!outputSaveFile.SaveFileNormal()) {
				std::cout << "Введите новое имя файла:" << std::endl;
				filePath = outputSaveFile.ChangeName();
			}
			wantRewrite = RewriteAsk(filePath);
			if (wantRewrite == MENU::YES) {
				std::string newFilePath = filePath;
				FileWork newOutputSave(newFilePath);
				while (newFilePath == filePath) {
					std::cout << "Введите новое имя файла:" << std::endl;
					newFilePath = newOutputSave.ChangeName();
					while (!newOutputSave.SaveFileNormal()) {
						std::cout << "Введите новое имя файла:" << std::endl;
						newFilePath = newOutputSave.ChangeName();
					}
				}
				array.ArraySaveOutput(newFilePath);
			}
			else {
				while (outputSaveFile.FileReadOnly()) {
					std::cout << "Введите новое имя файла:" << std::endl;
					filePath = outputSaveFile.ChangeName();
				}
				array.ArraySaveOutput(filePath);
			}
		}
		wantContinue = RepeatAsk();
	} while (wantContinue == MENU::YES);
}