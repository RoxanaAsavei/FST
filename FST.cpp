#include "FST.h"
#include <fstream>
#include <queue>
#include <iostream>

void FST::citesteFST() {
    std::ifstream fin("date.in");
    fin >> lgInputAlph;
    inputAlph.resize(lgInputAlph);
    for(int i = 0; i < lgInputAlph; ++i)
        fin >> inputAlph[i];
    fin >> lgOutputAlph;
    outputAlph.resize(lgOutputAlph);
    for(int i = 0; i < lgOutputAlph; ++i)
        fin >> outputAlph[i];
    fin >> nrStari;
    stari.resize(nrStari);
    for(int i = 0; i < nrStari; ++i) {
        fin >> stari[i];
    }
    fin >> stareInit;
    fin >> nrStariFinale;
    stariFinale.resize(nrStariFinale);
    for(int i = 0; i < nrStariFinale; ++i)
        fin >> stariFinale[i];
    fin >> nrTranzitii;
    int stare1, stare2;
    char litera1, litera2;
    for(int i = 0; i < nrTranzitii; ++i) {
        fin >> stare1 >> litera1;
        fin >> stare2 >> litera2;
        if(tranzitii.find({stare1, litera1}) != tranzitii.end()) {
            tranzitii[{stare1, litera1}].emplace_back(stare2, litera2);
        }
        else {
            tranzitii[{stare1, litera1}] = {{stare2, litera2}};
        }
    }
}

void FST::translate(const std::string& cuvant) {
    /// cuvant, poz litera la care ma aflu in el, starea in care sunt
    std::queue <std::tuple <std::string, int, int> > dePrelucrat;
    std::vector <std::string> output;
    dePrelucrat.emplace(cuvant, 0, stareInit);
    while(!dePrelucrat.empty()) {
        std::tuple <std::string, int, int> t = dePrelucrat.front();
        dePrelucrat.pop();
        int stare1 = std::get<2> (t);
        int idx = std::get<1> (t);
        std::string cuvant1 = std::get<0> (t);
        if(idx == cuvant1.length()) { // s-a terminat cuvantul
            if(eFinala(stare1)) {
                output.emplace_back(cuvant1);
            }
        }

        else {
            char litera1 = cuvant1[idx]; // luam litera de la poz respectiva
            if(tranzitii.find({stare1, litera1}) != tranzitii.end()) {
                // luam fiecare element din vector, inlocuim litera si mergem in starea respectiva
                for(auto pereche : tranzitii[{stare1, litera1}]) {
                    int stare2 = pereche.first;
                    char litera2 = pereche.second;
                    cuvant1[idx] = litera2;
                    dePrelucrat.emplace(cuvant1, idx + 1, stare2);
                }
            }
        }

    }

    for(const auto& c : output) {
        std::cout << c << "\n";
    }

}

bool FST::eFinala(int stare) {
    for(auto s : stariFinale) {
        if(s == stare)
            return true;
    }
    return false;
}

