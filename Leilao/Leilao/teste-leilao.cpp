#include "catch.hpp"
#include "Leilao.hpp"


TEST_CASE("Leilão não deve receber lances consectuivos do mesmo usuário") {
    Leilao leilao("Fiat 047 0Km");
    Usuario vinicius("Vinicius Dias");

    Lance primeiroLance(vinicius, 1000);
    Lance segundoLance(vinicius, 1500);

    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    REQUIRE(1 == leilao.recuperaLances().size());
    REQUIRE(1000 == leilao.recuperaLances()[0].recuperaValor());
}