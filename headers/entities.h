#include "domains.h"

/** 
 * Classe de entidade para usuário
*/
class Usuario {
private:
  Nome nome;
  Endereco endereco;
  Cep cep;
  Cpf cpf;
  Senha senha;
public:
  // Constructors
  Usuario(
    string nome,
    string endereco,
    int cep,
    string cpf,
    string senha
  );
  Usuario() {};

  // Getters and setters
  string getNome() const;
  void setNome(string nome);
  string getEndereco() const;
  void setEndereco(string endereco);
  int getCep() const;
  void setCep(int cep);
  string getCpf() const;
  void setCpf(string cpf);
  string getSenha() const;
  void setSenha(string senha);
};

/**
 * Classe de entidade para conta 
*/
class Conta {
private:
  CodigoDeBanco banco;
  CodigoDeAgencia agencia;
  NumeroDeConta numero;
public:
  // Constructors
  Conta(
    CodigoDeBanco banco, 
    CodigoDeAgencia agencia, 
    NumeroDeConta numero
  );
  Conta() {};

  // Getters and setters
  string getBanco() const;
  void setBanco(string banco);
  string getAgencia() const;
  void setAgencia(string agencia);
  string getConta() const;
  void setConta(string conta);
};
