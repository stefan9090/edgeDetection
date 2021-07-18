#include <iostream>

#include "SearchTree.h"
#include <fstream>
#include <chrono>

using namespace std::chrono;

void containsWord(DictSearchTree &dict, std::string_view word)
{
    if (dict.containsWord(word))
    {
        std::cout << "contains " << word << "\n";
    }
    else
    {
        std::cout << "Did not find " << word << "\n";
    }
}

int main()
{
    std::string sourceFileName = "words_alpha.txt";
    std::fstream wordsFile;

    wordsFile.open(sourceFileName);
    if (wordsFile.is_open())
    {
        int wordCount = 0;
        DictSearchTree dict;

        auto begin = steady_clock::now();

        std::string word;
        while (std::getline(wordsFile, word))
        {
            dict.addWord(word);
            wordCount++;
        }

        auto end = steady_clock::now();

        std::cout << "Added " << wordCount << " words\n";
        std::cout << "Creation took " << duration_cast<milliseconds>(end - begin).count() << " milliseconds\n";

        containsWord(dict, "convict");
        containsWord(dict, "cigarette");
        containsWord(dict, "relaxation");
        containsWord(dict, "miscarriage");
        containsWord(dict, "calculation");
        containsWord(dict, "jealous");
        containsWord(dict, "ouijrfgzoruf");
    }
    else
    {
        std::cout << "Failed to open" << sourceFileName << std::endl;
    }
}
