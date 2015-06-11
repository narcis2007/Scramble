#ifndef REPOSITORY_H
#define REPOSITORY_H
#include<string>
#include"word.h"
#include<vector>
class Repository
{
    std::string input_file,output_file;
    std::vector<Word> v;
public:
    Repository(std::string input_file,std::string output_file);
    ~Repository();
    const std::vector<Word>& get_all(){return v;}
    void save_game(const std::vector<Word>& guessedWords,int sum);
};

#endif // REPOSITORY_H
