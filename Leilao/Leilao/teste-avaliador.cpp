#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Avaliador.hpp"
#include <iostream>

Leilao emOrdemCrescente()
{
    Lance primeiroLance(Usuario("Rafael Ledo"), 2000);
    Lance segundoLance(Usuario("Ana Maria"), 1000);
    Leilao leilao("Fiat 147 0km");

    leilao.recebeLance(segundoLance);
    leilao.recebeLance(primeiroLance);

    return leilao;
}

Leilao emOrdemDecrescente()
{
    Lance segundoLance(Usuario("Ana Maria"), 1000);
    Lance primeiroLance(Usuario("Rafael Ledo"), 2000);
    Leilao leilao("Fiat 147 0km");

    leilao.recebeLance(segundoLance);
    leilao.recebeLance(primeiroLance);

    return leilao;
}

TEST_CASE("Avaliador") {
    
    Avaliador leiloeiro;

    SECTION("Leilões ordenados") {
        Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());


        SECTION("Deve recuperar maior lance de leilão")
        {
            leiloeiro.avalia(leilao);

            REQUIRE(2000 == leiloeiro.getMaiorValor());
        }

        SECTION("Deve recuperar menor lance de leilão")
        {
            leiloeiro.avalia(leilao);

            REQUIRE(1000 == leiloeiro.getMenorValor());
        }
    }
    SECTION("Deve recuperar os três maiores lances")
    {
        Lance primeiroLance(Usuario("Rafael Ledo"), 1000);
        Lance segundoLance(Usuario("Ana Maria"), 2000);
        Lance terceiroLance(Usuario("Pedro Guilherme"), 1500);
        Lance quartoLance(Usuario("Iago Mota"), 2500);
        Leilao leilao("Fiat 147 0km");

        leilao.recebeLance(segundoLance);
        leilao.recebeLance(primeiroLance);
        leilao.recebeLance(terceiroLance);
        leilao.recebeLance(quartoLance);

        leiloeiro.avalia(leilao);

        auto maiores3Lances = leiloeiro.get3MaioresLances();
        REQUIRE(3 == maiores3Lances.size());
        REQUIRE(2500 == maiores3Lances[0].recuperaValor());
        REQUIRE(2000 == maiores3Lances[1].recuperaValor());
        REQUIRE(1500 == maiores3Lances[2].recuperaValor());
    }
}


