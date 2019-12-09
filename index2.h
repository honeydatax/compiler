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
int stringlen();
int strs();
int strcats();
int strcopys();
int mempoke();
int inputs();
int mempeek();
int inputstring();
int vals();
int floatconsts();
void addkey(char *sss,int func);
void addvar(char *sss);
char *uppercase(char *s);
int doubleconsts();
int booleanlike();
int booleandiferent();
int ors();
int booleanbig();
int booleanless();
int notss();
int bbooleanb();
int filecreat();
int fileopen();
int fileclose();
int filewrite();
int fileread();
int nosound();
int sound();
int beeps();
int stringlow();
int stringhigh();
int findchar();
int stringcmp();
int findstr();
//=================================================================
void readll2(int n){
	if (n==22) strcats();
	if (n==23) strcopys();
	if (n==25) inputstring();
	if (n==33) strs();
	if (n==34) vals();
	if (n==44) filecreat();
	if (n==45) fileopen();
	if (n==46) fileclose();
	if (n==47) fileread();
	if (n==48) filewrite();
	if (n==49) stringlen();
	if (n==54) mempoke();
	if (n==53) mempeek();
	if (n==56) notss();
	if (n==61) stringcmp();
	if (n==62) stringlow();
	if (n==63) stringhigh();
	if (n==65) findchar();
	if (n==67) findstr();
	if (n==71) screen();
	if (n==75) back();
	if (n==76) hline();
	if (n==77) doevents();
	if (n==78) box();
	if (n==85) vline();
	if (n==86) nosound();
	if (n==87) sound();
	if (n==88) beeps();
	if (n==120) floatconsts();
	if (n==121) doubleconsts();
	if (n==122) booleanlike();
	if (n==123) booleandiferent();
	if (n==124) ors();
	if (n==125) booleanbig();
	if (n==126) booleanless();
	if (n==127) bbooleanb();
}

//=================================================================



//=================================================================

//addtxtbody
void addtxtbody(char *s){
	fprintf(f2,"%s\n",s);
}


//=================================================================
//addkey
void addvar(char *sss){
	int i;
	char *ss1;
	var[varcursor]=s+cursor;
	strcpy(var[varcursor],sss);
	ss1=uppercase(var[varcursor]);
	i=strlen(ss1)+2;
	var[varcursor]=ss1;
	cursor=cursor+((long) i);
	varcursor++;
	
}



//=================================================================


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
//=================================================================

//addkey
void addkey(char *sss,int func){
	int i;
	char *ss;
	subs[subcursor]=s+cursor;
	strcpy(subs[subcursor],sss);
	ss=uppercase(subs[subcursor]);
	i=strlen(ss)+2;
	subs[subcursor]=ss;
	//printf("t%d,%s,%d\n",subcursor,subs[subcursor],func);
	paramets[subcursor]=func;
	cursor=cursor+((long) i);
	subcursor++;
	
}

//=================================================================


void addkeys2(){
;
	addkey ("float.const",2); //120
	addkey ("double.const",2); //121
	addkey ("boolean.like",4); //122
	addkey ("boolean.diferent",4); //123
	addkey ("bits.or",4); //124
	addkey ("boolean.big",4); //125
	addkey ("boolean.less",4); //126
	addkey ("(boolean)",3); //127
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
									addtxtbody("	mov ecx,64000") ;
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


int stringlen(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	char *ss1;
	if(3==count){

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



									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[si]");
									addtxtbody("	call len32");
									fprintf(f2,"	mov di,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [di],eax");


		}
		return 0;
}

//=================================================================

int strs(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	char *ss1;
	if(3==count){

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

										fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
										fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
										addtxtbody("	cs");
										addtxtbody("	mov edi,[bx]");
										addtxtbody("	call STR32");


		}
		return 0;
}

//=================================================================

//=================================================================

int strcats(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	char *ss1;
	if(3==count){

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

									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov edi,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									addtxtbody("	call strcat");



		}
		return 0;
}

//=================================================================

int strcopys(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	char *ss1;
	if(3==count){

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

									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov di,[bx]");
									addtxtbody("	mov ax,0");
									addtxtbody("	mov ds,ax");
									addtxtbody("	mov al,0");
									addtxtbody("	mov [edi],al");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov ds,ax");
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									addtxtbody("	call strcat");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov ds,ax");



		}
		return 0;
}

//=================================================================

//=================================================================

int mempoke(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	char *ss1;
	if(3==count){

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

									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov edi,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov al,[bx]");
									addtxtbody("	mov dx,0");
									addtxtbody("	mov ds,dx");
									addtxtbody("	mov [edi],al");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov ds,ax");


		}
		return 0;
}

//=================================================================


int mempeek(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	char *ss1;
	if(3==count){

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

									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	mov di,bx");
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									addtxtbody("	mov dx,0");
									addtxtbody("	mov ds,dx");
									addtxtbody("	mov eax,[esi]");
									addtxtbody("	mov dx,cs");
									addtxtbody("	mov ds,dx");
									addtxtbody("	cs");
									addtxtbody("	mov [di],eax");



		}
		return 0;
}

//=================================================================


//=================================================================


int inputstring(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	char *ss1;
	if(3==count){

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


									addtxtbody("	mov bx,L50");
									addtxtbody("	mov dx,bx");
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov cl,[bx]");
									addtxtbody("	mov bx,dx");
									addtxtbody("	xor ch,ch");
									addtxtbody("	cs");
									addtxtbody("	mov [bx],cx");
									addtxtbody("	mov ah,0xa");
									addtxtbody("	int 0x21");
									addtxtbody("	mov bx,L50");
									addtxtbody("	inc bx");
									addtxtbody("	mov si,bx");
									addtxtbody("	mov ax,cs");
									addtxtbody("	call MEM32");
									addtxtbody("	mov esi,eax");
									addtxtbody("	xor ecx,ecx");
									addtxtbody("	cs");
									addtxtbody("	mov cl,[bx]");
									addtxtbody("	push ecx");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov edi,[bx]");
									addtxtbody("	inc esi");
									addtxtbody("	mov edx,1");
									addtxtbody("	call COPYMEM32");
									addtxtbody("	pop ecx");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									addtxtbody("	mov bp,0");
									addtxtbody("	mov ds,bp");
									addtxtbody("	mov al,0");
									addtxtbody("	add esi,ecx");
									addtxtbody("	mov [esi],al");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov ds,ax");




		}
		return 0;
}

//=================================================================

int vals(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	char *ss1;
	if(3==count){

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

									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	mov di,bx");
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									addtxtbody("	call val");



		}
		return 0;
}

//=================================================================

int floatconsts(){
	int i;
	int n;
	char *ss1;
	char *ss2;
	long l;
	double dff=0.00;
	if(paramets[69]<=count){
		error=0;
		for (n=0;n<count-1;n++){
			ss1=uppercase(ss[n+1]);
			i=findvar(ss1);
			if (i==-1){
				addvar (ss1);
				i=findvar(ss1);
			}else{
				printf("var:%s\n",ss1);
				error=1;
			}
			dff=atof(ss1);
			dff=dff*100;
			l=(long) dff;
			fprintf(f1,"varnext%d dd %lu\n",varnext,l);
			varnext++;
		}
	}
	return 0;
}

//=================================================================

int doubleconsts(){
	int i;
	int n;
	char *ss1;
	char *ss2;
	long l;
	double dff=0.00;
	if(paramets[69]<=count){
		error=0;
		for (n=0;n<count-1;n++){
			ss1=uppercase(ss[n+1]);
			i=findvar(ss1);
			if (i==-1){
				addvar (ss1);
				i=findvar(ss1);
			}else{
				printf("var:%s\n",ss1);
				error=1;
			}
			dff=atof(ss1);
			dff=dff*10000;
			l=(long) dff;
			fprintf(f1,"varnext%d dd %lu\n",varnext,l);
			varnext++;
		}
	}
	return 0;
}

//=================================================================

int booleanlike(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(4==count){

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
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ecx,[bx]");
									addtxtbody("	mov edx,0");
									addtxtbody("	cmp eax,ecx");
									fprintf(f2,"	jnz linenumber%d\n",lineno);
									addtxtbody("	mov edx,1");
									fprintf(f2,"	linenumber%d:\n",lineno);
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],edx");

		}
		return 0;
}

//=================================================================

//=================================================================

int booleandiferent(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(4==count){

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
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ecx,[bx]");
									addtxtbody("	mov edx,0");
									addtxtbody("	cmp eax,ecx");
									fprintf(f2,"	jz linenumber%d\n",lineno);
									addtxtbody("	mov edx,1");
									fprintf(f2,"	linenumber%d:\n",lineno);
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],edx");

		}
		return 0;
}

//=================================================================

int ors(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(4==count){

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
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ecx,[bx]");
									addtxtbody("	or eax,ecx");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],eax");

		}
		return 0;
}

//=================================================================

//=================================================================

int booleanbig(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(4==count){

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
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ecx,[bx]");
									addtxtbody("	mov edx,0");
									addtxtbody("	cmp eax,ecx");
									fprintf(f2,"	jbe linenumber%d\n",lineno);
									addtxtbody("	mov edx,1");
									fprintf(f2,"	linenumber%d:\n",lineno);
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],edx");

		}
		return 0;
}

//=================================================================

int booleanless(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(4==count){

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
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ecx,[bx]");
									addtxtbody("	mov edx,0");
									addtxtbody("	cmp eax,ecx");
									fprintf(f2,"	jae linenumber%d\n",lineno);
									addtxtbody("	mov edx,1");
									fprintf(f2,"	linenumber%d:\n",lineno);
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],edx");

		}
		return 0;
}

//=================================================================
//=================================================================

int notss(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(3==count){

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

									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[bx]");
									addtxtbody("	not eax");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],eax");

		}
		return 0;
}

//=================================================================


//=================================================================

int bbooleanb(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(3==count){

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

									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[bx]");
									addtxtbody("	mov edx,0");
									addtxtbody("	cmp eax,0");
									fprintf(f2,"	jz linenumber%d\n",lineno);
									addtxtbody("	mov edx,1");
									fprintf(f2,"	linenumber%d:\n",lineno);
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],edx");

		}
		return 0;
}


//=================================================================

int filecreat(){
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



									fprintf(f2,"	mov dx,varnext%d\n",i1+varnextstart);
									addtxtbody("	mov ah,0x3c");
									addtxtbody("	mov cx,0");
									addtxtbody("	int 0x21");




		}
		return 0;
}


//=================================================================

//=================================================================

int fileopen(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(3==count){

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


									fprintf(f2,"	mov dx,varnext%d\n",i2+varnextstart);
									addtxtbody("	mov ah,0x3d");
									addtxtbody("	mov al,2");
									addtxtbody("	int 0x21");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	xor edx,edx");
									addtxtbody("	mov dx,ax");
									addtxtbody("	mov [bx],edx");




		}
		return 0;
}


//=================================================================

//=================================================================

int fileclose(){
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
									addtxtbody("	mov ax,[bx]");
									addtxtbody("	mov bx,ax");
									addtxtbody("	mov al,2");
									addtxtbody("	mov ah,0x3e");
									addtxtbody("	int 0x21");



		}
		return 0;
}


//=================================================================

//=================================================================

int filewrite(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(4==count){

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



									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	mov esi,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i3+varnextstart);
									addtxtbody("	mov ecx,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	mov ax,[bx]");
									addtxtbody("	mov di,ax");
									addtxtbody("	call WRITE32");






		}
		return 0;
}


//=================================================================

int fileread(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(4==count){

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





									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	mov esi,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i3+varnextstart);
									addtxtbody("	mov ecx,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	mov ax,[bx]");
									addtxtbody("	mov di,ax");
									addtxtbody("	call READ32");





		}
		return 0;
}


//=================================================================













//=================================================================

int nosound(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(1==count){

		error=0;



									addtxtbody("	call nosound");



		}
		return 0;
}


//=================================================================

//=================================================================

//=================================================================

int sound(){
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
									addtxtbody("	mov eax,[bx]");
									addtxtbody("	call sound");




		}
		return 0;
}


//=================================================================

//=================================================================

//=================================================================

int beeps(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(1==count){

		error=0;



									addtxtbody("	mov eax,750");
									addtxtbody("	call sound");
									addtxtbody("	mov eax,8");
									addtxtbody("	call sleep");
									addtxtbody("	call nosound");




		}
		return 0;
}


//=================================================================
//=================================================================

int stringlow(){
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
									addtxtbody("	mov esi,[bx]");
									addtxtbody("	mov ax,0");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									addtxtbody("	call memlen");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									addtxtbody("	mov ax,0");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									addtxtbody("	call memlower");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");






		}
		return 0;
}


//=================================================================

//=================================================================

int stringhigh(){
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
									addtxtbody("	mov esi,[bx]");
									addtxtbody("	mov ax,0");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									addtxtbody("	call memlen");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									addtxtbody("	mov ax,0");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									addtxtbody("	call memhigth");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");






		}
		return 0;
}


//=================================================================

//=================================================================

//=================================================================

int findchar(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(4==count){

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





									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									addtxtbody("	mov ax,0");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									addtxtbody("	call memlen");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov al,[bx]");
									addtxtbody("	mov bp,0");
									addtxtbody("	mov es,bp");
									addtxtbody("	mov ds,bp");
									addtxtbody("	call findchr");
									addtxtbody("	mov ecx,eax");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],ecx");





		}
		return 0;
}


//=================================================================


//=================================================================

int stringcmp(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(4==count){

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





									fprintf(f2,"	mov bx,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									addtxtbody("	mov ax,0");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									addtxtbody("	call memlen");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov edi,[bx]");
									addtxtbody("	mov bp,0");
									addtxtbody("	mov es,bp");
									addtxtbody("	mov ds,bp");
									addtxtbody("	call comps");
									addtxtbody("	mov ecx,eax");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],ecx");




		}
		return 0;
}


//=================================================================


//=================================================================

int findstr(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(4==count){

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





									fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov esi,[bx]");
									fprintf(f2,"	mov bx,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov edi,[bx]");
									addtxtbody("	mov bp,0");
									addtxtbody("	mov es,bp");
									addtxtbody("	mov ds,bp");
									addtxtbody("	call findstr");
									addtxtbody("	mov ecx,eax");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov es,ax");
									addtxtbody("	mov ds,ax");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],ecx");





		}
		return 0;
}


//=================================================================

