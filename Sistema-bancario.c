#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int resposta=0,contador=0;
 int codigoGlobal=0, CPFGlobal=0;
typedef struct clientes{
  char nome[100];
  long int codigo;
  long int cpf;
  char endereco[150];
  int preenchido;
  struct clientes *proximoCliente;
}clientes;

typedef struct contas{
  
  struct contas *proximaConta;
} contas;



int menu(){
  
  printf("1 - Cadastrar novo cliente\n");
  printf("2 - Buscar cliente\n");
  printf("3 - Listar clientes\n");
  printf("4 - Atualizar dados de cliente\n");
  printf("5 - Excluir cliente\n");
  printf("6 - Visualizar dados do cliente\n");
  printf("7 - Cadastrar nova conta\n");
  printf("8 - Buscar Conta\n");
  printf("9 - Listar Contas\n");
  printf("10 - Atualizar dados da conta\n");
  printf("11 - Excluir conta\n");
  printf("12 - Visualizar dados da conta\n");
  printf("13 - Realizar Saque, trânsferência ou depósito\n");
  printf("14 - Sair\n");
  scanf("%i%*c",&resposta);
  
  while(resposta!=1 &&resposta!=2 && resposta!=3 && resposta!=4 && resposta!=5 && resposta!=6 && resposta!=7 && resposta!=8 && resposta!=9 && resposta!=10 && resposta!=11 && resposta!=12 && resposta!=13 && resposta!=14){
  printf("Resposta inválida. Tente novamente\n");
  scanf("%i%*c",&resposta);
}
  return resposta;
}

void ValidaCodigo(long int codigo, clientes *primeiro, clientes *proximoCliente){
  
  proximoCliente = primeiro;
  while(proximoCliente->preenchido==1){
    printf("entrei\n");
    if(proximoCliente->codigo==codigo){
      printf("Código já cadastrado. Digite outro codigo\n");
      scanf("%ld",&codigo);
      ValidaCodigo(codigo, primeiro, proximoCliente);
    }
    else{
      proximoCliente = proximoCliente->proximoCliente;
    }
  }
  proximoCliente->codigo=codigo;
}

void ValidaCPF(long int cpf, clientes *primeiro, clientes *proximoCliente){
  
  proximoCliente = primeiro;
  while(proximoCliente->preenchido==1){
    if(proximoCliente->cpf==cpf){
      printf("CPF já cadastrado. Digite outro CPF\n");
      scanf("%ld",&cpf);
      ValidaCPF(cpf, primeiro, proximoCliente);
    }
    else{
      proximoCliente = proximoCliente->proximoCliente;
    }
  }
  proximoCliente->cpf=cpf;
}

void CadastroCliente(clientes *primeiro, clientes *proximoCliente){
  proximoCliente=primeiro;

  while(proximoCliente->preenchido==1){
    proximoCliente=proximoCliente->proximoCliente;
    printf("1");
  }
  
  long int codigo;
  long int cpf;
  printf("Digite o nome do cliente a ser cadastrado\n");
  scanf(" %[^\n]s%*c ",proximoCliente->nome);
  printf("Digite um código de segurança\n");
  scanf(" %ld",&codigo);
  proximoCliente->codigo = codigoGlobal;
  codigoGlobal++;
  ValidaCodigo(codigo, primeiro, proximoCliente);
  printf("Digite o CPF do titular\n");
  scanf(" %ld",&cpf);
  ValidaCPF(cpf, primeiro, proximoCliente);
  printf("Digite o endereço\n");
  scanf(" %[^\n]s%*c",proximoCliente->endereco);
  proximoCliente->preenchido=1;
  proximoCliente->proximoCliente = (clientes*) malloc(sizeof(clientes));
  proximoCliente = proximoCliente->proximoCliente;
}


void listarClientes(clientes *primeiro, clientes *proximoCliente){
  proximoCliente = primeiro;
  while(proximoCliente->preenchido==1){
    printf("%s\n",proximoCliente->nome);
    proximoCliente = proximoCliente->proximoCliente;
  }
}

void buscaCliente(clientes *primeiro, clientes *proximoCliente){
  long int code;
  printf("Digite o código do cliente pelo qual deseja buscar\n");
  scanf("%ld",&code);
  proximoCliente = primeiro;
  while(proximoCliente->preenchido==1){
    if(proximoCliente->codigo==code){
      printf("Cliente encontrado:\n");
      printf("Nome: %s\n", proximoCliente->nome);
      printf("CPF: %ld\n", proximoCliente->cpf);
      printf("Endereço: %s\n",proximoCliente->endereco);
      return;
    }
    else
    proximoCliente = proximoCliente->proximoCliente;
  }
  printf("Cliente não encontrado\n");
}

int main(){
  clientes *primeiro = (clientes*) malloc(sizeof(clientes));
  clientes *proximoCliente = primeiro;
  primeiro->preenchido=0;
 

  while(resposta != 14){
    menu();
    if(resposta ==1){
      CadastroCliente(primeiro,proximoCliente);
    }
    else if(resposta==2){
      buscaCliente(primeiro,proximoCliente);
    }
    else if(resposta==3){
      listarClientes(primeiro, proximoCliente);
    }
  }
  
 


return 0;
}