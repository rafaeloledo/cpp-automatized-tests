#include "Leilao.hpp"

Leilao::Leilao(std::string descricao) : descricao(descricao)
{

}

const std::vector<Lance>& Leilao::recuperaLances() const
{
	return lances;
}

bool Leilao::usuariosDiferentes(const Lance& lance) {
	return lances.back().getNomeUsuario() != lance.getNomeUsuario();
}

void Leilao::recebeLance(const Lance& lanceAtual)
{
	if (lances.size() == 0 || usuariosDiferentes(lanceAtual)) {
		lances.push_back(lanceAtual);
	}
}

