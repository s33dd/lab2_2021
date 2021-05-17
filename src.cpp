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

		//������ ���� ���������� �������
		inputType = (INPUT_TYPE)InputAsk();

		//��������� ������� ������� �� �����
		if (inputType == INPUT_TYPE::FILE) {
			std::cout << "������� ��� �����: " << std::endl;
			filePath = GetInput<std::string>();
			FileWork tempFile(filePath);
			while(tempFile.NameForbidden()) {
				std::cout << "������� ����� ��� �����:" << std::endl;
				filePath = tempFile.ChangeName();
			}
			arraySize = tempFile.GetSize();
			while (!SizeNormal(arraySize)) {
				std::cout << "��������� ���������� �����!" << std::endl;
				std::cout << "������� ��� �����: " << std::endl;
				filePath = tempFile.ChangeName();
				arraySize = tempFile.GetSize();
			}
		}
		else {
			std::cout << "������� ������ �������: " << std::endl;
			std::cout << "��� ����� �������� ����� ����� ����� ������ ��� ����� �����." << std::endl;
			arraySize = GetInput<int>();
			while (!SizeNormal(arraySize)) {
				std::cout << "������� ������ �������: " << std::endl;
				arraySize = GetInput<int>();
			}
		}

		FileWork file(filePath);
		Array array(arraySize);

		//������������� ����������
		if (inputType == INPUT_TYPE::RANDOM) {
			array.ArrayRandomInput(arraySize); //���������� ����������
		}
		else {
			if (inputType == INPUT_TYPE::FILE) {
				dataReaded = array.ArrayFileInput(filePath);
				while (!dataReaded) {
					std::cout << "������� ����� ��� �����:" << std::endl;
					filePath = file.ChangeName();
					dataReaded = array.ArrayFileInput(filePath);
				}; //���������� �� �����
			}
			else {
				for (int i = 0; i < arraySize; i++) {
					array.ArrayManualInput(i); //���������� �������
				}
			}
		}

		//array.ArrayOutput(arraySize); //����� �� ���������������� �������
		array.ArraySort(ZERO_INDEX, arraySize); //���������� �������
		array.ArrayOutput(arraySize); //����� ���������������� �������

		//���� �������� �����
		find = array.SoughtInput();

		//����� ����� � ������� � ����� ������
		int findIndex = array.BinarySearch(arraySize);
		if (findIndex == NO_ELEMENT) {
			SetConsoleTextAttribute(consoleHandle, BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); //��������� ����� ������ �� ������� �������, ����� �����
			std::cout << "�������� " << find << " � ������� ���.";
			SetConsoleTextAttribute(consoleHandle, standart); // ����������� � ����������� ������
			std::cout << std::endl;
		}
		else {
			SetConsoleTextAttribute(consoleHandle, BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); //��������� ����� ������ �� ������� ������, ����� �����
			std::cout << "����� " << find << " ��������� � ������� ��� ������� " << findIndex;
			SetConsoleTextAttribute(consoleHandle, standart); // ����������� � ����������� ������
			std::cout << std::endl;
		}

		//������ �� ���������� �������� ������ � ���� ����������
		if (inputType != INPUT_TYPE::FILE) {
			wantSave = SaveInputAsk();
			if (wantSave == MENU::YES) {
				std::cout << "������� ��� �����:" << std::endl;
				filePath = GetInput<std::string>();
				FileWork inputSaveFile(filePath);
				while (!inputSaveFile.SaveFileNormal()) {
					std::cout << "������� ����� ��� �����:" << std::endl;
					filePath = inputSaveFile.ChangeName();
				}
				wantRewrite = RewriteAsk(filePath);
				if (wantRewrite == MENU::YES) {
					std::string newFilePath = filePath;
					FileWork newInputSave(newFilePath);
					while (newFilePath == filePath) {
						std::cout << "������� ����� ��� �����:" << std::endl;
						newFilePath = newInputSave.ChangeName();
						while (!newInputSave.SaveFileNormal()) {
							std::cout << "������� ����� ��� �����:" << std::endl;
							newFilePath = newInputSave.ChangeName();
						}
					}
					array.ArraySaveInput(newFilePath);
				}
				else {
					while (inputSaveFile.FileReadOnly()) {
						std::cout << "������� ����� ��� �����:" << std::endl;
						filePath = inputSaveFile.ChangeName();
					}
					array.ArraySaveInput(filePath);
				}
			}
		}

		wantSave = OutputFileAsk();
		if (wantSave == MENU::YES) {
			std::cout << "������� ��� �����:" << std::endl;
			filePath = GetInput<std::string>();
			FileWork outputSaveFile(filePath);
			while (!outputSaveFile.SaveFileNormal()) {
				std::cout << "������� ����� ��� �����:" << std::endl;
				filePath = outputSaveFile.ChangeName();
			}
			wantRewrite = RewriteAsk(filePath);
			if (wantRewrite == MENU::YES) {
				std::string newFilePath = filePath;
				FileWork newOutputSave(newFilePath);
				while (newFilePath == filePath) {
					std::cout << "������� ����� ��� �����:" << std::endl;
					newFilePath = newOutputSave.ChangeName();
					while (!newOutputSave.SaveFileNormal()) {
						std::cout << "������� ����� ��� �����:" << std::endl;
						newFilePath = newOutputSave.ChangeName();
					}
				}
				array.ArraySaveOutput(newFilePath);
			}
			else {
				while (outputSaveFile.FileReadOnly()) {
					std::cout << "������� ����� ��� �����:" << std::endl;
					filePath = outputSaveFile.ChangeName();
				}
				array.ArraySaveOutput(filePath);
			}
		}
		wantContinue = RepeatAsk();
	} while (wantContinue == MENU::YES);
}