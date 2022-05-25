#ifndef Avaliador_hpp
#define Avaliador_hpp
#include "Leilao.hpp"

class Avaliador
{
    private:
        float maiorValor = INT_MIN;
        float menorValor = INT_MAX;
        std::vector<Lance> maiores3Lances;
        static bool comparaLances(const Lance&, const Lance&);
    public:
        void avalia(Leilao);
        float getMaiorValor() const;
        float getMenorValor() const;
        std::vector<Lance> get3MaioresLances() const;
};

#endif