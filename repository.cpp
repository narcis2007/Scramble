#include "repository.h"
#include<fstream>
using namespace std;
Repository::Repository(std::string input_file,std::string output_file):input_file(input_file),output_file(output_file)
{
    int points;
    string name;
    ifstream f(input_file.c_str());
    while(!f.eof()){
        f>>name>>points;
        v.push_back(Word(name,points));
    }
}

void Repository::save_game(const std::vector<Word>& v2,int sum){
    ofstream g(output_file.c_str(),std::fstream::app);
    g<<"game:"<<endl;
    for_each(v2.begin(),v2.end(),[&g](Word i){                                 //FOLOSESC FOR_EACH  !!!!!
        g<<i.get_name()<<" "<<i.get_points()<<endl;
    }
    );
}

Repository::~Repository()
{

}

