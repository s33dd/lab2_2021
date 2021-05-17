#include "array.h"

Array::Array(int size) {
	m_arraySize = size;
	m_array = new int[m_arraySize];
	m_sought = 0;
}

Array::~Array() {
	delete[] m_array;
}

void Array::ArraySort(int firstIndex, int size) {
	int leftBorder = firstIndex;
	int rightBorder = size - 1;
	int temp = 0;
	int comparingElement = m_array[firstIndex];
	while (leftBorder <= rightBorder) {
		while (m_array[leftBorder] < comparingElement) {
			leftBorder++;
		}
		while (m_array[rightBorder] > comparingElement) {
			rightBorder--;
		}
		if (leftBorder <= rightBorder) {
			temp = m_array[leftBorder];
			m_array[leftBorder] = m_array[rightBorder];
			m_array[rightBorder] = temp;
			leftBorder++;
			rightBorder--;
		}
	}
	if (rightBorder > firstIndex) {
		ArraySort(firstIndex, rightBorder + 1);
	}
	if (leftBorder < size) {
		ArraySort(leftBorder, size);
	}
}

void Array::ArrayManualInput(int index) {
	std::cout << "¬ведите " << index + 1 << " элемент массива: " << std::endl;
	m_array[index] = GetInput<int>();
}

void Array::ArrayRandomInput(int size) {
	unsigned int seed = (unsigned int)time(0);
	srand(seed);
	for (int i = 0; i < size; i++) {
		m_array[i] = rand() % (UPPER_BORDER - LOWER_BORDER) + LOWER_BORDER;
	}
}

bool Array::ArrayFileInput(std::string path) {
	std::string data;
	std::ifstream inputFile;
	inputFile.open(path);
	getline(inputFile, data);
	m_arraySize = stoi(data);
	try {
		for (int i = 0; i < m_arraySize; i++) {
				getline(inputFile, data);
				m_array[i] = stoi(data);
		}
	}
	catch (const std::exception&) {
		std::cout << "¬ файле недостаточно данных, либо они представлены в неверном формате." << std::endl;
		std::cout << "“ребуемый формат: перва€ строка Ч размер массива, последующие строки Ч по одному элементу массива." << std::endl;
		std::cout << "Ёлементов должно быть столько же, сколько указано в размере." << std::endl << std::endl;
		inputFile.close();
		return false;
	}
	inputFile.close();
	return true;
}

void Array::ArraySaveInput(std::string path) {
	std::ofstream saveInputFile;
	saveInputFile.open(path);
	saveInputFile << m_arraySize;
	for (int i = 0; i < m_arraySize; i++) {
		saveInputFile << std::endl << m_array[i];
	}
	saveInputFile.close();
}

void Array::ArraySaveOutput(std::string path) {
	std::ofstream saveOutputFile;
	saveOutputFile.open(path);
	int findIndex = BinarySearch(m_arraySize);
	saveOutputFile << "¬ведЄнный массив: " << std::endl;
	for (int i = 0; i < m_arraySize; i++) {
		saveOutputFile << m_array[i] << " ";
	}
	saveOutputFile << std::endl;
	if (findIndex == NO_ELEMENT) {
		saveOutputFile << "Ёлемента " << m_sought << " в массиве нет." << std::endl;
	}
	else {
		saveOutputFile << "„исло " << m_sought << " находитс€ в массиве под номером " << findIndex << std::endl;
	}
	saveOutputFile.close();
}


void Array::ArrayOutput(int size) {
	std::cout << "¬ведЄнный массив: " << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << m_array[i] << " ";
	}
	std::cout << std::endl;
}

int Array::BinarySearch(int size) {
	int leftBorder = 0;
	int rightBorder = size - 1;
	int index = 0;
	int middle = 0;
	while (leftBorder <= rightBorder) {
		middle = (leftBorder + ((rightBorder - leftBorder) / 2) );
		if (m_array[middle] == m_sought) {
			index = middle;
			return index + 1;
		}
		if (m_array[middle] > m_sought) {
			rightBorder = middle - 1;
		}
		else {
			leftBorder = middle + 1;
		}
		
	}
	return NO_ELEMENT;
}

int Array::operator[](int index){
	return m_array[index];
}

int Array::SoughtInput() {
	std::cout << "¬ведите число, которое вы желаете найти: " << std::endl;
	std::cout << "ѕри вводе дробного числа будет вз€та только его цела€ часть." << std::endl;
	m_sought = GetInput<int>();
	return m_sought;
}

int Array::GetSought() {
	return m_sought;
}

void Array::First() {
	m_array[0] = 19;
	m_array[1] = 10;
	m_array[2] = 12;
	m_array[3] = 0;
	m_array[4] = 11;
	m_sought = 0;
}

void Array::Second() {
	m_array[0] = 0;
	m_array[1] = 0;
	m_array[2] = -14;
	m_array[3] = 1;
	m_array[4] = 56;
	m_array[5] = 11;
	m_array[6] = 11;
	m_sought = -14;
}

void Array::Third() {
	m_array[0] = 0;
	m_array[1] = 0;
	m_array[2] = 152;
	m_sought = 1;
}

void Array::Fourth() {
	m_array[0] = 1;
	m_array[1] = 0;
	m_array[2] = -14;
	m_array[3] = -17;
	m_array[4] = 856;
	m_array[5] = -11;
	m_sought = -11;
}

void Array::Fifth() {
	m_array[0] = 0;
	m_array[1] = 4;
	m_array[2] = -14;
	m_array[3] = 1;
	m_array[4] = 56;
	m_array[5] = 15;
	m_array[6] = 11;
	m_sought = 0;
}

bool SizeNormal(int size) {
	if (size <= 0) {
		std::cout << "–азмер массива должен быть больше нул€!" << std::endl;
		return false;
	}
	else {
		return true;
	}
}