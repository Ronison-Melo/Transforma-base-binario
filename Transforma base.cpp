#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
void barra(){
	int cont=0;
	char vet[30]="";
	
	while(cont <= 100){
		printf("Carregando...\n");
		strcat(vet,"\xDB");
		printf("%s %d%%",vet, cont );
		Sleep(30);
		if(cont!=100)
		system("cls");
		cont+=1;	
	}	
}
void ini(int *vet){
	for(int i=0;i<32;i++){
		vet[i]=0;
	}
}
void imprime(int *vet,int tam){
	
		for(int i=0;i<tam;i++){
		printf("%d ",vet[i]);
	}
}
void menu(){
	system("cls");
	printf("	---------TRANSFORMACAO DE BASE----------\n\n");
	printf("	(1) - DEC -> BIN\n	(2) - BIN -> DEC\n	(3) - ENCERRAR\nESCOLHA: ");
}
void transforma_em_bin(double num,int inteiro,double dec,int *vet){
	int i,base=1,tam=0,dif=0,aux,vetaux[32],carac,tam2,t_carac=15,t_mant=31,j,k;
system("cls");
	while(base<=inteiro){//achar a menor base
		base*=2;
		tam+=1;//determina o tamanho do array aux que vai receber a parte int.
	}
	base/=2;
	if(inteiro == 0){
	tam=1; 
	base=1;
}
	int vetor[tam];
	for(i=0;i<tam;i++){//transforma a parte inteira;
		if(inteiro >= base){
			vetor[i]=1;
			inteiro-=base;
			base/=2;
		}else{
			vetor[i]=0;
			base/=2;
		}
	}inteiro=num;
	if(num<0)
	printf("-");
	imprime(vetor,tam);
	
	int vetor2[25];
		
		for(i=0;i<25;i++){
			dec*=2; 
			aux=dec;
			vetor2[i]=aux; 
			if(dec>=1){
				dec=dec-aux;
			}
		}
	printf(",");
	imprime(vetor2,25);
	printf("\n\n");
	system("pause");
	
}
void inistr(char *bits){
	for(int i=0;i<15;i++){
		bits[i] = '\0';
	}
}
void bin_dec(char *bits, int av, int pv,int cont,int ok){
	int p_int=0,i,j,base=1;
	float p_real=0, v_total=0,a;
	system("cls");
	for(i=av-1;i>=0;i--){
		if(bits[i]=='1'){
			p_int+=base;
		}
		base*=2;
	}
	if(ok==1){
		
	a=0.5;
	for(i=pv;i<cont;i++){
		if(bits[i]=='1'){
			p_real+=a;
		}
		a/=2;
	}

	v_total=p_int + p_real;
}else{
	v_total=p_int;
}
	if(bits[0]=='-')
	v_total*=(-1);
	printf("\nValor: %.10f\n",v_total);
	getch();
}
int veri(char *bits){
	int i=0,cont=0,virg=0;
	while(bits[i]!='\0'){
		if(bits[i]!='-'&&bits[i]!='1'&&bits[i]!='0'&&bits[i]!='.'&&bits[i]!=','&&bits[i]!='+'){system("cls");
		printf("\n	Apenas 0 e 1 como numeros.\n");system("pause");
		return 1;
		}
		if(bits[0]!='+'&&bits[0]!='-'&&bits[0]!='1'&&bits[0]!='0'){
			printf("\n	No inicio apenas os sinais ou bits. Tente novamente!\n");system("pause");
			return 1;
		}
		 if(i>0){
		 	if(bits[i]=='-'||bits[i]=='+'){
		printf("\n	Sequencia binaria incorreta! Sinais apenas no inicio! Tente novamente.\n\n");system("pause");
		return 1;
	}
	}
		 	if(bits[i]==','){
		 		virg+=1;
	}
	if(virg>1){
		printf("\n	Sequencia binaria incorreta! Tente novamente!\n");system("pause");
		return 1;
	}
	if(bits[i]!='0'&&bits[i]!='1')
	cont+=1;
		i+=1;
		
	}
	if(cont==i){
		printf("\n	Sequencia binaria incorreta! Tente Novamente\n");system("pause");
	return 1;
}
	
	return 0;
}
int main(){
	int op,p_int, vet[32],i,av=0,pv=0,cont,ok,ret;
	char bits[15];
	double num,p_dec;
	do{ ini(vet);
	menu();
	scanf("%d",&op);
	switch(op){ 
		case 1: system("cls");printf("DECIMAl - BINARIO\n");
		printf("\nDigite um numero em decimal: ");
		scanf("%lf",&num);
		//barra();
		if(num<0){
		p_int=num*(-1);
		p_dec=(num*(-1))-p_int;	
		}else{
		p_int=num;
		p_dec=num-p_int;
		}
		transforma_em_bin(num,p_int,p_dec,vet);	
		break;
			case 2: ret=0;do{
				inistr(bits);system("cls");printf("BINARIO - DECIMAL\n");
			printf("Digite os bits: ");
			fflush(stdin);
			gets(bits);
			//barra();
				ret=veri(bits);
			}while(ret==1); 
			i=0;cont=0; ok=0;
			while(bits[i]!='\0'){
				if(bits[i]==','||bits[i]=='.')
				ok=1;
				
				cont+=1;
				i+=1;
			}
			if(ok==1){
			i=0;av=0; pv=0;
			while(i<15){
				if(bits[i]==','||bits[i]=='.'){
					break;
				}else{
				av+=1;	
				}
				i+=1;
			}
			pv=av+1;
		}else{
			av=cont; pv=0;
		}
			bin_dec(bits,av,pv,cont,ok);
			 break;
				case 3: barra(); system("cls"); printf("\n		FIM		\n	--------------------------");Sleep(2000);break;
					default: system("cls");printf("OPCAO INVALIDA! TENTE NOVAMENTE!\n");Sleep(2000);
	}
}while(op!=3);
return 0;
}
