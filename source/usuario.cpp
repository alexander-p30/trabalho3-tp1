#include "../headers/usuario.h"
#include "../headers/containers.h"
#include <iostream>

using namespace std;

CntrContainerUsuario* CntrContainerUsuario::instancia = nullptr;
ContainerUsuario* CntrContainerUsuario::containerUsuario = ContainerUsuario::getInstancia();

CntrContainerUsuario* CntrContainerUsuario::getInstancia() {
  if(instancia == nullptr) {
    instancia = new CntrContainerUsuario();
  }

  return instancia;
}

bool CntrContainerUsuario::criarUsuario(string nome, string endereco, int cep, string cpf, string senha) {
  Usuario *usuario = nullptr;
  try {
    usuario = new Usuario(nome, endereco, cep, cpf, senha);
  } catch(const invalid_argument& err) {
    cerr << err.what() << endl;
    return false;
  }

  return containerUsuario->addUsuario(*usuario);
}

bool CntrContainerUsuario::cadastrarUsuario(string nome, string endereco, int cep, string cpf, string senha, string banco, string agencia, string numero) {
 Usuario *usuario = nullptr;
 Conta *cont = nullptr;
  try {
    usuario = new Usuario(nome, endereco, cep, cpf, senha);
    cont  = new Conta(banco, agencia, numero);
    usuario->account = cont;
  } catch(const invalid_argument& err) {
    cerr << err.what() << endl;
    return false;
  }

  bool usuarioCriado = containerUsuario->addUsuario(*usuario);
  if(usuarioCriado) {
    cout << "Usuário e conta criados com sucesso!" << endl;
  } else {
    cout << "Falha ao criar usuário: cpf " << cpf << " já utilizado." << endl;
  }
  return usuarioCriado;
}

bool CntrContainerUsuario::excluirUsuarioPorCpf(string cpf) {
  return containerUsuario->remUsuarioPorCpf(cpf);
}

void CntrContainerUsuario::listarUsuarios() {
  containerUsuario->listarUsuarios();
}

Usuario* CntrContainerUsuario::buscarUsuarioPorCpf(string cpf) {
  return containerUsuario->buscarUsuarioPorCpf(cpf);
}
