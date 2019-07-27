#include "functions.h"
void loginn(){
	cbc();
	int opc, op, flag = 0;
	printf("\t\t  ██  BEM VINDO  ██\n\n");
	printf("\t\t  ██ 1 - Login   ██\n");
	printf("\t\t  ██ 0 - Cadastro██\n");

	printf("\n\t\t  Opção: ");

	scanf("%d", &opc);
	getchar();
	while(opc!=1 && opc!=0)
	{
		printf("\n\t    ██ Opção Invalida. Digite novamente ██\n");
		printf("\n\t\t\t   Opção: ");
		scanf("%d", &opc);
	}
	if(opc == 1){
	char login[50], lgn[100];
	char password[50], shn[100];
	char leitor[1000];
	char loginU[50], passwordU[50];
	

	FILE *Accounts = fopen("accounts","r");
while(flag == 0){
	cbc();
	strcpy(login,"");
	strcpy(password,"");
	strcat(login, "LOGIN:");
	strcat(password, "SENHA:");


	printf("\t     ██  Login  ██\n\n");
	printf("\t     ██ Login: ");
	scanf("%s", loginU);
	printf("\t     ██ Password: ");
	scanf("%s", passwordU);
	flag = 1;
	strcat(login, loginU);
	strcat(password, passwordU);
	printf("%s\n", login);
	printf("%s\n", password);

	fscanf(Accounts,"%s\n", lgn);
	fscanf(Accounts,"%s", shn);
		while(strcmp(login, lgn) != 0 && strcmp(password, shn) != 0){
			if(fgets(leitor, 1000, Accounts) == NULL){
				printf("\n ██ Conta não existente, tente novamente!!\n");
				sleep(1);
				flag = 0;
				break;
			}else
			{
				fscanf(Accounts,"%s\n", lgn);
				fscanf(Accounts,"%s\n", shn);
		}
		
	}
	fclose(Accounts);
	if(flag==1){
    //tela_inicio();
    flag == 0;
	}
}
}else if(opc == 0){
	resgistro();
	loginn();
}

}



void resgistro(){
	char login[50], shn[100];
	int password;
	password = randomNumber();
	cbc();

	printf("\t     ██  CADASTRO  ██\n\n");
	printf("\t     ██ Login: ");
	scanf("%s", login);
	printf("\t     ██ Password: %d\n", password);
	printf("\n\t     ██ Digite [YES] para continuar\n");
	printf("\n\t     ██ Digite [NO] para cancelar\n");
	scanf("%s", shn);
	while(strcmp(shn, "YES")!= 0 && strcmp(shn, "NO")!= 0){
		scanf("%s", shn);
	}
	if(strcmp(shn, "YES")== 0){
		printf("Cadastrado!\n");
		sleep(1);
	}else{
		printf("Cancelado!\n" );
		sleep(1);
		exit(0);
	}
	FILE *Accounts = fopen("accounts","a+");
	fprintf(Accounts,"\nLOGIN:");
	fprintf(Accounts,"%s\n", login);
	fprintf(Accounts,"SENHA:");
	fprintf(Accounts,"%d\n", password);
	fprintf(Accounts,"SALDO:0\n");

    fclose(Accounts);


}

void cbc()
{
	system("clear");
	printf("███████████████████████████████████████████████████\n");
	printf("██████       ██       ██  ██  ███  ██       ███████\n");
	printf("██████  ███████  ███  ██  ███  █  ███  ███  ███████\n");
	printf("██████  ███████       ██  ████   ████       ███████\n");
	printf("██████  ███████  ███  ██  ███  █  ███  ███  ███████\n");
	printf("██████       ██  ███  ██  ██  ███  ██  ███  ███████\n");
	printf("███████████████████████████████████████████████████\n\n");
}

int randomNumber() {

  srand(time(NULL));
  int password; 

  do {
    password = rand() % 1000000;
  } while (password < 100000 || password == 1000000);

  return password;
}
