
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
void readll(char *argv1);
int ccount=0;
void msgbox();
void head();
void register_var(char *argv1 );
void tail();
void body(int c);
void pprint();
FILE *f1;
FILE *f2;

int main(int argc, char *argv[]){
		msgbox();
		char *dd;
		int count=0;
		int i;
		char *s1;
		char *s2;
		s1=s;
		f1=fopen("index.dat","w");
		f2=fopen("index1.dat","w");
		head();
		do{
			if (!feof(stdin)){
				fgets(c,800,stdin);
				dd=strstr(c,"\n");
				if (dd!=NULL) dd[0]=0;
				readll(c);	
			}
			c[0]=0;
		}while(!feof(stdin));
		fprintf(f1,"\nmain:\n",c);
		pprint();
		tail();
		printf("\ndone...\nopen file index.dat to see codes\n");
		fclose(f1);
		fclose(f2);
return 0;
}



void readll(char *argv1){
	char *s1;
	char *s2;
	int n;
	int r;
	int count=0;
	r=0;
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
	if (strcmp(ss[0],"echo")==0){
		register_var(ss[1]);
	}
	
	
}

void register_var(char *argv1 ){
	fprintf (f1,"var%d db \"%s\",13,10,\"$\" \n",ccount,argv1);
	ccount++;
}

void pprint(){
	int n;
	page=0;
	for(n=0;n<ccount;n++){
		body(n);
		page++;
		if (page>20){
			page=0;
			printf("\ncall key\n",c);
		}
	}
}


void body(int c){
	fprintf(f1,"\nmov dx,var%d\ncall echo\n",c);
}

void tail(){
	fprintf(f1,"\nexits:\nmov ah,0\nint 0x21\nret\n");
}

void msgbox(){
	printf ("\e[0;30;46m");
}

void head(){
	
	fprintf(f1,"\norg 0x100\n;nasm format\njmp main");
	fprintf(f1,"\necho:\nmov ah,9\nint 0x21\nret\n");
	fprintf(f1,"\nvarm1 db 13,10,\"press key to continue ,esc to exit\",13,10,\"$\"\n");
	fprintf(f1,"\nkey:\nmov dx,varm1\ncall echo\nmov ah,0\nint 0x16\ncmp al,27\njz keyesc\nret\nkeyesc:\njmp exits\nret\n");
	
}







