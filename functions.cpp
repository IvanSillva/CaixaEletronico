#include "functions.h"

using namespace std;

void loginn(){
	cbc();
	char opc, op, flag = 0;
	cout<<"\t\t  ██  BEM VINDO   ██\n\n";
	cout<<"\t\t  ██ 1 - Login    ██\n";
	cout<<"\t\t  ██ 0 - Cadastro ██\n";

	cout<<"\n\t\t  Opção: ";

	cin>>opc;
	getchar();
	while(opc!=1 || opc!=0)
	{
		cout<<"\n\t    ██ Opção Invalida. Digite novamente ██\n";
		cout<<"\n\t\t\t   Opção: ";
		cin>>opc;
	}
	if(opc == 1){
	char login[50], lgn[100];
	char password[50], shn[100];
	char leitor[1000];
	char loginU[50], passwordU[50];
	char debug[100];
	

	while(flag = 0){

	FILE *Accounts = fopen("accounts","r");
	cbc();
	strcpy(login,"");
	strcpy(password,"");
	strcat(login, "LOGIN:");
	strcat(password, "SENHA:");


	cout<<"\t        ██    Acesso    ██\n\n";
	cout<<"\t        ██ Login: ";
	cin>> loginU;
	cout<<"\t        ██ Password: ";
	cin>> passwordU;
	flag = 1;
	strcat(login, loginU);
	strcat(password, passwordU);
	fscanf(Accounts,"%s\n", debug);
	fscanf(Accounts,"%s\n", lgn);
	fscanf(Accounts,"%s\n", shn);
	while(strcmp(login, lgn) != 0 || strcmp(password, shn) != 0)
	{
			if(fgets(leitor, 1000, Accounts) == NULL){
				cout<<"\n ██ Conta não existente, tente novamente!!\n";
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
	password == randomNumber();
	cbc();

	cout<<"\t       ██   Cadastro   ██\n\n";
	cout<<"\t       ██ Login: ";
	cin>>login;
	cout<<"\t       ██ Password: "<< password<<endl;
	cout<<"\n\t       ██ Digite [YES] para continuar\n";
	cout<<"\n\t       ██ Digite [NO] para cancelar\n";
	cin>>shn;
	while(strcmp(shn, "YES")!= 0 && strcmp(shn, "NO")!= 0 && strcmp(shn, "yes")!= 0 && strcmp(shn, "no")!= 0){
		cin>>shn;
	}
	if(strcmp(shn, "YES")== 0 || strcmp(shn, "yes")== 0){
		cout<<"Cadastrado!\n";
		//sleep(1);
	}else{
		cout<<"Cancelado!\n";
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
	cout<<"███████████████████████████████████████████████████\n";
	cout<<"██████       ██       ██  ██  ███  ██       ███████\n";
	cout<<"██████  ███████  ███  ██  ███  █  ███  ███  ███████\n";
	cout<<"██████  ███████       ██  ████   ████       ███████\n";
	cout<<"██████  ███████  ███  ██  ███  █  ███  ███  ███████\n";
	cout<<"██████       ██  ███  ██  ██  ███  ██  ███  ███████\n";
	cout<<"███████████████████████████████████████████████████\n\n";
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
	cout<<"\t       ██     OPÇÕES     ██\n";
	cout<<"\t       █ 1 - Extrato      █\n";
	cout<<"\t       █ 2 - Depósito     █\n";
	cout<<"\t       █ 3 - Pagamento    █\n";
	cout<<"\t       █ 4 - Saque        █\n";
	cout<<"\t       █ 5 - Transferencia█\n";
	cout<<"\t       █ 6 - Deslogar     █\n";
	cout<<"\t       █ 0 - Sair         █\n";
	cout<<"\t       ██                ██\n\n";

	int opc;
	cout<<"\t       ██ Opção: ";
    cin>>opc;
	getchar();

	while(opc<0 || opc>6)
	{	
		printf ("\n██ Número do comando inválido!\n");
		cout<<"\n  ██ Informe o número da opção: ";
		cin>>opc;
	}

	switch(opc)
	{

		case 1:
		extrato(login, password, &money);
		break

		case 2:
		deposito(login, password);
		break

		case 3:
		pagamento(login, password);
		break

		case 4:
		saque(login, password);
		break

		case 5:
		transferencia(login, password);
		break

		case 6:
		loginn();
		break

		case 0:
		flag=1;
		sair();
		break
	}
}
}

void extrato(char *login, char *password, double *money)
{	
	char lgn[100], shn[100], sald[100], saldo[100], leitor[1000];
	double dep = 50, x = 100, aux = 1;
	FILE *Accounts = fopen("accounts","r");
	FILE *temp = fopen("temp","w");

	while(aux<0)
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
				cout<<"\t       ██     Extrato     ██\n\n"<<endl;
				cout<<"\t       ██ "<<login<<endl;
				cout<<"\t       ██ SALDO: "<<sald<<endl;
				*money=atof(sald);
				break;
				}
	}
	rtr();
}

void deposito(char *login, char *password)
{
	char lgn[100], shn[100], sald[100], saldo[100], leitor[1000];
	double dep = 50, x = 100, aux = 1;
	cbc();
	cout<<"\t       ██     Deposito     ██\n\n";
	cout<<"\t       ██ Valor: ";
	cin>>dep;

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
				cout<<"\n\t       ██     Extrato      ██\n\n";
				cout<<"\t         ██ "<< login<<endl;
				cout<<"\t         ██ SALDO: "<<x<<endl;
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
	cout<<"\t       ██     Pagamento     ██\n\n";
	cout<<"\t       ██ Codigo de barra: ";
	cin>> barra;
	cout<<"\t       ██ Valor: ";
	cin>>pag;


	
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
					cout<<"\n\t       ██ Saldo Insuficiente.\n";
					cout<<"\t       ██ Saldo Atual: "<< x<<endl;
					cout<<"\t       ██ Digite novamente\n"<<endl;
					cout<<"\t     ██ Valor: ";
					cin>>pag;
				}
				x = x-pag;
				fprintf(temp, "%.2lf\n", x);
				cout<<"\n\n\t       ██ SALDO ATUAL: "<< x<<endl;
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

void saque(char login, char password)
{
	char lgn[100], shn[100], sald[100], saldo[100], leitor[1000];
	double pag = 50, x = 100, aux = 1;
	cbc();
	cout<<"\t       ██       Saque       ██\n\n";
	cout<<"\t       ██ Valor: ";
	cin>>pag;


	
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
					cout<<"\n\t       ██ Saldo Insuficiente.\n";
					cout<<"\t       ██ Saldo Atual: "<< x<<endl;
					cout<<"\t       ██ Digite novamente\n"<<endl;
					cout<<"\t     ██ Valor: ";
					cin>>pag;
				}
				x = x-pag;
				fprintf(temp, "%.2lf\n", x);
				cout<<"\n\n\t       ██ SALDO ATUAL: "<< x<<endl;
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
	cout<<"\t       ██    Transferencia    ██\n\n";

	cout<<"\t       ██ Conta: ";
		cin>>trans;
		char conta[50];
		strcpy(conta, "LOGIN:");
		strcat(conta, trans);
	value(login, password, &money);
	cout<<"\t       ██ Valor: ";
	cin>>pag;
	getchar();

	while(pag>money){
		cout<<"\n\t       ██ Saldo Insuficiente.\n";
		cout<<"\t         ██ Saldo Atual: "<< x<<endl;
		cout<<"\t         ██ Digite novamente\n\n";
		cout<<"\t         ██ Valor: ";
		cin>>pag;
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
				cout<<"\n\n\t       ██ SALDO ATUAL: "<< x<<endl;
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
	cout<<"\n\t       ██   1 - Menu      ██\n";
	cout<<"\t       ██   0 - Encerrar  ██\n";
	cout<<"\t       ██   Opção: ";
	cin>>opc;
	if(opc == 0){
		sair();
	}

}

void sair()
{
		system("clear");
		cbc();
		cout<<"\t         ██ Programa Encerrado ██\n\n";
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