#include "functions.h"

using namespace std;

void loginn(){
	cbc();
	int opc, op, flag = 0;
	cout<<"\t\t  ██  BEM VINDO  ██\n\n";
	cout<<"\t\t  ██ 1 - Login   ██\n";
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
	char debug[100];
	

	while(flag == 0){

	FILE *Accounts = fopen("accounts","r");
	cbc();
	strcpy(login,"");
	strcpy(password,"");
	strcat(login, "LOGIN:");
	strcat(password, "SENHA:");


	printf("\t        ██    Acesso    ██\n\n");
	printf("\t     ██ Login: ");
	scanf("%s", loginU);
	printf("\t     ██ Password: ");
	scanf("%s", passwordU);
	flag = 1;
	strcat(login, loginU);
	strcat(password, passwordU);
	fscanf(Accounts,"%s\n", debug);
	fscanf(Accounts,"%s\n", lgn);
	fscanf(Accounts,"%s\n", shn);
	while(strcmp(login, lgn) != 0 || strcmp(password, shn) != 0)
	{
			if(fgets(leitor, 1000, Accounts) == NULL){
				printf("\n ██ Conta não existente, tente novamente!!\n");
				//sleep(1);
				flag = 0;
				break;
			}else
			{
				fscanf(Accounts,"%s\n", debug);
				fscanf(Accounts,"%s\n", lgn);
				fscanf(Accounts,"%s\n", shn);
		}
		
	}
	fclose(Accounts);
	if(flag==1){
    menu(login, password);
    flag == 1;
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

	printf("\t       ██   Cadastro   ██\n\n");
	printf("\t     ██ Login: ");
	scanf("%s", login);
	printf("\t     ██ Password: %d\n", password);
	printf("\n\t     ██ Digite [YES] para continuar\n");
	printf("\n\t     ██ Digite [NO] para cancelar\n");
	scanf("%s", shn);
	while(strcmp(shn, "YES")!= 0 && strcmp(shn, "NO")!= 0 && strcmp(shn, "yes")!= 0 && strcmp(shn, "no")!= 0){
		scanf("%s", shn);
	}
	if(strcmp(shn, "YES")== 0 || strcmp(shn, "yes")== 0){
		printf("Cadastrado!\n");
		//sleep(1);
	}else{
		printf("Cancelado!\n" );
		//sleep(1);
		exit(0);
	}
	FILE *Accounts = fopen("accounts","a+");
	fprintf(Accounts,"===========");
	fprintf(Accounts,"\nLOGIN:");
	fprintf(Accounts,"%s\n", login);
	fprintf(Accounts,"SENHA:");
	fprintf(Accounts,"%d\n", password);
	fprintf(Accounts,"0\n");

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

void menu(char *login, char *password)
{	
	double money;
	int flag = 0;
while(flag==0){
	cbc();
	printf("\t       ██     OPÇÕES     ██\n");
	printf("\t       █ 1 - Extrato      █\n");
	printf("\t       █ 2 - Depósito     █\n");
	printf("\t       █ 3 - Pagamento    █\n");
	printf("\t       █ 4 - Saque        █\n");
	printf("\t       █ 5 - Transferencia█\n");
	printf("\t       █ 6 - Deslogar     █\n");
	printf("\t       █ 0 - Sair         █\n");
	printf("\t       ██                ██\n\n");

	int opc;
	printf("\t       ██ Opção: ");
    scanf("%d", &opc);
	getchar();

	while(opc<0 || opc>6)
	{	
		printf ("\n██ Número do comando inválido!\n");
		printf("\n██ Informe o número da opção: ");
		scanf("%d", &opc);
	}

	switch(opc)
	{

		case 1:
		extrato(login, password, &money);
		break;

		case 2:
		deposito(login, password);
		break;

		case 3:
		pagamento(login, password);
		break;

		case 4:
		saque(login, password);
		break;

		case 5:
		transferencia(login, password);
		break;

		case 6:
		loginn();
		break;

		case 0:
		flag=1;
		sair();
		break;
	}
}
}

void extrato(char *login, char *password, double *money)
{	
	char lgn[100], shn[100], sald[100], saldo[100], leitor[1000];
	double dep = 50, x = 100, aux = 1;
	FILE *Accounts = fopen("accounts","r");
	FILE *temp = fopen("temp","w");

	while(aux>0)
	{		
			if(fgets(leitor, 1000, Accounts) == NULL)
			{	
				break;
			}

			fscanf(Accounts,"%s\n", lgn);
			fscanf(Accounts,"%s\n", shn);
			fscanf(Accounts,"%s\n", sald);

			if(strcmp(login, lgn) == 0 && strcmp(password, shn) == 0){
				cbc();
				printf("\t       ██     Extrato     ██\n\n");
				printf("\t     ██ %s\n", login);
				printf("\t     ██ SALDO: %s\n", sald);
				*money=atof(sald);
				break;
				}
	}
	fclose(Accounts);
	fclose(temp);
	rtr();
}

void deposito(char *login, char *password)
{
	char lgn[100], shn[100], sald[100], saldo[100], leitor[1000];
	double dep = 50, x = 100, aux = 1;
	cbc();
	printf("\t       ██     Deposito     ██\n\n");
	printf("\t     ██ Valor: ");
	scanf("%lf", &dep);

	FILE *Accounts = fopen("accounts","r");
	FILE *temp = fopen("temp","w");

	while(aux>0)
	{		
			if(fgets(leitor, 1000, Accounts) == NULL)
			{	
				break;
			}

			fscanf(Accounts,"%s\n", lgn);
			fscanf(Accounts,"%s\n", shn);
			fscanf(Accounts,"%s\n", sald);
			if(strcmp(login, lgn) == 0 && strcmp(password, shn) == 0){
				fprintf(temp,"===========\n");
				fprintf(temp, "%s\n",lgn);
				fprintf(temp, "%s\n",shn);
				x = atof(sald);
				x = x+dep;
				fprintf(temp, "%.2lf\n", x);
				printf("\n\t       ██     Extrato      ██\n\n");
				printf("\t     ██ %s\n", login);
				printf("\t     ██ SALDO: %.2lf\n", x);
				}else{
				fprintf(temp,"===========\n");
				fprintf(temp, "%s\n",lgn);
				fprintf(temp, "%s\n",shn);
				fprintf(temp, "%s\n",sald);
			}
	}
	fclose(Accounts);
	fclose(temp);

	Accounts = fopen("accounts","w");
	temp = fopen("temp","r");
 	while(aux>0)
	{		
			if(fgets(leitor, 1000, temp) == NULL)
			{	
				break;
			}

			fscanf(temp,"%s\n", lgn);
			fscanf(temp,"%s\n", shn);
			fscanf(temp,"%s\n", sald);			
			fprintf(Accounts,"===========\n");
			fprintf(Accounts, "%s\n",lgn);
			fprintf(Accounts, "%s\n",shn);
			fprintf(Accounts, "%s\n",sald);
			}
	fclose(Accounts);
	fclose(temp);
	rtr();
}

void pagamento(char *login, char *password)
{	
	char barra[300], lgn[100], shn[100], sald[100], saldo[100], leitor[1000];
	double pag = 50, x = 100, aux = 1;
	cbc();
	printf("\t       ██     Pagamento     ██\n\n");
	printf("\t     ██ Codigo de barra: ");
	scanf("%s", barra);
	printf("\t     ██ Valor: ");
	scanf("%lf", &pag);


	
	FILE *Accounts = fopen("accounts","r");
	FILE *temp = fopen("temp","w");
	
	while(aux>0)
	{		
			if(fgets(leitor, 1000, Accounts) == NULL)
			{	
				break;
			}

			fscanf(Accounts,"%s\n", lgn);
			fscanf(Accounts,"%s\n", shn);
			fscanf(Accounts,"%s\n", sald);

			if(strcmp(login, lgn) == 0 && strcmp(password, shn) == 0){
				fprintf(temp,"===========\n");
				fprintf(temp, "%s\n",lgn);
				fprintf(temp, "%s\n",shn);
				x = atof(sald);
				while(x<pag){
					printf("\n\t       ██ Saldo Insuficiente.\n");
					printf("\t       ██ Saldo Atual: %.2lf.\n", x);
					printf("\t       ██ Digite novamente\n\n");
					printf("\t     ██ Valor: ");
					scanf("%lf", &pag);
				}
				x = x-pag;
				fprintf(temp, "%.2lf\n", x);
				printf("\n\n\t     ██ SALDO ATUAL: %.2lf\n", x);
				}else{
				fprintf(temp,"===========\n");
				fprintf(temp, "%s\n",lgn);
				fprintf(temp, "%s\n",shn);
				fprintf(temp, "%s\n",sald);
			}
	}
	fclose(Accounts);
	fclose(temp);

	Accounts = fopen("accounts","w");
	temp = fopen("temp","r");
 	while(aux>0)
	{		
			if(fgets(leitor, 1000, temp) == NULL)
			{	
				break;
			}

			fscanf(temp,"%s\n", lgn);
			fscanf(temp,"%s\n", shn);
			fscanf(temp,"%s\n", sald);			
			fprintf(Accounts,"===========\n");
			fprintf(Accounts, "%s\n",lgn);
			fprintf(Accounts, "%s\n",shn);
			fprintf(Accounts, "%s\n",sald);
			}	
	fclose(Accounts);
	fclose(temp);
	rtr();
}

void saque(char *login, char *password)
{
	char lgn[100], shn[100], sald[100], saldo[100], leitor[1000];
	double pag = 50, x = 100, aux = 1;
	cbc();
	printf("\t       ██       Saque       ██\n\n");
	printf("\t     ██ Valor: ");
	scanf("%lf", &pag);


	
	FILE *Accounts = fopen("accounts","r");
	FILE *temp = fopen("temp","w");
	
	while(aux>0)
	{		
			if(fgets(leitor, 1000, Accounts) == NULL)
			{	
				break;
			}

			fscanf(Accounts,"%s\n", lgn);
			fscanf(Accounts,"%s\n", shn);
			fscanf(Accounts,"%s\n", sald);

			if(strcmp(login, lgn) == 0 && strcmp(password, shn) == 0){
				fprintf(temp,"===========\n");
				fprintf(temp, "%s\n",lgn);
				fprintf(temp, "%s\n",shn);
				x = atof(sald);
				while(x<pag){
					printf("\n\t       ██ Saldo Insuficiente.\n");
					printf("\t       ██ Saldo Atual: %.2lf.\n", x);
					printf("\t       ██ Digite novamente\n\n");
					printf("\t     ██ Valor: ");
					scanf("%lf", &pag);
				}
				x = x-pag;
				fprintf(temp, "%.2lf\n", x);
				printf("\n\n\t     ██ SALDO ATUAL: %.2lf\n", x);
				}else{
				fprintf(temp,"===========\n");
				fprintf(temp, "%s\n",lgn);
				fprintf(temp, "%s\n",shn);
				fprintf(temp, "%s\n",sald);
			}
	}
	fclose(Accounts);
	fclose(temp);

	Accounts = fopen("accounts","w");
	temp = fopen("temp","r");
 	while(aux>0)
	{		
			if(fgets(leitor, 1000, temp) == NULL)
			{	
				break;
			}

			fscanf(temp,"%s\n", lgn);
			fscanf(temp,"%s\n", shn);
			fscanf(temp,"%s\n", sald);			
			fprintf(Accounts,"===========\n");
			fprintf(Accounts, "%s\n",lgn);
			fprintf(Accounts, "%s\n",shn);
			fprintf(Accounts, "%s\n",sald);
			}	
	fclose(Accounts);
	fclose(temp);
	rtr();
}

void transferencia(char *login, char *password)
{
	char trans[500],lgn[100], shn[100], sald[100], saldo[100], leitor[1000];
	double pag = 50, x = 100, aux = 1, flag = 0, money;
	cbc();
	printf("\t       ██    Transferencia    ██\n\n");

	printf("\t     ██ Conta: ");
		scanf("%s", trans);
		char conta[50];
		strcpy(conta, "LOGIN:");
		strcat(conta, trans);
	value(login, password, &money);
	printf("\t     ██ Valor: ");
	scanf("%lf", &pag);
	getchar();

	while(pag>money){
		printf("\n\t       ██ Saldo Insuficiente.\n");
		printf("\t       ██ Saldo Atual: %.2lf.\n", x);
		printf("\t       ██ Digite novamente\n\n");
		printf("\t     ██ Valor: ");
		scanf("%lf", &pag);
	}
	
	FILE *Accounts = fopen("accounts","r");
	FILE *temp = fopen("temp","w");
	
	while(aux>0)
	{		
			if(fgets(leitor, 1000, Accounts) == NULL)
			{	
				break;
			}

			fscanf(Accounts,"%s\n", lgn);
			fscanf(Accounts,"%s\n", shn);
			fscanf(Accounts,"%s\n", sald);

			if(strcmp(login, lgn) == 0 && strcmp(password, shn) == 0){
				fprintf(temp,"===========\n");
				fprintf(temp, "%s\n",lgn);
				fprintf(temp, "%s\n",shn);
					x = atof(sald);
					x = x-pag;
				fprintf(temp, "%.2lf\n", x);
				printf("\n\n\t     ██ SALDO ATUAL: %.2lf\n", x);
					}else if(strcmp(conta, lgn) == 0 ){
						fprintf(temp,"===========\n");
						fprintf(temp, "%s\n",lgn);
						fprintf(temp, "%s\n",shn);
							x = atof(sald);
							x = x+pag;
						fprintf(temp, "%.2lf\n", x);
							}else{
								fprintf(temp,"===========\n");
								fprintf(temp, "%s\n",lgn);
								fprintf(temp, "%s\n",shn);
								fprintf(temp, "%s\n",sald);
			}
	}
	fclose(Accounts);
	fclose(temp);

	Accounts = fopen("accounts","w");
	temp = fopen("temp","r");
 	while(aux>0)
	{		
			if(fgets(leitor, 1000, temp) == NULL)
			{	
				break;
			}

			fscanf(temp,"%s\n", lgn);
			fscanf(temp,"%s\n", shn);
			fscanf(temp,"%s\n", sald);			
			fprintf(Accounts,"===========\n");
			fprintf(Accounts, "%s\n",lgn);
			fprintf(Accounts, "%s\n",shn);
			fprintf(Accounts, "%s\n",sald);
			}	
	fclose(Accounts);
	fclose(temp);
	rtr();

}

void rtr(){
	int opc;
	printf("\n\t       ██   1 - Menu      ██\n");
	printf("\t       ██   0 - Encerrar  ██\n");
	printf("\t       ██  Opção: ");
	scanf("%d", &opc);
	if(opc == 0){
		sair();
	}

}

void sair()
{
		system("clear");
		cbc();
		printf("\t         ██ Programa Encerrado ██\n\n");
		exit(0);
}

void value(char *login, char *password, double *money)
{	
	char lgn[100], shn[100], sald[100], saldo[100], leitor[1000];
	double aux = 1;
	FILE *Accounts = fopen("accounts","r");

	while(aux>0)
	{		
			if(fgets(leitor, 1000, Accounts) == NULL)
			{	
				break;
			}

			fscanf(Accounts,"%s\n", lgn);
			fscanf(Accounts,"%s\n", shn);
			fscanf(Accounts,"%s\n", sald);

			if(strcmp(login, lgn) == 0 && strcmp(password, shn) == 0){
				*money=atof(sald);
				break;
				}
	}
	fclose(Accounts);
}