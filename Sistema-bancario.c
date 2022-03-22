#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int resposta=0;
int contador=0;
 int codigoGlobal=0, CPFGlobal=0;
typedef struct clientes{
  char nome[100];
  long int codigo;
  long int cpf;
  char endereco[150];
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

void ValidaCodigo(long int codigo, clientes *primeiro, clientes *proximoCliente, char nome[130]){
  
  proximoCliente = primeiro;
  while(proximoCliente->nome!=nome && proximoCliente->codigo!=codigoGlobal){
    if(proximoCliente->codigo==codigo){
      printf("Código já cadastrado. Digite outro codigo\n");
      printf("%ld, %ld\n",proximoCliente->codigo,codigo);
      scanf("%ld",&codigo);
      ValidaCodigo(codigo, primeiro, proximoCliente,nome);
    }
    else{
      proximoCliente = proximoCliente->proximoCliente;
    }
  }
  proximoCliente->codigo=codigo;
}

void ValidaCPF(long int cpf, clientes *primeiro, clientes *proximoCliente, char nome[130]){
  
  proximoCliente = primeiro;
  while(proximoCliente->nome!=nome && proximoCliente->cpf!=CPFGlobal){
    if(proximoCliente->cpf==cpf){
      printf("CPF já cadastrado. Digite outro CPF\n");
      printf("%ld, %ld\n",proximoCliente->cpf,cpf);
      scanf("%ld",&cpf);
      ValidaCPF(cpf, primeiro, proximoCliente,nome);
    }
    else{
      proximoCliente = proximoCliente->proximoCliente;
    }
  }
  proximoCliente->cpf=cpf;
}

void CadastroCliente(clientes *primeiro, clientes *proximoCliente, clientes *inicio){
  
  int x=0;
  long int codigo;
  long int cpf;
  printf("Digite o nome do cliente a ser cadastrado\n");
  scanf("%[^\n]s%*c",proximoCliente->nome);
  printf("Digite um código de segurança\n");
  scanf(" %ld",&codigo);
  proximoCliente->codigo = codigoGlobal;
  codigoGlobal++;
  ValidaCodigo(codigo, primeiro, proximoCliente,proximoCliente->nome);
  printf("Digite o CPF do titular\n");
  scanf(" %ld",&cpf);
  ValidaCPF(cpf, primeiro, proximoCliente,proximoCliente->nome);
  printf("Digite o endereço\n");
  scanf(" %[^\n]s%*c",proximoCliente->endereco);

  proximoCliente = proximoCliente->proximoCliente;
 proximoCliente->proximoCliente = (clientes*) malloc(sizeof(clientes));
 printf("1 - Cadastrar novo cliente\n");
  printf("Aperte outra tecla para voltar ao menu\n");
 scanf("%d%*c",&x);
  if(x==1){   
    CadastroCliente(primeiro,proximoCliente, inicio);
  }
}




int main(){
  clientes *primeiro = (clientes*) malloc(sizeof(clientes));
  clientes *proximoCliente = primeiro;
  proximoCliente->proximoCliente = (clientes*) malloc(sizeof(clientes));
  clientes *inicio = primeiro;

  while(resposta != 14){
    menu();
    if(resposta ==1){
      CadastroCliente(primeiro,proximoCliente, inicio);
    }
  }
  
//Apenas para visualizar dados
  while(primeiro!=NULL){
    printf("%s, %ld\n",primeiro->nome, primeiro->codigo);
    primeiro = primeiro->proximoCliente;
  }
 


return 0;
}