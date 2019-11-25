#define textsize 900000
#define nlines 12000


int count;
int ccount=0;
int lastslasts=0;
int nextsnexts=0;
char labels[50*50];
int mainsub=0;
int substart=0;
int n=0;
int parametscount=0;
int paramets[5000];
int varnextstart=0;
int varnext=0;
long varsart;
int lineno;
int error;
int eerror;
int page=0;
char linec[800];
long cursor=0;
int subcursor=0;
int varcursor=0;
char *c=linec;
char *cc;
char *ccc;
char *tabs[nlines];
char *var[5000];
char *subs[5000];
char var0[1024];
char var3[160];
char varvar[64000];
int tindex=0;
char s[textsize];
char *ss[500];
int count2=0;
char *i[1024];
char *ii[50];
char *iii[1024];
char var2[]=";";
FILE *f1;
FILE *f2;
FILE *f3;

void addtxtbody(char *s);
void readll2(int n);
void addkeys2();
void addcode2();
int screen();
int findvar(char *s);
int back();
int doevents();
int box();
int hline();
int vline();

//=================================================================
void readll2(int n){
	if (n==71)  screen();
	if (n==75)  back();
	if (n==76)  hline();
	if (n==77)  doevents();
	if (n==78)  box();
	if (n==85)  vline();
}

//=================================================================



//=================================================================

//addtxtbody
void addtxtbody(char *s){
	fprintf(f2,"%s\n",s);
}


//=================================================================
//findvar
int findvar(char *s){
	int n;
	int i=-1;
	for (n=0;n<varcursor;n++){
		if(strcmp(s,var[n])==0){
			i=n;
			n=varcursor+1;
		}
		
	}
	return i;
}



//=================================================================
//uppercase
char *uppercase(char *s){
	int n;
	int nn=strlen(s);
	int value=0;
	char *r=s;
	char c=0;
	for(n=0;n<nn;n++){
		c=s[n];
		if (c!=0){
			if (value==0 && c>32){
				value=1;
				r=s+n;
			}
			if (c>='a' && c<='z')s[n]=c-32;
			if (value==1 && c<33){
				s[n]=0;
				n=nn+1;
			}
		}
		
	}

	return r;
}


void addkeys2(){
;
}

//=================================================================

void addcode2(){
;
}

//=================================================================

int screen(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(2==count){

		error=0;

		ss1=uppercase(ss[1]);
		i1=findvar(ss1);
		if (i1==-1){
			printf("error var1\n");
			error=1;
		}




									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[si]");
									addtxtbody("	call scr");



		}
		return 0;
}

//=================================================================

int back(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(2==count){

		error=0;

		ss1=uppercase(ss[1]);
		i1=findvar(ss1);
		if (i1==-1){
			printf("error var1\n");
			error=1;
		}




									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov al,[bx]");
									addtxtbody("	mov edi,140000h") ;
									addtxtbody("	mov ecx,1ffffh") ;
									addtxtbody("	push ds");
									addtxtbody("	push es");
									addtxtbody("	mov edx,0");
									addtxtbody("	mov ds,dx");
									addtxtbody("	mov es,dx");
									addtxtbody("	call memfilld");
									addtxtbody("	pop es");
									addtxtbody("	pop ds");



		}
		return 0;
}

//=================================================================

int doevents(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(1==count){

		error=0;

									addtxtbody("	call setvideo");





		}
		return 0;
}

//=================================================================

//=================================================================

int box(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	char *ss1;
	if(6==count){

		error=0;

		ss1=uppercase(ss[1]);
		i1=findvar(ss1);
		if (i1==-1){
			printf("error var1\n");
			error=1;
		}

		ss1=uppercase(ss[2]);
		i2=findvar(ss1);
		if (i2==-1){
			printf("error var2\n");
			error=1;
		}

		ss1=uppercase(ss[3]);
		i3=findvar(ss1);
		if (i3==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}


		ss1=uppercase(ss[5]);
		i5=findvar(ss1);
		if (i5==-1){
			printf("error var5\n");
			error=1;
		}






									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,boxdx");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,boxdy");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,boxdx1");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,boxdy1");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i5+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov al,[si]");
									addtxtbody("	mov si,boxdcolor");
									addtxtbody("	cs");
									addtxtbody("	mov [si],al");
									addtxtbody("	call boxd32");

									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	xor eax,eax");
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	xor ebx,ebx");
									addtxtbody("	cs");
									addtxtbody("	mov bx,[si]");
									addtxtbody("	sub ebx,eax");
									addtxtbody("	mov eax,ebx");
									addtxtbody("	push eax");
									addtxtbody("	xor ecx,ecx");
									addtxtbody("	xor edx,edx");
									addtxtbody("	mov ebx,4");
									addtxtbody("	div ebx");
									addtxtbody("	xor ecx,ecx");
									addtxtbody("	xor edx,edx");
									addtxtbody("	mul ebx");
									addtxtbody("	pop ebx");
									addtxtbody("	sub ebx,eax");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	xor eax,eax");
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	sub eax,ebx");

									addtxtbody("	mov si,boxx");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,boxy");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,boxx1");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,boxy1");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i5+varnextstart);
									addtxtbody("	mov al,[si]");
									addtxtbody("	mov si,boxcolor");
									addtxtbody("	mov [si],al");
									addtxtbody("	call box32");






		}
		return 0;
}

//=================================================================


int hline(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	char *ss1;
	if(5==count){

		error=0;

		ss1=uppercase(ss[1]);
		i1=findvar(ss1);
		if (i1==-1){
			printf("error var1\n");
			error=1;
		}

		ss1=uppercase(ss[2]);
		i2=findvar(ss1);
		if (i2==-1){
			printf("error var2\n");
			error=1;
		}

		ss1=uppercase(ss[3]);
		i3=findvar(ss1);
		if (i3==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}



									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,hlinex");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,hliney");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,hlinex1");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov al,[si]");
									addtxtbody("	mov si,hlinecolor");
									addtxtbody("	cs");
									addtxtbody("	mov [si],al");
									addtxtbody("	call hlined32");


									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	xor eax,eax");
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	xor ebx,ebx");
									addtxtbody("	cs");
									addtxtbody("	mov bx,[si]");
									addtxtbody("	sub ebx,eax");
									addtxtbody("	mov eax,ebx");
									addtxtbody("	push eax");
									addtxtbody("	xor ecx,ecx");
									addtxtbody("	xor edx,edx");
									addtxtbody("	mov ebx,4");
									addtxtbody("	div ebx");
									addtxtbody("	xor ecx,ecx");
									addtxtbody("	xor edx,edx");
									addtxtbody("	mul ebx");
									addtxtbody("	pop ebx");
									addtxtbody("	sub ebx,eax");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	xor eax,eax");
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	sub eax,ebx");

									addtxtbody("	mov si,hlinex");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,hliney");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,hlinex1");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov al,[si]");
									addtxtbody("	mov si,hlinecolor");
									addtxtbody("	cs");
									addtxtbody("	mov [si],al");
									addtxtbody("	call hlined32");


		}
		return 0;
}

//=================================================================


int vline(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	char *ss1;
	if(5==count){

		error=0;

		ss1=uppercase(ss[1]);
		i1=findvar(ss1);
		if (i1==-1){
			printf("error var1\n");
			error=1;
		}

		ss1=uppercase(ss[2]);
		i2=findvar(ss1);
		if (i2==-1){
			printf("error var2\n");
			error=1;
		}

		ss1=uppercase(ss[3]);
		i3=findvar(ss1);
		if (i3==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}




									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,vlinex");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,vliney");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ax,[si]");
									addtxtbody("	mov si,vliney1");
									addtxtbody("	cs");
									addtxtbody("	mov [si],ax");
									fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov al,[si]");
									addtxtbody("	mov si,vlinecolor");
									addtxtbody("	cs");
									addtxtbody("	mov [si],al");
									addtxtbody("	call vline32");





		}
		return 0;
}

//=================================================================


