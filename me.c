#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {

	int idade,vazio;
	char nome[100],cargo[30],sexo[10] ;
	float salb,irrf,inss,sall;

} dados ;


//função que imprime o menu

void impostos(float salb,float *irrf,float *inss){

	float bcac;

	if(salb<=1693.72){

		*inss=salb*0.08;
		bcac=salb-*inss;

	}
	else if(salb>=1693.73 && salb<=2822.90){

		*inss=salb*0.09;
		bcac=salb-*inss;

	}
	else if(salb>=2822.91 && salb<=5645.80){

		*inss=salb*0.11;
		bcac=salb-*inss;

	}
	else{

		*inss=621.04;
		bcac=salb-*inss;

	}

	if(bcac<=1903.98){

		*irrf=0;

	}
	else if(bcac>=1903,99 && bcac<=2826.65){

		*irrf=(bcac*0.075)-142.80;

					}
	else if(bcac>=2826.66 && bcac<=3751.05){

		*irrf=(bcac*0.15)-354.80;

	}
	else if(bcac>=3751.06 && bcac<=4664.67){

		*irrf=(bcac*0.225)-636.13;

	}
	else{

		*irrf=(bcac*0.275)-869.36;

	}
}

int menu(int exit){

	system("clear||cls");
	printf("Folha Salarial\n\n\n1.Alterações cadastrais\n2.Consultar dados de um funcionário\n3.IRRF repassado a RFB\n4.INSS pago a Previdência Social\n5.Total de impostos pago pela empresa\n6.Total dos salários brutos dos funcionários\n7.Total dos salários líquidos dos funcionários\n8.Tabela com dados de todos os funcionários da empresa\n9.Sobre os desenvolvedores\n10.Fechar programa e salvar alterações\n\nOBS:Para salvar alterações no programa é necessário fechar pelo menu(opção 9)\n\n\n\n");

		if(exit==2){

			printf("Opção Inválida, digite uma opção válida(Entre 1 e 10)\n\n\nEscolha uma opção:\n\n");

		}

		else{

			printf("Escolha uma opção:\n\n");

		}
}

//f1= Cadastro/exclusão de funcionário
//f2= Consultar dados de um funcionário;
//f3= IRRF repassado a RFB
//f4= INSS
//f5= total bruto
//f6= total líquido
//f7= sair

void f1(int *exit,dados *func){

	char opt[1000], inclu[1000], confi[100000];
	int inv=0,mat,can,i,corr,existe,ponto;
	double bcac;

	system("clear||cls");

	*exit=0;

	while(inv!=1000){

		system("clear||cls");

		if(inv==0){	

			printf("Tela de inclusão/exclusão de cadastro.\n\n\n1.Incluir Funcionário\n2.Excluir Funcionário\n3.Voltar ao menu principal\n\nEscolha Opção:\n");

		}

		else{

			printf("Tela de inclusão/exclusão de cadastro.\n\n\n1.Incluir Funcionário\n2.Excluir Funcionário\n3.Voltar ao menu principal\n\nOpção Inválida,escolha um opção válida(1 a 3):\n");

		}

		scanf(" %2s",&opt);
		getchar();
		
		if (strncmp(opt,"1",2)==0){

			inv=0;

			for(mat=1;mat<=2000;mat++){

				if(func[mat].vazio==1){

					break;

				}

			}

			if(mat==2001){

					system("clear||cls");
					printf("Não há vagas vagas disponíveis\n\n\nPressione Enter para retornar\n\n"),
					getchar();

			}
				
			else{

				can=1;
				while(can!=0){

					corr=2;
					while(corr!=1){

						system("clear||cls");

						if(corr==2){
							
							printf("Tela de cadastro de funcionários(Para cancelar o cadastro digite \"sair\")\n\n\nMátricula:%d\nNome:",mat);
						
						}
						else if(corr==0){

							printf("Tela de cadastro de funcionários(Para cancelar o cadastro digite \"sair\")\n\n\nNome inválido, insira apenas letras\n\nMátricula:%d\nNome:",mat);

						}
						
						fgets(inclu,sizeof(inclu),stdin);
						
						if(inclu[strlen(inclu)-1]=='\n'){

							inclu[strlen(inclu)-1]=0;

						}

						strcpy(func[mat].nome,inclu);
						if(inclu[0]!=' '){

							for(i=0;i<=strlen(inclu)-1;i++){

								inclu[i]=tolower(inclu[i]);

								if((inclu[i]-'0'>=49 && inclu[i]-'0'<=74) || (inclu[i]-'0'==-16)){

									corr=1;
									
								}
								else{

									corr=0;
									break;

								}
							}	
						}
						else{

							corr=0;

						}
					}	
					if(strcmp(inclu,"sair")==0){
						func[mat].vazio=1;
						strcpy(func[mat].nome,"NULL");
						printf("\n\nCadastro cancelado com sucesso, pressione Enter para retornar ao menu anterior\n\n");
						getchar();
						break;
					}

					corr=2;
					while(corr!=1){

						system("clear||cls");

						if(corr==2){

							printf("Tela de cadastro de funcionários(Para cancelar o cadastro digite \"sair\")\n\n\nMátricula:%d\nNome:%s\nCargo:",mat,func[mat].nome);

						}
						else if(corr==0){

							printf("Tela de cadastro de funcionários(Para cancelar o cadastro digite \"sair\")\n\n\nCargo inválido, insira apenas letras\n\nMátricula:%d\nNome:%s\nCargo:",mat,func[mat].nome);

						}
						
						fgets(inclu,sizeof(inclu),stdin);
						if(inclu[strlen(inclu)-1]=='\n'){

							inclu[strlen(inclu)-1]=0;

						}
						strcpy(func[mat].cargo,inclu);	
						if(inclu[0]!=' '){

							for(i=0;i<=strlen(inclu)-1;i++){

								inclu[i]=tolower(inclu[i]);

								if((inclu[i]-'0'>=49 && inclu[i]-'0'<=74) || (inclu[i]-'0'==-16)){

									corr=1;
									
								}
								else{

									corr=0;
									break;

								}
							}	
						}
						else{

							corr=0;

						}
					}								
					if(strcmp(inclu,"sair")==0){
						func[mat].vazio=1;
						strcpy(func[mat].nome,"NULL");
						strcpy(func[mat].cargo,"NULL");				
						printf("\n\nCadastro cancelado com sucesso, pressione Enter para retornar ao menu anterior\n\n");
						getchar();
						break;
					}					

					corr=2;
					while(corr!=1){

						system("clear||cls");

						if(corr==2){

							printf("Tela de cadastro de funcionários(Para cancelar o cadastro digite \"sair\")\n\n\nMátricula:%d\nNome:%s\nCargo:%s\nSexo:",mat,func[mat].nome,func[mat].cargo);

						}
						else if(corr==0){

							printf("Tela de cadastro de funcionários(Para cancelar o cadastro digite \"sair\")\n\n\nSexo inválido(Insira \"Masculino\" ou \"Feminino\"\n\nMátricula:%d\nNome:%s\nCargo:%s\nSexo:",mat,func[mat].nome,func[mat].cargo);

						}
						
						fgets(inclu,sizeof(inclu),stdin);						

						if(inclu[strlen(inclu)-1]=='\n'){

							inclu[strlen(inclu)-1]=0;

						}
						for(i=0;i<=strlen(inclu)-1;i++){

								inclu[i]=tolower(inclu[i]);

						}


						if(strcmp(inclu,"sair")==0){

							break;							

						}

						
						if(strcmp(inclu,"masculino")==0 || strcmp(inclu,"feminino")==0){

							corr=1;
							inclu[0]=toupper(inclu[0]);

						}

						else{

							corr=0;

						}
					}					
					strcpy(func[mat].sexo,inclu);										
					if(strcmp(inclu,"sair")==0){
						func[mat].vazio=1;
						strcpy(func[mat].nome,"NULL");
						strcpy(func[mat].cargo,"NULL");
						strcpy(func[mat].sexo,"NULL");
						printf("\n\nCadastro cancelado com sucesso, pressione Enter para retornar ao menu anterior\n\n");
						getchar();
						break;
					}
					
					corr=2;
					while(corr!=1){

						system("clear||cls");

						if(corr==2){

							printf("Tela de cadastro de funcionários(Para cancelar o cadastro digite \"sair\")\n\n\nMátricula:%d\nNome:%s\nCargo:%s\nSexo:%s\nIdade:",mat,func[mat].nome,func[mat].cargo,func[mat].sexo);

						}
						else if(corr==0){

							printf("Tela de cadastro de funcionários(Para cancelar o cadastro digite \"sair\")\n\n\nIdade inválida, insira apenas numéros\n\nMátricula:%d\nNome:%s\nCargo:%s\nSexo:%s\nIdade:",mat,func[mat].nome,func[mat].cargo,func[mat].sexo);

						}
						
						fgets(inclu,sizeof(inclu),stdin);
						if(inclu[strlen(inclu)-1]=='\n'){

							inclu[strlen(inclu)-1]=0;

						}
						
						for(i=0;i<=strlen(inclu)-1;i++){

							inclu[i]=tolower(inclu[i]);
							
						}
						if(strcmp(inclu,"sair")==0){

								break;

						}

						for(i=0;i<=strlen(inclu)-1;i++){

							if(inclu[i]-'0'>=0 && inclu[i]-'0'<=9){

								corr=1;
									
							}
							else{

								corr=0;
								break;

							}

						}						
					}	
					func[mat].idade=atoi(inclu);		
					if(strcmp(inclu,"sair")==0){
						func[mat].vazio=1;
						strcpy(func[mat].nome,"NULL");
						strcpy(func[mat].cargo,"NULL");
						strcpy(func[mat].sexo,"NULL");
						func[mat].idade=0;
						printf("\n\nCadastro cancelado com sucesso, pressione Enter para retornar ao menu anterior\n\n");
						getchar();
						break;
					}					
					
					corr=2;
					while(corr!=1){

						system("clear||cls");

						if(corr==2){

							printf("Tela de cadastro de funcionários(Para cancelar o cadastro digite \"sair\")\n\n\nMátricula:%d\nNome:%s\nCargo:%s\nSexo:%s\nIdade:%d\nSalário Bruto:",mat,func[mat].nome,func[mat].cargo,func[mat].sexo,func[mat].idade);

						}
						else if(corr==0){

							printf("Tela de cadastro de funcionários(Para cancelar o cadastro digite \"sair\")\n\n\nSalário bruto inválido, insira apenas numéros\n\nMátricula:%d\nNome:%s\nCargo:%s\nSexo:%s\nIdade:%d\nSalário Bruto:",mat,func[mat].nome,func[mat].cargo,func[mat].sexo,func[mat].idade);

						}
						
						fgets(inclu,sizeof(inclu),stdin);
						if(inclu[strlen(inclu)-1]=='\n'){

							inclu[strlen(inclu)-1]=0;

						}
						
						for(i<=0;i<=strlen(inclu)-1;i++){

							inclu[i]=tolower(inclu[i]);
							
						}
						if(strcmp(inclu,"sair")==0){

							break;

						}

						if(inclu[0]-'0'!=-2){

							ponto=0;
							for(i=0;i<=strlen(inclu)-1;i++){

								if((inclu[i]-'0'>=0 && inclu[i]-'0'<=9)){

									corr=1;
										
								}
								else if(inclu[i]-'0'==-2){

									ponto=ponto+1;
									if(ponto>=2){

										corr=0;
										break;

									}

								}
								else{

									corr=0;
									break;

								}
							}
						}
						else{

							corr=0;

						}
					}	
					func[mat].salb=atof(inclu);
					if(strcmp(inclu,"sair")==0){
						func[mat].vazio=1;
						strcpy(func[mat].nome,"NULL");
						strcpy(func[mat].cargo,"NULL");
						strcpy(func[mat].sexo,"NULL");
						func[mat].idade=0;
						func[mat].salb=0.0;
						printf("\n\nCadastro cancelado com sucesso, pressione Enter para retornar ao menu anterior\n\n");
						getchar();
						break;
					}					

					func[mat].vazio=0;

					impostos(func[mat].salb,&func[mat].irrf,&func[mat].inss);
					
					func[mat].sall=func[mat].salb-func[mat].inss-func[mat].irrf;

					system("clear||cls");
					printf("Funcionário cadastrado com sucesso.\n\n");
					printf("Mátricula: %d\nNome %s\nCargo: %s\n",mat,func[mat].nome,func[mat].cargo);
					printf("Sexo: %s\nIdade: %d\nSalário Bruto: %.2f\n",func[mat].sexo,func[mat].idade,func[mat].salb);
					printf("INSS: %.2f\nIRRF: %.2f\nSalário Líquido %.2f\n",func[mat].inss,func[mat].irrf,func[mat].sall);
					printf("\nPressione Enter para retornar ao menu anterior\n");
					getchar();
					can=0;
				}
			}	

		}
			
		else if (strncmp(opt,"2",2)==0){

			can=1;
			existe=0;
			
			while(can!=0){

				inv=0;
				system("clear||cls");
				if(existe==0){
					
					printf("Tela de exclusão de cadastro de funcionário\n\n\nMátriculas cadastradas:\n\n\nMátricula    Funcionário\n\n");
					for(mat=1;mat<=2000;mat++){

						if(func[mat].vazio==0){

							printf("%d %s\n",mat,func[mat].nome);

						}

					}
					printf("\n\nDigite a matrícula do funcionário para excluir o seu cadrasto(Para retornar ao menu anterior digite \"sair\"):\n\n");
				
				}

				else if(existe==1){

					printf("Tela de exclusão de cadastro de funcionário\n\n\nNão existe cadastro para esta mátricula\n\nMátriculas cadastradas:\n\n\nMátricula    Funcionário\n\n");
					for(mat=1;mat<=2000;mat++){

						if(func[mat].vazio==0){

							printf("%d %s\n",mat,func[mat].nome);

						}

					}
					printf("\n\nDigite a matrícula do funcionário para excluir o seu cadrasto(Para retornar ao menu anterior digite \"sair\"):\n\n");

				}
				else if(existe==2){

					printf("Tela de exclusão de cadastro de funcionário\n\n\nEntrada inválida(Entre um numéro de 1 a 2000)\n\n\nDigite a matrícula do funcionário para excluir o seu cadrasto(Para retornar ao menu anterior digite \"sair\"):\n\n");

				}		
				gets(confi);
	
				mat=atoi(confi);
				for(i=0;i<=strlen(confi)-1;i++){			

						confi[i]=tolower(confi[i]);

				}

				if(strcmp(confi,"sair")==0){

					break;

				}

				else if(mat<=2000 && mat>=1){

					if(func[mat].vazio==1){

						system("clear||cls");
						existe=1;						

					}

					else{

						existe=0;
						system("clear||cls");
						printf("Tela de exclusão de cadastro de funcionário\n\n\n");
						printf("Dados do funcionário\n\n\nNome:%s\n",func[mat].nome);
						printf("Cargo:%s\nSexo%s\nIdade:%d\nSalário Bruto:%.2f\n",func[mat].cargo,func[mat].sexo,func[mat].idade,func[mat].salb);
						printf("INSS:%.2f\nIRRF:%.2f\nSalário Líquido:%.2f\n\n\n",func[mat].inss,func[mat].irrf,func[mat].sall);
						printf("Confirmar exclusão do cadastro?\n\n1.Sim\n2.Não\n\n");						
						gets(confi);

						i=1;
						while(i!=0){

							if(atoi(confi)==1){

								func[mat].vazio=1;
								strcpy(func[mat].nome, "NULL");
								strcpy(func[mat].cargo, "NULL");
								strcpy(func[mat].sexo, "NULL");
								func[mat].idade=0;
								func[mat].salb=0.0;
								func[mat].irrf=0.0;
								func[mat].inss=0.0;
								func[mat].sall=0.0;		
								system("clear||cls");
								printf("Tela de exclusão de cadastro de funcionário\n\n\n");
								printf("Exclusão realizada com sucesso, pressione Enter para retornar ao menu anterior\n");
								getchar();
								can=0;
								break;

							}

							else if(atoi(confi)==2){

								func[mat].vazio=0;						
								system("clear||cls");
								printf("Tela de exclusão de cadastro de funcionário\n\n\n");
								printf("Cancelamento de exclusão realizada com sucesso, pressione Enter para retornar ao menu anterior\n");
								getchar();
								can=0;
								break;					
								
							}	

							else{

								system("clear||cls");
								printf("Tela de exclusão de cadastro de funcionário\n\n\n");							
								printf("Confirmar exclusão do cadastro?\n\n1.Sim\n2.Não\n\nDigite uma opção válida(1 ou 2):\n");
								gets(confi);
							}
						}
					}
				}

				else{

					existe=2;

				}

			}

		}

		else if (strncmp(opt,"3",2)==0){

			return;

		}

		else{
			inv=1;

		}

	}
}


void f2(int *exit,dados *func){
	
	int mat,i,j;
	char cmat[1000];

	system("clear||cls");
	*exit=0;
	i=0;
	while(i!=1){
		
		system("clear||cls");

		if(i==0){
			
			printf("Digite o numéro de matricula do funcionário que deseja consultar(Para sair digite \"sair\"):\n\n");
		
		}
		else if(i==2){

			printf("Mátricula não cadastrada\n\nDigite o numéro de matricula do funcionário que deseja consultar(Para sair digite \"sair\"):\n\n");

		}
		else if(i==3){

			printf("Entrada inválida,digite um numéro entre 1 e 2000\n\nDigite o numéro de matricula do funcionário que deseja consultar(Para sair digite \"sair\"):\n\n");

		}


		fgets(cmat,sizeof(cmat),stdin);
		if(cmat[strlen(cmat)-1]=='\n'){

			cmat[strlen(cmat)-1]=0;

		}

		for(j=0;j<=strlen(cmat);j++){

			cmat[j]=tolower(cmat[j]);

		}

		if(strcmp(cmat,"sair")==0){

			break;

		}

		for(j=0;j<=strlen(cmat)-1;j++){

			if(cmat[j]-'0'>=0 && cmat[j]-'0'<=9){

				i=1;

			}
			else{

				i=3;
				break;

			}

		}

		if(i==3){
			
			continue;

		}

		if(atoi(cmat)>2000 || atoi(cmat)<1){

				i=3;
				continue;

		}

		
		if(i==1){

			mat=atoi(cmat);

			if(func[mat].vazio==0){

				system("clear||cls");
				printf("Mátricula: %d\nNome %s\nCargo: %s\n",mat,func[mat].nome,func[mat].cargo);
				printf("Sexo: %s\nIdade: %d\nSalário Bruto: %.2f\n",func[mat].sexo,func[mat].idade,func[mat].salb);
				printf("INSS: %.2f\nIRRF: %.2f\nSalário Líquido %.2f\n",func[mat].inss,func[mat].irrf,func[mat].sall);
				printf("\n\nPressione Enter para retornar ao menu principal\n");
				getchar();	

			}
			else{

				i=2;

			}


		}

	}

	return;

}

void f3(int *exit,dados *func){
	
	int mat;
	double total=0;

	system("clear||cls");
	*exit=0;

	for(mat=1;mat<=2000;mat++){

		if(func[mat].vazio==0){

			total=total+func[mat].irrf;

		}

	}

	printf("Total do IRRF repassado a Receita Federal: R$ %.2f\n\n\nPressione Enter para retornar ao menu principal\n",total);
	getchar();

	return;	

}

void f4(int *exit,dados *func){
	
	int mat;
	double total=0;

	system("clear||cls");
	*exit=0;

	for(mat=1;mat<=2000;mat++){

		if(func[mat].vazio==0){

			total=total+func[mat].inss;

		}

	}

	printf("Total de INSS repassado a previdência social: R$ %.2f\n\n\nPressione Enter para retornar ao menu principal\n",total);
	getchar();

	return;

}


void f5(int *exit,dados *func){
	
	int mat;
	double total=0;

	system("clear||cls");
	*exit=0;

	for(mat=1;mat<=2000;mat++){

		if(func[mat].vazio==0){

			total=total+func[mat].inss+func[mat].irrf;

		}

	}

	printf("Total de impostos pagos pela empresa: R$ %.2f\n\n\nPressione Enter para retornar ao menu principal\n",total);
	getchar();

	return;

}

void f6(int *exit,dados *func){
	
	int mat;
	double total=0;

	system("clear||cls");
	*exit=0;

	for(mat=1;mat<=2000;mat++){

		if(func[mat].vazio==0){

			total=total+func[mat].salb;

		}

	}

	printf("Total do IRRF repassado a Receita Federal: R$ %.2f\n\n\nPressione Enter para retornar ao menu principal\n",total);
	getchar();

	return;

}

void f7(int *exit,dados *func){
	
	int mat;
	double total=0;

	system("clear||cls");
	*exit=0;

	for(mat=1;mat<=2000;mat++){

		if(func[mat].vazio==0){

			total=total+func[mat].sall;

		}

	}

	printf("Total do IRRF repassado a Receita Federal: R$ %.2f\n\n\nPressione Enter para retornar ao menu principal\n",total);
	getchar();

	return;

}

void f8(int *exit,dados *func){
	
	int mat;
	FILE *df;
	system("clear||cls");
	*exit=0;
	df=fopen("funcionarios.csv","w");
				
	if(df== NULL){
				
		printf("Erro de arquivo\n\nPresione Enter para retornar ao menu principal\n");
		getchar();
		return;
	}
			
	else{
				
		for (mat=0;mat<=2000;mat++){
												
			if(mat==0){
				
				fprintf(df,"Nome,Cargo,Sexo,Idade,Salario Bruto,IRRF,INSS,Salario Liquido\n");
			
			}
				
			else{
				
				if(func[mat].vazio==0){

					fprintf(df,"%s,%s,%s,%d,%.2f,%.2f,%.2f,%.2f\n",func[mat].nome,func[mat].cargo,func[mat].sexo,func[mat].idade,func[mat].salb,func[mat].irrf,func[mat].inss,func[mat].sall);		
				
				}
			}
		}
	}
			
	fclose(df);
	printf("Tabela exportada com sucesso para a pasta do programa\n\nPressione Enter para voltar ao menu principal\n\n");
	getchar();
	return;

}

void f9(int *exit){
	
	system("clear||cls");
	*exit=0;
	printf("Desenvolvido por Carlos Monteiro\n\nPressione Enter para retornar\n\n");
	getchar();
	return;

}

void f10(int *exit){

	*exit=1;
	system("clear||cls");
	printf("Programa finalizado com sucesso \n\n\n\n");

}



int main() {

	int mat,exit=0,i=0,j=0,k=0,aux=0;
	char opt[1000],linha[1000],palavra[1000],cont;
	dados func[2001];
	FILE *df;

	if(df=fopen("dados.csv","r")== NULL){
		
		df=fopen("dados.csv","w");

		if(df != NULL){

			fprintf(df,"Disponivel,Nome,Cargo,Sexo,Idade,Salario Bruto,IRRF,INSS,Salario Liquido\n");

			for (mat=1;mat<=2000;mat++){
				
				func[mat].vazio=1;
				strcpy(func[mat].nome, "NULL");
				strcpy(func[mat].cargo, "NULL");
				strcpy(func[mat].sexo, "NULL");
				func[mat].idade=0;
				func[mat].salb=0.0;
				func[mat].irrf=0.0;
				func[mat].inss=0.0;
				func[mat].sall=0.0;
				fprintf(df,"%d,%s,%s,%s,%d,%.2f,%.2f,%.2f,%.2f\n",func[mat].vazio,func[mat].nome,func[mat].cargo,func[mat].sexo,func[mat].idade,func[mat].salb,func[mat].irrf,func[mat].inss,func[mat].sall);		

			}
			
			system("clear||cls");
			printf("Primeiro acesso, arquivo criado com sucesso\n\nPressione enter para continuar\n");
			getchar();
			fclose(df);

		}

		else if(df == NULL){

			printf("Erro de arquivo\n");
			return 0;

		}	

	}

	else{

		df=fopen("dados.csv","r");
		mat=0;
		
		if(df != NULL){

			while(fgets(linha, sizeof(linha), df)!=NULL ){
				
				if(mat>=1){

					i=0;
					j=1;
					k=strlen(linha);
					//printf("\n%d %d\n%s\n",mat,k,linha);

					while(j<=9){

						memset(palavra,0,sizeof(palavra));
						aux=0;

						while(linha[i]!=',' && i<k-1){

							palavra[aux]=linha[i];
							i++;
							aux++;						

						}

						i++;
						switch(j){

							case 1:
								func[mat].vazio=atoi(palavra);
							break;

							case 2:
								strcpy(func[mat].nome,palavra);
							break;
							
							case 3:
								strcpy(func[mat].cargo,palavra);							
							break;
							
							case 4:							
								strcpy(func[mat].sexo,palavra);
							break;
							
							case 5:
								func[mat].idade=atoi(palavra);
							break;
							
							case 6:
								func[mat].salb=atof(palavra);
							break;
							
							case 7:
								func[mat].irrf=atof(palavra);
							break;
							
							case 8:
								func[mat].inss=atof(palavra);
							break;
							
							case 9:
								func[mat].sall=atof(palavra);
							break;
							
						}

						j++;

					}		
					
			//	printf("%d  %d,%s,%s,%s,%d,%.2f,%.2f,%.2f,%.2f\n",mat,func[mat].vazio,func[mat].nome,func[mat].cargo,func[mat].sexo,func[mat].idade,func[mat].salb,func[mat].irrf,func[mat].inss,func[mat].sall);
				
				}	

				mat++;

			}

			fclose(df);

		}

		if(df == NULL){

			printf("Erro de arquivo\n");
			return 0;

		}	

	}

	// cont='';
	// printf("%d\n",cont-'0');
	// getchar();

	while(exit!=1){

		menu(exit);
		fgets(opt,sizeof(opt),stdin);

		if (strncmp(opt,"1\n",2)==0){

			f1(&exit,func);

		}
		
		else if (strncmp(opt,"2\n",2)==0){

			f2(&exit,func);

		}
		
		else if (strncmp(opt,"3\n",2)==0){
			
			f3(&exit,func);

		}
		
		else if (strncmp(opt,"4\n",2)==0){
			
			f4(&exit,func);

		}

		else if (strncmp(opt,"5\n",2)==0){
			
			f5(&exit,func);

		}

		else if (strncmp(opt,"6\n",2)==0){
			
			f6(&exit,func);

		}
		
		else if (strncmp(opt,"7\n",1)==0){
			
			f7(&exit,func);

		}

		else if (strncmp(opt,"8\n",2)==0){
			
			f8(&exit,func);

		}

		else if (strncmp(opt,"9\n",2)==0){
			
			f9(&exit);

		}

		else if (strncmp(opt,"10\n",2)==0){
			
				
			i=0;
			while(i!=1){

				system("clear||cls");

				if(i==0){
					
					printf("Deseja salvar alterações?\n\n1.Sim\n2.Não\n\nEscolha Opção:\n");

				}
				else if(i==2){

					printf("Deseja salvar alterações?\n\n1.Sim\n2.Não\n\nOpção inválida, escolha uma opção válida:\n");


				}


				fgets(opt,sizeof(opt),stdin);

				if(strncmp(opt,"1\n",2)==0){

					df=fopen("dados.csv","w");
				
					if(df== NULL){
				
						printf("Erro de arquivo\n");
						return 0;
					}
				
					else{
				
						for (mat=0;mat<=2000;mat++){
												
							if(mat==0){
				
								fprintf(df,"Disponivel,Nome,Cargo,Sexo,Idade,Salario Bruto,IRRF,INSS,Salario Liquido\n");
				
							}
				
							else{
				
								fprintf(df,"%d,%s,%s,%s,%d,%.2f,%.2f,%.2f,%.2f\n",func[mat].vazio,func[mat].nome,func[mat].cargo,func[mat].sexo,func[mat].idade,func[mat].salb,func[mat].irrf,func[mat].inss,func[mat].sall);		
				
							}
						}
					}
				
					fclose(df);
					break;			
				}

				else if(strncmp(opt,"2\n",1)==0){

					break;

				}

				i=2;
			
			}

			f10(&exit);

		}

		else{

			exit=2;		

		}
	}
	
	return 0;

}