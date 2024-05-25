#ifndef FST_FST_H
#define FST_FST_H


#include <vector>
#include <map>
#include <string>

class FST {
int lgInputAlph;
std::vector<char> inputAlph;
int lgOutputAlph;
std::vector<char> outputAlph;
int nrStari;
std::vector<int> stari;
int stareInit;
int nrStariFinale;
std::vector<int> stariFinale;
int nrTranzitii;
std::map <std::pair<int, char>, std::vector<std::pair<int, char> > > tranzitii;

public:
    void citesteFST();
    void translate(const std::string& cuvant);
    bool eFinala(int stare);
};


#endif //FST_FST_H
