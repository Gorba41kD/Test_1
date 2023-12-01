#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
void printOperatingSystem()
{
    #ifdef WINDOWS_OS
    std::cout << "Hello from Windows!" << std::endl;
    #elif LINUX_OS
    std::cout << "Hello from Linux!" << std::endl;
    #else
    std::cout << "Unknown system!" << std::endl;
	#endif
}
enum InitialData
{
	FILE_1 = 1,
	FILE_2,
	WORD
};
void deleteWords(std::vector<std::string>& words, const std::string& wordToDelete)
{
	auto it = std::remove_if(words.begin(), words.end(), [&](const std::string& word)
		{
			if (word.size() != wordToDelete.size())
			{
				return false;
			}
			for (size_t i = 0; i < word.size(); ++i)
			{
				if (tolower(word[i]) != tolower(wordToDelete[i]))
				{
					return false;
				}
			}
			return true;
		});
	words.erase(it, words.end());

}
void sortWords(std::vector<std::string>& words)
{
	std::sort(words.begin(), words.end(), [](const std::string& firstWord, const std::string& secondWord)
		{
			std::string firstTemp = firstWord;
			std::string secondTemp = secondWord;
			std::transform(firstWord.begin(), firstWord.end(), firstTemp.begin(), ::tolower);
			std::transform(secondWord.begin(), secondWord.end(), secondTemp.begin(), ::tolower);
			return firstTemp < secondTemp;
		});
}
void printWords(const std::vector<std::string>& words)
{
	std::cout << "Size = " << words.size() << std::endl;
	for (const auto& word : words)
	{
		std::cout << word << " ";
	}
	std::cout << std::endl;
}
void writingFile(std::ofstream& fout, std::string& file)
{
	char symbol{};
	std::string text{};
	do
	{
		std::cout << "Do you want to enter a file (y/n)" << std::endl;
		std::cin >> symbol;
		std::cin.ignore(32767, '\n');
		if (symbol == 'y')
		{
			std::cout << "Enter a file" << std::endl;
			std::getline(std::cin, text);
			text += ' ';
			fout.open(file, std::ios_base::app);
			fout << text;
			fout.close();
		}
		else if (symbol == 'n')
		{
			break;
		}
	} while (true);
}
void readinigFile(std::ifstream& fin, std::string& file, std::vector<std::string>& words)
{
	fin.open(file);
	std::string line{};
	std::string word{};
	while (!fin.eof())
	{
		fin >> word;
		words.push_back(word);
	}
	fin.close();
}
void writingFile(std::ofstream& fout, std::string& file, const std::vector<std::string>& words)
{
	fout.open(file, std::ios_base::app);
	for (const auto& word : words)
	{
		fout << word;
		fout << " ";
	}
	fout.close();
}
int main(int argc,char* argv[])
{
    printOperatingSystem();

	std::string firstFile = argv[FILE_1];
	std::string secondFile = argv[FILE_2];
	std::string wordToDelete = argv[WORD];

	std::ofstream fout;
	std::ifstream fin;

	std::vector<std::string> words;
	words.reserve(20);
	
	writingFile(fout, firstFile);
	readinigFile(fin, firstFile, words);

	printWords(words);
	deleteWords(words, wordToDelete);
	sortWords(words);

	std::cout << "==================================================" << std::endl;

	printWords(words);
	writingFile(fout, secondFile, words);
	 
	system("pause");

	return 0;
}