#include "file.h"

FileWork::FileWork(std::string path){
	m_path = path;
}

bool FileWork::NameForbidden() {
	bool isNameNormal = false;
	try {
		isNameNormal = std::filesystem::is_regular_file(m_path);
	}
	catch (std::exception) {
		std::cout << "Недопустимое имя файла!" << std::endl;
		return true;
	}
	return false;
}

std::string FileWork::ChangeName() {
	m_path = GetInput<std::string>();
	while (NameForbidden()) {
		m_path = GetInput<std::string>();
	}
	return m_path;
}

//std::string FileWork::GetName() {
//	return m_path;
//}

bool FileWork::FileExist() {
	std::ifstream CheckFile;
	CheckFile.open(m_path);
	if (CheckFile.is_open()) {
		CheckFile.close();
		return true;
	}
	else {
		return false;
	}
}

int FileWork::GetSize() {
	std::ifstream inputFile;
	int size = 0;
	inputFile.open(m_path);
	while (!inputFile.is_open()) {
		std::cout << "При открытии файла произошла ошибка!" << std::endl << std::endl;
		std::cout << "Укажите адрес файла: " << std::endl;
		m_path = GetInput<std::string>();
		while (NameForbidden()) {
			m_path = GetInput<std::string>();
		}
		inputFile.open(m_path);
	}
	std::cout << "Файл успешно открыт!" << std::endl;
	std::cout << std::endl;
	inputFile >> size;
	inputFile.close();
	return size;
}

bool FileWork::FileReadOnly() {
	std::ofstream outputFile;
	outputFile.open(m_path);
	if (outputFile.is_open()) {
		outputFile.close();
		return false;
	}
	else {
		std::cout << "Файл доступен только для чтения! Как же в него сохранять?" << std::endl;
		outputFile.close();
		return true;
	}
}

bool FileWork::SaveFileNormal() {
	bool fileCreated = false;
	if (NameForbidden()) { //Если имя запрещено, то нет смысла пытаться создавать файл
		return false;
	}
	if (FileExist()) { //Если файл уже есть, то нет смысла его проверять
		return true;
	}
	while (!fileCreated) {
		std::ofstream tryCreate;
		tryCreate.open(m_path);
		tryCreate << "check";
		tryCreate.close();
		std::ifstream tryOpen;
		tryOpen.open(m_path);
		if (tryOpen.is_open()) {
			tryOpen.close();
			remove(m_path.c_str());
			fileCreated = true;
		}
		else {
			tryOpen.close();
			fileCreated = false;
			std::cout << "Ошибка при создании файла. Провертье имя файла." << std::endl;
			return false;
		}
	}
	return true;
}