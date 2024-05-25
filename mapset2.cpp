// mapset2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>


using namespace std;

int main()
{

    setlocale(LC_ALL, "RUS");
       

        ifstream inputFile("Artifacts.txt");
        if (!inputFile.is_open()) {
            cerr << "Не удалось открыть файл Artifacts.txt\n";
            return 1;
        }

        map<string, int> wordCount;
        vector<string> words;
        int targetCount = 0;

        // Чтение первого числа
        if (inputFile >> targetCount) {
            string word;
            while (inputFile >> word) {
                words.push_back(word);
                wordCount[word]++;
            }
        }

        //
        else {
            cerr << "Невозможно прочитать первое число из файла\n";
            return 1;
        }

        inputFile.close();

        cout << "Слова, встречающиеся " << targetCount << " раз(a): ";
        for (const auto& pair : wordCount) {
            if (pair.second == targetCount) {
                cout << pair.first << " ";
            }
        }
        cout << endl;

        return 0;
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
