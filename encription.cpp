#include <iostream>
#include <string>
#include <Windows.h> // для работы SetConsoleCP, SetConsoleOutputCP
#include <fstream>


int main()
{
	SetConsoleCP(1251);			//кодировка для ввода и вывода
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	std::string word;
	std::ifstream in("hello.txt");
	in >> word;
	in.close();
	std::cout <<"Строка для зашифровки: "<< word << "\n";
	std::cout <<"--------------------------------------------------\n";
	//std::cout << "Введите строку для зашифровки: ";
	while ((word.length() % 7) != 0)
	{
		word = word + ' ';
	}

	for (int i = 0; i < word.length(); i = i + 7)
	{
		char temp = word[0 + i];
		word[0 + i] = word[6 + i];
		word[6 + i] = word[4 + i];
		word[4 + i] = word[2 + i];
		word[2 + i] = word[1 + i];
		word[1 + i] = word[3 + i];
		word[3 + i] = temp;

	}

	std::cout << "Ваша зашифрованная строка: "<<word<<"\n";

	std::ofstream out("Result.txt");
	out << word;
	out.close();
}
