#include "Usuario.hpp"

Usuario::Usuario(std::string nome): nome(nome)
{
}

std::string Usuario::recuperaNome() const
{
    return nome;
}

std::string Usuario::getPrimeiroNome() const
{
    return nome.substr(0, nome.find(' '));
} 