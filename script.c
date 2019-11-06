
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define textsize 800
#define nlines 12000

int page=0;
char linec[textsize];
char *c=linec;
char *cc;
char *ccc;
char *tabs[nlines];
char *var[5000];
int tindex=0;
char s[64000];
char *ss[500];
void readll(char *argv1 ,char *argv2);
int ccount=0;
void msgbox();
void head();
void register_var(char *argv1 );
void tail();
void body(int c);
void pprint();

int main(int argc, char *argv[]){
		msgbox();
		char *dd;
		int count=0;
		int i;
		char *s1;
		char *s2;
		s1=s;
		head();
		do{
			if (!feof(stdin)){
				fgets(c,800,stdin);
				dd=strstr(c,"\n");
				if (dd!=NULL) dd[0]=0;
				if (c[0]!=0) register_var(c);
				i=strlen(c);
				s1=s1+i+1;
				
			}
			c[0]=0;
		}while(!feof(stdin));
		printf("\nmain:\n");
		pprint();
		tail();
		 
return 0;
}



void readll(char *argv1 ,char *argv2){
	char *s1;
	char *s2;
	int n;
	int r;
	int count=0;
	r=0;
	strcpy(s,argv2);
	ss[count]=argv1;
	count++;
	s1=argv1;
	do{
		ss[count]=strstr(s1,",");
		if (ss[count]==NULL)r=1;
		
		if (ss[count]!=NULL){
			s2=ss[count];
			s1=s2+1;
			s2[0]=0;
			ss[count]=s1;
			count++;
		}
	}while(r==0);
	for (n=0;n<count;n++){
		printf("%d %s\n",n,ss[n]);
		
	}
	
}

void register_var(char *argv1 ){
	printf ("var%d db \"%s\",13,10,\"$\" \n",ccount,argv1);
	ccount++;
}

void pprint(){
	int n;
	for(n=0;n<ccount;n++){
		body(n);
	}
}

void head(){
	
	printf("\norg 0x100\n;nasm format\njmp main");
	printf("\nprint:\nmov ah,9\nint 0x21\nret\n");
	
}


void body(int c){
	printf("\nmov dx,var%d\ncall print\n",c);
}

void tail(){
	printf("\nexits:\nmov ah,0\nint 0x21\nret\n");
}

void msgbox(){
	printf ("\e[0;30;46m");
}








