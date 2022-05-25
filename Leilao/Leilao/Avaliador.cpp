#include "Avaliador.hpp"
#include <algorithm>
#include <iostream>


void Avaliador::avalia(Leilao leilao)
{
	auto lances = leilao.recuperaLances();
	for (Lance lance : lances) {

		float valorDoLance = lance.recuperaValor();
		if (valorDoLance > getMaiorValor()) {
			maiorValor = valorDoLance;
		}
		if (valorDoLance < getMenorValor()) {
			menorValor = valorDoLance;
		}
	}

	std::sort(lances.begin(), lances.end(), comparaLances);
	size_t tamanho = lances.size() > 3 ? 3 : lances.size();
	maiores3Lances = std::vector<Lance>(lances.begin(), lances.begin() + tamanho);

}

float Avaliador::getMaiorValor() const
{
	return maiorValor;
}

float Avaliador::getMenorValor() const
{
	return menorValor;
}

std::vector<Lance> Avaliador::get3MaioresLances() const {
	return maiores3Lances;
}

bool Avaliador::comparaLances(const Lance& lance1, const Lance& lance2)
{
	return lance1.recuperaValor() > lance2.recuperaValor();
}


