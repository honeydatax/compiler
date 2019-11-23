
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define textsize 900000
#define nlines 12000

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
int count;
int tindex=0;
char s[textsize];
char *ss[500];
int count2=0;
char *i[1024];
char *ii[50];
char *iii[1024];
char var2[]=";";
void readll(char *argv1);
int ccount=0;
void msgbox();
void head();
int register_var(char *argv1 );
void tail();
void body(int c);
void pprint(int n);
void addcode(char *s1);
char *uppercase(char *s);
void addkey(char *sss,int func);
int findkey(char *s);
int echos();
void addtxtbody(char *s);
void addtxtbodynx(char *s);
void addtxtbodynb(int n);
void addvar(char *sss);
int findvar(char *s);
int declair(char *s);
int iinteger(char *s);
int function(char *s);
int callfunction(char *s);
int locate();
int color();
int add();
int sub();
int consts();
int printnumber();
int pointers();
int pointersto();
int pointersfrom();
int ford();
int dowhile();
int dodo();
int like();
int diferent();
int big();
int less();
int inside();
int outside();
int rem();
int sstring();
int memory();
int fillmmem();
int copymem();
int printstring();
int sets();
int timerrnd();
int ands();
int inkeys();
int sleeps();
int divs();
int muls();
int getnumbers();
int doloops();
int lets();
int evals();
void evalsubs(int d0,int d1,int d2);
void evalsums(int d0,int d1,int d2);
void evalmuls(int d0,int d1,int d2);
void evaldivs(int d0,int d1,int d2);
void evalclears(int p1,int size);
int evalssplint(char *destiny,char *list[],char separete);
int PrintList(int sizes);
void priorityString(int sizes);
void priorityList(int sizes);
int strchr1(char *argv);
int evalgetnumbers(char *s1);
int getvar(char *s1);
void priorityList(int sizes);
int lists(char *argv);
int solver(char *argv);
void params(char *argv);
void emain(char *argv);
int ddouble(char *s);
int returneval;
int ffloat(char *s);
int printfloat();
int tinteger();
int tfloat();
int tdouble();
int printdouble();
FILE *f1;
FILE *f2;
FILE *f3;

//=================================================================
//MAIN
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
		fprintf(f2,"\nmain:\n");
		f3=f2;
		page=0;
		lineno=0;
		eerror=0;
		mainsub=0;
		do{
			if (!feof(stdin)){
				lineno++;
				fgets(c,800,stdin);
				dd=strstr(c,"\n");
				if (dd!=NULL) dd[0]=0;
				readll(c);	
			}
			c[0]=0;
		}while(!feof(stdin));
		tail();
		fclose(f1);
		fclose(f2);
		if (eerror==1) {
			printf("fail to compile error\n");
		}else{
			eerror=0;
			system("nasm -o out.com index.dat 2> indexx.dat");
			f1=fopen("indexx.dat","r");
			do{
				if (!feof(f1)){
					lineno++;
					fgets(c,800,f1);
					dd=strstr(c,"sub");
					if (dd!=NULL){
						dd=dd+3;
						i=atoi(dd);
						printf("function declare not exists you are call a function not creat \"%s\"\n", subs[i]);
						eerror=1;		
						c[0]=0;
					}
					printf("%s\n",c);
					
				}
				c[0]=0;
			}while(!feof(stdin));
			fclose(f1);
			if(eerror==0) printf("\ndone...\nopen file index.dat and index1.dat to see codes\n");
		}
return 0;
}

//=================================================================
//READLL
void readll(char *argv1){
	char *s1;
	char *s2;
	int r;
	count=0;
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
	s1=uppercase(ss[0]);
	ss[0]=s1;
	n=findkey(ss[0]);
	error=1;
	if (n==0) printstring();
	if (n==1) sets();
	if (n==2) error=0;
	if (n==3) echos();
	if (n==5) iinteger(ss[1]);
	if (n==6) lets();
	if (n==7) add();
	if (n==8) sub();
	if (n==13) like();
	if (n==14) diferent();
	if (n==15) big();
	if (n==16) less();
	if (n==19) fillmmem();
	if (n==20) copymem();
	if (n==21) sstring();
	if (n==29) ford();
	if (n==31) pointers();
	if (n==35) getnumbers();
	if (n==36) printnumber();
	if (n==39) muls();
	if (n==40) divs();
	if (n==50) sleeps();
	if (n==51) timerrnd();
	if (n==55) ands();
	if (n==66 || n==17) rem();
	if (n==68) inkeys();
	if (n==69) consts();
	if (n==70) locate();
	if (n==74) ffloat(ss[1]);
	if (n==82) memory();
	if (n==84) color();
	if (n==93) declair(ss[1]);
	if (n==94) function(ss[1]);
	if (n==95) pointersto();
	if (n==96) pointersfrom();
	if (n==97) dowhile();
	if (n==98) dodo();
	if (n==99) inside();
	if (n==100) outside();
	if (n==101) doloops();
	if (n==102) evals();
	if (n==103) printfloat();
	if (n==104) tinteger();
	if (n==105) tfloat();
	if (n==106) ddouble(ss[1]);
	if (n==107) tdouble();
	if (n==108) printdouble();
	if (n>=substart) callfunction(ss[0]);
	//printf("**%d\n",n);
	if (error==1){
		printf("line error:%d\n",lineno);
		eerror=1;
	}

	
}

//=================================================================
//register_var
int register_var(char *argv1 ){
	int i=ccount;
	int nn=strlen(argv1);
	nn=nn & 255;
	fprintf (f1,"var%d db  %d,\"%s\",13,10,0 \n",ccount,nn,argv1);
	ccount++;
	return i;
}

//=================================================================
//pprint
void pprint(int n){
		body(n);
		page++;
		if (page>19){
			page=0;
			fprintf(f2,"\ncall key\n",c);
		}

}

//=================================================================
//body
void body(int c){
	fprintf(f2,"\nmov dx,var%d\ncall echos\n",c);
}

//=================================================================
//tail
void tail(){
	fprintf(f2,"\nret\n");
	fprintf(f2,"\nret\n");
	fprintf(f1,"endf db 0\n");
	
}

//=================================================================
//msgbox()
void msgbox(){
	printf ("\e[0;37;40m");
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
//head()
void head(){
			//by line sky lib gnu (c)
			addcode ("section .text");
			addcode ("org 0x100");
			addcode ("main1:");
			addcode ("jmp start");
			addcode ("db 'build in index32 developer tools.... '");
			addcode ("%include \"index1.dat\"");
			addcode ("mains:");
			addcode ("call main");
			addcode ("");
			addcode (";body start");
			addcode ("");
			addcode (";end of body");
			addcode ("exit:");
			addcode ("      mov si,rreservemem");
			addcode ("      mov eax,[si]");
			addcode ("	mov ax,0");
			addcode ("	mov ds,ax");
			addcode ("      mov ebx,180004h"); 
			addcode ("      mov [ebx],eax");
			addcode ("	mov ax,cs");
			addcode ("	mov ds,ax");
			addcode ("	mov ax,0ffffh");
			addcode ("	mov sp,ax");
			addcode ("	mov ax,cs");
			addcode ("	mov ss,ax");
			addcode ("	xor ax,ax");
			addcode ("	push ax");
			addcode ("	xor ax,ax");
			addcode ("	int 0x21");
			addcode ("	ret");
			addcode ("ret");
			addcode ("len32:");
			addcode ("          push ebx                ");
			addcode ("          push ecx                ");
			addcode ("          push edx                ");
			addcode ("          push esi                ");
			addcode ("          push edi                ");
			addcode ("          push ebp                ");
			addcode ("          push ds                ");
			addcode ("          mov bp,0                ");
			addcode ("          mov ds,bp");
			addcode ("	    mov ecx,0");
			addcode ("len321:");
			addcode ("	    ds");
			addcode ("	    mov al,[esi]");
			addcode ("	    cmp al,0");
			addcode ("	    jz len323");
			addcode ("	    inc esi");
			addcode ("	    inc ecx");
			addcode ("	    jmp len321");
			addcode ("len323:");				
			addcode ("		mov eax,ecx");				
			addcode ("                    pop ds          ");      
			addcode ("                    pop ebp         ");       
			addcode ("                    pop edi         ");       
			addcode ("                    pop esi         ");       
			addcode ("                    pop edx         ");       
			addcode ("                    pop ecx         ");        
			addcode ("                    pop ebx         ");       
			addcode ("	ret");
			addcode ("ret");
			addcode ("strcat:");
			addcode ("	mov ax,0");
			addcode ("	mov ds,ax");
			addcode ("	mov ah,0");
			addcode ("strcat2:");
			addcode ("	mov al,[edi]");
			addcode ("	cmp al,ah");
			addcode ("	jz strcat3");
			addcode ("	inc edi");
			addcode ("	jmp strcat2");
			addcode ("strcat3:");
			addcode ("	mov al,[esi]");
			addcode ("	mov [edi],al");
			addcode ("	cmp al,ah");
			addcode ("	jz strcat4");
			addcode ("	inc esi");
			addcode ("	inc edi");
			addcode ("	jmp strcat3");
			addcode ("strcat4:");
			addcode ("	mov ax,cs");
			addcode ("	mov ds,ax");
			addcode ("	ret");
			addcode ("COPYMEM32:");
			addcode ("          push eax                ");
			addcode ("          push ebx                ");
			addcode ("          push ecx                ");
			addcode ("          push edx                ");
			addcode ("          push esi                ");
			addcode ("          push edi                ");
			addcode ("          push ebp                ");
			addcode ("          push ds                ");
			addcode ("          mov bp,0                ");
			addcode ("          mov ds,bp");
			addcode ("          cmp edx,0");
			addcode ("          JZ COPYMEM326");
			addcode ("          COPYMEM3211:");
			addcode ("          cmp ecx,0");
			addcode ("          JZ COPYMEM326");
			addcode ("          COPYMEM321:");
			addcode ("                    ds");
			addcode ("                    mov al,[esi]");
			addcode ("                    ds");
			addcode ("                    mov [edi],al");
			addcode ("                    clc             ");   
			addcode ("                    add edi,edx");
			addcode ("                    inc esi         ");       
			addcode ("                    dec ecx         ");       
			addcode ("                    jnz COPYMEM321");
			addcode ("                    COPYMEM326:");
			addcode ("                    pop ds          ");      
			addcode ("                    pop ebp         ");       
			addcode ("                    pop edi         ");       
			addcode ("                    pop esi         ");       
			addcode ("                    pop edx         ");       
			addcode ("                    pop ecx         ");        
			addcode ("                    pop ebx         ");       
			addcode ("                    pop eax         ");       
			addcode ("                    RET             ");   
			addcode ("MEM32:                ");
			addcode ("          push esi                ");
			addcode ("          and eax,0ffffh");
			addcode ("          clc                ");
			addcode ("          shl eax,4");
			addcode ("          and esi,0ffffh");
			addcode ("          clc                 ");
			addcode ("          add eax,esi");
			addcode ("          pop esi                ");
			addcode ("          RET                ");
			addcode ("MOVEMEM32:");
			addcode ("          push eax                ");
			addcode ("          push ebx                ");
			addcode ("          push ecx                ");
			addcode ("          push edx                ");
			addcode ("          push esi                ");
			addcode ("          push edi                ");
			addcode ("          push ebp                ");
			addcode ("          push ds                ");
			addcode ("          mov bp,0                ");
			addcode ("          mov ds,bp");
			addcode ("          MOVEMEM3211:");
			addcode ("          cmp ecx,0");
			addcode ("          JZ MOVEMEM326");
			addcode ("          MOVEMEM321:");
			addcode ("                    ds");
			addcode ("                    mov al,[esi]");
			addcode ("                    ds");
			addcode ("                    mov [edi],al");
			addcode ("                    dec edi");
			addcode ("                    dec esi         ");       
			addcode ("                    dec ecx         ");       
			addcode ("                    jnz MOVEMEM321");
			addcode ("                    MOVEMEM326:");
			addcode ("                    pop ds          ");      
			addcode ("                    pop ebp         ");       
			addcode ("                    pop edi         ");       
			addcode ("                    pop esi         ");       
			addcode ("                    pop edx         ");       
			addcode ("                    pop ecx         ");        
			addcode ("                    pop ebx         ");       
			addcode ("                    pop eax         ");       
			addcode ("                    RET             ");   
			addcode ("GOTOXY:                ");
			addcode ("          push ebx                ");
			addcode ("          push ecx                ");
			addcode ("          push edx                ");
			addcode ("          push esi                ");
			addcode ("          push edi                ");
			addcode ("          push ebp                ");
			addcode ("          mov si,ax");
			addcode ("          mov di,bx");
			addcode ("          and si,0fffh");
			addcode ("          and di,0fffh");
			addcode ("          xor cx,cx");
			addcode ("          xor dx,dx");
			addcode ("          mov ax,si");
			addcode ("          mov bx,2                ");
			addcode ("          clc                ");
			addcode ("          mul bx                ");
			addcode ("          mov si,ax");
			addcode ("          mov ax,di");
			addcode ("          mov bx,160");
			addcode ("          clc                ");
			addcode ("          mul bx                ");
			addcode ("          mov bx,si");
			addcode ("          clc                ");
			addcode ("          add ax,bx");
			addcode ("          and eax,0ffffh");
			addcode ("          mov ebx,0b8000h");
			addcode ("          clc                ");
			addcode ("          add eax,ebx");
			addcode ("          pop ebp                ");
			addcode ("          pop edi                ");
			addcode ("          pop esi                ");
			addcode ("          pop edx                ");
			addcode ("          pop ecx                 ");
			addcode ("          pop ebx                ");
			addcode ("          RET                ");
			addcode ("PRINT32:                ");
			addcode ("          push eax             ");   
			addcode ("          push ebx             ");   
			addcode ("          push ecx             ");   
			addcode ("          push edx             ");   
			addcode ("          push esi             ");   
			addcode ("          push edi             ");   
			addcode ("          push ebp             ");   
			addcode ("          cmp ecx,0");
			addcode ("          JZ PRINT3213");
			addcode ("          push esi             ");   
			addcode ("          mov si,x             ");   
			addcode ("          cs             ");   
			addcode ("          mov al,[si]             ");   
			addcode ("          cs             ");   
			addcode ("          mov bl,[si+1]             ");   
			addcode ("          pop esi             ");
   			addcode ("          and ax,0ffh");
			addcode ("          and bx,0ffh");
			addcode ("          call GOTOXY");
			addcode ("          mov edi,eax");
			addcode ("          cmp ecx,255");
			addcode ("          JB PRINT3212");
			addcode ("          mov ebx,255");
			addcode ("          PRINT3212:");
			addcode ("          mov edx,2");
			addcode ("          call COPYMEM32");
			addcode ("          push esi             ");   
			addcode ("          mov si,x             ");   
			addcode ("          cs             ");   				
			addcode ("          mov al,[si]          ");
			addcode ("          cs             ");   				   
			addcode ("          mov bl,[si+1]        ");   
			addcode ("          pop esi             ");   
			addcode ("          and ax,0ffh");
			addcode ("          and bx,0ffh");
			addcode ("          mov si,bx");
			addcode ("          clc                ");
			addcode ("			");
			addcode ("          add ax,cx");
			addcode ("          cmp ax,80");
			addcode ("          JB PRINT328");
			addcode ("          mov bx,80");
			addcode ("          sub ax,bx");
			addcode ("          xor dx,dx");
			addcode ("          xor cx,cx");
			addcode ("          mov bx,80");
			addcode ("          clc                ");
			addcode ("          div bx               "); 
			addcode ("          clc                ");
			addcode ("          add ax,si");
			addcode ("          cmp ax,24");
			addcode ("          JB PRINT328");
			addcode ("          mov ax,24");
			addcode ("          PRINT328:");
			addcode ("          push esi             ");   
			addcode ("          mov si,x             ");   
			addcode ("          cs             ");   				
			addcode ("          mov al,[si+1]        ");   
			addcode ("          inc al        ");   
			addcode ("          cs             ");   				
			addcode ("          mov [si+1],al        ");   
			addcode ("          mov al,0        ");   
			addcode ("          cs             ");   				
			addcode ("          mov [si],al ");
			addcode ("          pop esi             ");   
			addcode ("          PRINT3213:");
			addcode ("          pop ebp              ");  
			addcode ("          pop edi              ");  
			addcode ("          pop esi              ");  
			addcode ("          pop edx              ");  
			addcode ("          pop ecx              ");   
			addcode ("          pop ebx              ");  
			addcode ("          pop eax              ");  
			addcode ("          RET                ");
			addcode ("timer:");
			addcode ("	push ebx");
			addcode ("	push ds");
			addcode ("	mov ax,0x40");
			addcode ("	mov ds,ax");
			addcode ("	mov bx,0x6c");
			addcode ("	mov eax,[bx]");
			addcode ("	pop ds");
			addcode ("	pop ebx");
			addcode ("ret");
			addcode ("sleep:");
			addcode ("	mov ecx,eax");
			addcode ("	xor eax,eax");
			addcode ("	cmp eax,ecx");
			addcode ("	jz sleep6");
			addcode ("	call timer");
			addcode ("	clc");
			addcode ("	add ecx,eax");
			addcode ("	jo sleep8");
			addcode ("	call timer");
			addcode ("	cmp eax,ecx");
			addcode ("	jz sleep6");
			addcode ("	sleep1:");
			addcode ("		call timer");
			addcode ("		cmp eax,ecx");
			addcode ("		jz sleep6");
			addcode ("		jb sleep1");
			addcode ("	jmp sleep6");
			addcode ("	sleep8:");
			addcode ("	sleep5:");
			addcode ("		call timer");
			addcode ("		cmp eax,ecx");
			addcode ("		jz sleep6");
			addcode ("		ja sleep5");
			addcode ("	jmp sleep1");
			addcode ("sleep6:");
			addcode ("ret");
			addcode ("inkey:");
			addcode ("	mov ah,0x1");
			addcode ("	int 0x16");
			addcode ("	jnz waits");
			addcode ("nwaits:");
			addcode ("	xor ax,ax");
			addcode ("	ret");
			addcode ("waits:");
			addcode ("	xor ax,ax");
			addcode ("	int 0x16");
			addcode ("	xor cl,cl");
			addcode ("	mov ah,cl");
			addcode ("	ret");
	               	addcode ("echo:");
			addcode ("          push ax");
			addcode ("          push bx");              
			addcode ("          push cx");                
			addcode ("          push dx");                
			addcode ("          push di");                
			addcode ("          push si");                
			addcode ("          push bp");                
			addcode ("          push es");                
			addcode ("          mov ax,cs");
			addcode ("          mov es,ax");
			addcode ("          xchg si,bp"); 
			addcode ("          mov bx,bp");
			addcode ("          cs");
			addcode ("          mov cl,[bx]");
			addcode ("          inc bp");                
			addcode ("          and cx,0ffh");
			addcode ("          mov bx,x");
			addcode ("          cs");
			addcode ("          mov dx,[bx]");
			addcode ("          mov bx,color");
			addcode ("          cs");
			addcode ("          mov al,[bx]");
			addcode ("          mov bl,al");
			addcode ("          mov bh,0");   
			addcode ("          mov al,0");                
			addcode ("          mov ah,13h");
			addcode ("          int 10h");                
			addcode ("          pop es");                
			addcode ("          pop bp");                
			addcode ("          pop si");                
			addcode ("          pop di");                
			addcode ("          pop dx");                
			addcode ("          pop cx");                
			addcode ("          pop bx");                
			addcode ("          pop ax");                
			addcode ("          RET");   
			addcode ("val:");
			addcode ("		mov ax,0");
			addcode ("		mov ds,ax");
			addcode ("		mov ecx,0");
			addcode ("		mov edx,0");
			addcode ("		mov ebx,1");
			addcode ("		mov eax,0");
			addcode ("val2:");
			addcode ("		mov al,[esi]");
			addcode ("		cmp al,48");
			addcode ("		jb val3");
			addcode ("		cmp al,57");
			addcode ("		ja val3");
			addcode ("		jmp val4");
			addcode ("val3:");
			addcode ("		cmp cl,0");
			addcode ("		jz val40");
			addcode ("		jmp val5");
			addcode ("val4:");
			addcode ("		cmp cl,9");
			addcode ("		jz val55");
			addcode ("		inc cl");
			addcode ("		inc esi");
			addcode ("		jmp val2");
			addcode ("val55:");
			addcode ("		dec cl");
			addcode ("val5:");
			addcode ("		dec esi");
			addcode ("val6:");
			addcode ("		push ecx");
			addcode ("		push edx");
			addcode ("		xor eax,eax");
			addcode ("		mov al,[esi]");
			addcode ("		clc");
			addcode ("		sub al,48");
			addcode ("		xor ecx,ecx");
			addcode ("		xor edx,edx");
			addcode ("		push ebx");
			addcode ("		imul ebx");
			addcode ("		xor ecx,ecx");
			addcode ("		xor edx,edx");
			addcode ("		pop ebx");
			addcode ("		push eax");
			addcode ("		mov eax,10");
			addcode ("		imul ebx");
			addcode ("		mov ebx,eax");
			addcode ("		pop eax");
			addcode ("		pop edx");
			addcode ("		pop ecx");
			addcode ("		clc");
			addcode ("		add edx,eax");
			addcode ("		dec esi");
			addcode ("		dec cl");
			addcode ("		cmp cl,0");
			addcode ("		jz val40");
			addcode ("		jmp val6");
			addcode ("val40:");
			addcode ("		mov eax,edx");
			addcode ("		mov bp,cs");
			addcode ("		mov ds,bp");
			addcode ("		mov [di],eax");
			addcode ("ret");
			addcode ("STR32:     ");           
			addcode ("        push eax                ");
			addcode ("        push ebx                ");
			addcode ("        push ecx                ");
			addcode ("        push edx                ");
			addcode ("        push edi                ");
			addcode ("        push esi                ");
			addcode ("        push ebp                ");
			addcode ("        push ds                ");
			addcode ("        mov eax,[si]");
			addcode ("        mov ebp,0");			
			addcode ("        mov ds,bp                ");
			addcode ("        mov ebp,1000000000");
			addcode ("        STR321:                ");
			addcode ("                  xor edx,edx");
			addcode ("                  xor ecx,ecx");
			addcode ("                  mov ebx,ebp");
			addcode ("                  clc            ");     
			addcode ("                  div ebx        ");        
			addcode ("                  mov esi,edx");
			addcode ("                  mov ah,'0'");
			addcode ("                  clc            ");    
			addcode ("                  add al,ah");
			addcode ("                  mov [edi],al");
			addcode ("                  inc edi         ");       
			addcode ("                  mov eax,ebp");
			addcode ("                  xor edx,edx");
			addcode ("                  xor ecx,ecx");
			addcode ("                  mov ebx,10");
			addcode ("                  clc            ");    
			addcode ("                  div ebx        ");        
			addcode ("                  mov ebp,eax");
			addcode ("                  mov eax,esi");
			addcode ("                  cmp ebp,0");
			addcode ("                  JNZ STR321");
			addcode ("                          ");
			addcode ("          pop ds                ");
			addcode ("          pop ebp                ");
			addcode ("          pop esi                ");
			addcode ("          pop edi                ");
			addcode ("          pop edx                ");
			addcode ("          pop ecx                ");
			addcode ("          pop ebx                ");
			addcode ("          pop eax                ");
			addcode ("          RET          ");
			addcode ("start:");
			addcode ("		;start stack 64k");
			addcode ("	mov ax,cs");
			addcode ("	mov cx,0x1000");
			addcode ("	add ax,cx");
			addcode ("	mov ss,ax");
			addcode ("	mov ax,0xffff");
			addcode ("	mov sp,ax");
			addcode ("	xor ax,ax");
			addcode ("	push ax");
			addcode ("		;end stack 64k");
			addcode ("		;start alocate");
			addcode ("	mov bx,L18");
			addcode ("	mov ax,endf");
			addcode ("	mov cx,8");
			addcode ("	add ax,cx");
			addcode ("	mov [bx],ax");
			addcode ("		;end alocate");
			addcode ("		;start randomize");
			addcode ("	call timer");
			addcode ("	mov bx,L20");
			addcode ("	xor cx,cx");
			addcode ("	mov cl,al");
			addcode ("	mov ax,257");
			addcode ("	add ax,cx");
			addcode ("	mov [bx],ax");
			addcode ("		;end randomize");
			addcode ("      xor ax,ax");
			addcode ("      mov ds,ax");
			addcode ("      mov edx,1234567890");
			addcode ("      mov ebx,180000h"); 
			addcode ("      mov eax,[ebx]");
			addcode ("      cmp eax,edx");
			addcode ("      jz reservemem");
			addcode ("      mov eax,4");
			addcode ("      clc");
			addcode ("      add ebx,eax");
			addcode ("      mov eax,100h");
			addcode ("      clc");                
			addcode ("      add eax,ebx");
			addcode ("      mov [ebx],eax");
			addcode ("      mov eax,1234567890");
			addcode ("      mov ebx,180000h"); 
			addcode ("      mov [ebx],eax");
			addcode ("reservemem:");
			addcode ("      mov ebx,180004h"); 
			addcode ("      mov eax,[ebx]");
			addcode ("      mov si,rreservemem");
			addcode ("      cs");
			addcode ("      mov [si],eax");
			addcode ("      mov ax,cs");
			addcode ("      mov ds,ax");
			addcode ("");
			addcode ("jmp mains");
			addcode ("RESERVES:");
			addcode ("          push ebx");
			addcode ("          push ecx");                
			addcode ("          push edx");                
			addcode ("          push edi");                
			addcode ("          push esi");                
			addcode ("          push ebp");                
			addcode ("          push ds ");               
			addcode ("          push es ");               
			addcode ("          JMP RESERVES2");
			addcode ("          RESERVES2:");
			addcode ("          xor ax,ax");
			addcode ("          mov ds,ax");
			addcode ("          mov ebx,180004h");
			addcode ("          mov eax,[ebx]");
			addcode ("");
			addcode ("          mov edx,eax");
			addcode ("          clc               "); 
			addcode ("          add edx,ecx");
			addcode ("          add edx,4");
			addcode ("          mov [ebx],edx");
			addcode ("          mov ebx,eax");
			addcode ("          mov esi,eax");
			addcode ("          mov [ebx],ecx");
			addcode ("          mov eax,esi");
			addcode ("          clc");
			addcode ("          add eax,4");
			addcode ("          clc");
			addcode ("          add eax,ecx");
			addcode ("          dec eax");
			addcode ("          mov ebx,eax");
			addcode ("          mov al,0");
			addcode ("          mov [ebx],al");
			addcode ("          mov eax,esi");
			addcode ("          clc");
			addcode ("          add eax,4");
			addcode ("          pop es");                
			addcode ("          pop ds");                
			addcode ("          pop ebp");                
			addcode ("          pop esi");                
			addcode ("          pop edi");                
			addcode ("          pop edx");                
			addcode ("          pop ecx");                
			addcode ("          pop ebx");                
			addcode ("                   ");       
			addcode ("          RET     ");           
			addcode ("FILL32:             ");   
			addcode ("          push eax  ");              
			addcode ("          push ebx  ");              
			addcode ("          push ecx  ");              
			addcode ("          push edx  ");              
			addcode ("          push esi  ");              
			addcode ("          push edi  ");              
			addcode ("          push ebp  ");              
			addcode ("          push ds   ");             
			addcode ("          mov bp,0  ");              
			addcode ("          mov ds,bp");
			addcode ("          cmp edx,0");
			addcode ("          JNZ FILL3211");
			addcode ("          inc edx       ");         
			addcode ("          FILL3211:");
			addcode ("          FILL321:      ");          
			addcode ("                    mov [edi],al");
			addcode ("                    clc ");               
			addcode ("                    add edi,edx");
			addcode ("                    dec ecx      ");          
			addcode ("                    JNZ FILL321");
			addcode ("          pop ds                ");
			addcode ("          pop ebp                ");
			addcode ("          pop edi                ");
			addcode ("          pop esi                ");
			addcode ("          pop edx                ");
			addcode ("          pop ecx                "); 
			addcode ("          pop ebx                ");
			addcode ("          pop eax                ");
			addcode ("          RET                ");
			addcode ("scr:");
			addcode ("	mov ebx,255");
			addcode ("	cmp eax,ebx");
			addcode ("	ja scr1");
			addcode ("	mov ah,0");
			addcode ("	int 10h");
			addcode ("	ret");
			addcode ("scr1:");
			addcode ("	mov bx,ax");
			addcode ("	mov ax,4f02h");
			addcode ("	int 10h");
			addcode ("	ret");
			addcode ("setvideo:");
			addcode ("	push ds");
			addcode ("	push es");
			addcode ("	mov dx,0");
			addcode ("	mov esi,140000h");
			addcode ("	mov ds,dx");
			addcode ("	mov es,dx");
			addcode ("setvideo2:");
			addcode ("	mov ax,4f05h");
			addcode ("	mov bx,0");
			addcode ("	int 10h");
			addcode ("	inc dx");
			addcode ("setvideo3:");
			addcode ("	mov edi,0a0000h");
			addcode ("	mov ecx,4000h");
			addcode ("	call memcopyd");
			addcode ("	cmp dx,4");
			addcode ("	jb setvideo2");
			addcode ("	pop es");
			addcode ("	pop ds");
			addcode ("	ret");
			addcode ("hline32:");
			addcode ("	mov si,hlinex");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,640");
			addcode ("	cmp ax,bx");
			addcode ("	jb hline32xxl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("hline32xxl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg hline32xxh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("hline32xxh:");
			addcode ("	mov si,hliney");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,400");
			addcode ("	cmp ax,bx");
			addcode ("	jb hline32yyl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("hline32yyl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg hline32yyh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("hline32yyh:");
			addcode ("	mov si,hlinex1");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,640");
			addcode ("	cmp ax,bx");
			addcode ("	jb hline32xxxl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("hline32xxxl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg hline32xxxh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("hline32xxxh:");
			addcode ("	mov si,hlinex");
			addcode ("	mov ax,[si]");
			addcode ("	mov si,hlinex1");
			addcode ("	mov bx,[si]");
			addcode ("	cmp ax,bx");
			addcode ("	ja hline32end");
			addcode ("	jz hline32end");
			addcode ("	mov si,hliney");
			addcode ("	xor eax,eax");
			addcode ("	mov ax,[si]");
			addcode ("	mov ebx,640");
			addcode ("	mov ecx,0");
			addcode ("	mov edx,0");
			addcode ("	mul ebx");
			addcode ("	mov ebx,140000h");
			addcode ("	add eax,ebx");
			addcode ("	mov si,hlinex");
			addcode ("	xor ebx,ebx");
			addcode ("	mov bx,[si]");
			addcode ("	add eax,ebx");
			addcode ("	mov edi,eax");
			addcode ("	mov si,hlinex1");
			addcode ("	xor eax,eax");
			addcode ("	mov ax,[si]");
			addcode ("	sub eax,ebx");
			addcode ("	mov ecx,eax");
			addcode ("	mov si,hlinecolor");
			addcode ("	mov al,[si]");
			addcode ("	push ds");
			addcode ("	push es");
			addcode ("	mov bp,0");
			addcode ("	mov ds,bp");
			addcode ("	mov es,bp");
			addcode ("	call memfill");
			addcode ("	pop es");
			addcode ("	pop ds");
			addcode ("hline32end:");
			addcode ("	ret");
			addcode ("vline32:");
			addcode ("	mov si,vlinex");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,640");
			addcode ("	cmp ax,bx");
			addcode ("	jb vline32xxl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("vline32xxl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg vline32xxh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("vline32xxh:");
			addcode ("	mov si,vliney");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,400");
			addcode ("	cmp ax,bx");
			addcode ("	jb vline32yyl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("vline32yyl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg vline32yyh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("vline32yyh:");
			addcode ("	mov si,vliney1");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,400");
			addcode ("	cmp ax,bx");
			addcode ("	jb vline32xxxl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("vline32xxxl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg vline32xxxh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("vline32xxxh:");
			addcode ("	mov si,vliney");
			addcode ("	mov ax,[si]");
			addcode ("	mov si,vliney1");
			addcode ("	mov bx,[si]");
			addcode ("	cmp ax,bx");
			addcode ("	ja vline32end");
			addcode ("	jz vline32end");
			addcode ("	mov si,vliney");
			addcode ("	xor eax,eax");
			addcode ("	mov ax,[si]");
			addcode ("	mov ebx,640");
			addcode ("	mov ecx,0");
			addcode ("	mov edx,0");
			addcode ("	mul ebx");
			addcode ("	mov ebx,140000h");
			addcode ("	add eax,ebx");
			addcode ("	mov si,vlinex");
			addcode ("	xor ebx,ebx");
			addcode ("	mov bx,[si]");
			addcode ("	add eax,ebx");
			addcode ("	mov edi,eax");
			addcode ("	mov si,vliney");
			addcode ("	xor ebx,ebx");
			addcode ("	mov bx,[si]");
			addcode ("	mov si,vliney1");
			addcode ("	xor eax,eax");
			addcode ("	mov ax,[si]");
			addcode ("	sub eax,ebx");
			addcode ("	mov ecx,eax");
			addcode ("	mov si,vlinecolor");
			addcode ("	mov al,[si]");
			addcode ("	push ds");
			addcode ("	push es");
			addcode ("	mov bp,0");
			addcode ("	mov ds,bp");
			addcode ("	mov es,bp");
			addcode ("	mov dx,640");
			addcode ("	call FILL32");
			addcode ("	pop es");
			addcode ("	pop ds");
			addcode ("vline32end:");
			addcode ("	ret");
			addcode ("box32:");
			addcode ("	mov si,boxx");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,640");
			addcode ("	cmp ax,bx");
			addcode ("	jb box32xxl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("box32xxl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg box32xxh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("box32xxh:");
			addcode ("	mov si,boxy");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,400");
			addcode ("	cmp ax,bx");
			addcode ("	jb box32yyl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("box32yyl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg box32yyh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("box32yyh:");
			addcode ("	mov si,boxx1");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,640");
			addcode ("	cmp ax,bx");
			addcode ("	jb box32xxxl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("box32xxxl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg box32xxxh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("box32xxxh:");
			addcode ("	mov si,boxy1");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,400");
			addcode ("	cmp ax,bx");
			addcode ("	jb box32yyyl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("box32yyyl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg box32yyyh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("box32yyyh:");
			addcode ("	mov si,boxx");
			addcode ("	mov ax,[si]");
			addcode ("	mov si,boxx1");
			addcode ("	mov bx,[si]");
			addcode ("	cmp ax,bx");
			addcode ("	ja box32end");
			addcode ("	jz box32end");
			addcode ("	mov si,boxy");
			addcode ("	mov ax,[si]");
			addcode ("	mov si,boxy1");
			addcode ("	mov bx,[si]");
			addcode ("	cmp ax,bx");
			addcode ("	ja box32end");
			addcode ("	jz box32end");
			addcode ("	mov si,boxy");
			addcode ("	mov ax,[si]");
			addcode ("	mov si,boxy1");
			addcode ("	mov bx,[si]");
			addcode ("	sub bx,ax");
			addcode ("	mov [si],bx");
			addcode ("	cmp bx,0");
			addcode ("	jz box32end");
			addcode ("	mov si,boxy");
			addcode ("	xor eax,eax");
			addcode ("	mov ax,[si]");
			addcode ("	mov ebx,640");
			addcode ("	mov ecx,0");
			addcode ("	mov edx,0");
			addcode ("	mul ebx");
			addcode ("	mov ebx,140000h");
			addcode ("	add eax,ebx");
			addcode ("	mov si,boxx");
			addcode ("	xor ebx,ebx");
			addcode ("	mov bx,[si]");
			addcode ("	add eax,ebx");
			addcode ("	mov edi,eax");
			addcode ("	mov si,boxx1");
			addcode ("	xor eax,eax");
			addcode ("	mov ax,[si]");
			addcode ("	sub eax,ebx");
			addcode ("	mov ecx,eax");
			addcode ("	mov si,boxcolor");
			addcode ("	mov al,[si]");
			addcode ("	mov edx,1");
			addcode ("	mov si,boxy1");
			addcode ("	mov bx,[si]");
			addcode ("	mov si,bx");
			addcode ("	mov ebx,640");
			addcode ("	mov bp,0");
			addcode ("	push ds");
			addcode ("	push es");
			addcode ("	mov ds,bp");
			addcode ("	mov es,bp");
			addcode ("box32loop:");
			addcode ("	push edi");
			addcode ("	push ecx");
			addcode ("	call memfill");
			addcode ("	pop ecx");
			addcode ("	pop edi");
			addcode ("	add edi,ebx");
			addcode ("	dec si");
			addcode ("	cmp si,0");
			addcode ("	jnz box32loop");
			addcode ("	pop es");
			addcode ("	pop ds");
			addcode ("box32end:");
			addcode ("	ret");
			addcode ("boxd32:");
			addcode ("	mov si,boxdx");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,640");
			addcode ("	cmp ax,bx");
			addcode ("	jb boxd32xxl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("boxd32xxl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg boxd32xxh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("boxd32xxh:");
			addcode ("	mov si,boxdy");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,400");
			addcode ("	cmp ax,bx");
			addcode ("	jb boxd32yyl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("boxd32yyl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg boxd32yyh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("boxd32yyh:");
			addcode ("	mov si,boxdx1");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,640");
			addcode ("	cmp ax,bx");
			addcode ("	jb boxd32xxxl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("boxd32xxxl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg boxd32xxxh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("boxd32xxxh:");
			addcode ("	mov si,boxdy1");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,400");
			addcode ("	cmp ax,bx");
			addcode ("	jb boxd32yyyl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("boxd32yyyl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg boxd32yyyh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("boxd32yyyh:");
			addcode ("	mov si,boxdx");
			addcode ("	mov ax,[si]");
			addcode ("	mov si,boxdx1");
			addcode ("	mov bx,[si]");
			addcode ("	cmp ax,bx");
			addcode ("	ja boxd32end");
			addcode ("	jz boxd32end");
			addcode ("	mov si,boxdy");
			addcode ("	mov ax,[si]");
			addcode ("	mov si,boxdy1");
			addcode ("	mov bx,[si]");
			addcode ("	cmp ax,bx");
			addcode ("	ja boxd32end");
			addcode ("	jz boxd32end");
			addcode ("	mov si,boxdy");
			addcode ("	mov ax,[si]");
			addcode ("	mov si,boxdy1");
			addcode ("	mov bx,[si]");
			addcode ("	sub bx,ax");
			addcode ("	mov [si],bx");
			addcode ("	cmp bx,0");
			addcode ("	jz boxd32end");
			addcode ("	mov si,boxdy");
			addcode ("	xor eax,eax");
			addcode ("	mov ax,[si]");
			addcode ("	mov ebx,640");
			addcode ("	mov ecx,0");
			addcode ("	mov edx,0");
			addcode ("	mul ebx");
			addcode ("	mov ebx,140000h");
			addcode ("	add eax,ebx");
			addcode ("	mov si,boxdx");
			addcode ("	xor ebx,ebx");
			addcode ("	mov bx,[si]");
			addcode ("	add eax,ebx");
			addcode ("	mov edi,eax");
			addcode ("	mov si,boxdx1");
			addcode ("	xor eax,eax");
			addcode ("	mov ax,[si]");
			addcode ("	sub eax,ebx");
			addcode ("	mov ecx,eax");
			addcode ("	mov si,boxdcolor");
			addcode ("	mov al,[si]");
			addcode ("	mov edx,1");
			addcode ("	mov si,boxdy1");
			addcode ("	mov bx,[si]");
			addcode ("	mov si,bx");
			addcode ("	mov ebx,640");
			addcode ("	push eax");
			addcode ("	push ebx");
			addcode ("	push edx");
			addcode ("	mov eax,ecx");
			addcode ("	mov ecx,0");
			addcode ("	mov edx,0");
			addcode ("	mov ebx,4");
			addcode ("	div ebx");
			addcode ("	mov ecx,eax");
			addcode ("	pop edx");
			addcode ("	pop ebx");
			addcode ("	pop eax");
			addcode ("	mov bp,0");
			addcode ("	push ds");
			addcode ("	push es");
			addcode ("	mov ds,bp");
			addcode ("	mov es,bp");
			addcode ("boxd32loop:");
			addcode ("	push edi");
			addcode ("	push ecx");
			addcode ("	call memfilld");
			addcode ("	pop ecx");
			addcode ("	pop edi");
			addcode ("	add edi,ebx");
			addcode ("	dec si");
			addcode ("	cmp si,0");
			addcode ("	jnz boxd32loop");
			addcode ("	pop es");
			addcode ("	pop ds");
			addcode ("boxd32end:");
			addcode ("	ret");
			addcode ("byteEAX:");
			addcode ("push ebx");
			addcode ("mov ah,al");
			addcode ("mov bx,ax");
			addcode ("shl ebx,16");
			addcode ("or eax,ebx");
			addcode ("pop ebx");	
			addcode ("ret");
			addcode ("memcopyd:");
			addcode ("cmp ecx,0");
			addcode ("jnz memcopyd2");
			addcode ("ret");
			addcode ("memcopyd2:");
			addcode ("cld");
			addcode ("memcopyd10 db 66h,67h");
			addcode ("rep movsd");
			addcode ("ret");
			addcode ("memford:");
			addcode ("cmp ecx,0");
			addcode ("jnz memford2");
			addcode ("ret");
			addcode ("memford2:");
			addcode ("std");
			addcode ("memford10 db 66h,67h");
			addcode ("rep movsb");
			addcode ("cld");
			addcode ("ret");
			addcode ("memcopy:");
			addcode ("cmp ecx,0");
			addcode ("jnz memcopy2");
			addcode ("ret");
			addcode ("memcopy2:");
			addcode ("cld");
			addcode ("memcopy10 db 66h,67h");
			addcode ("rep movsb");
			addcode ("ret");
			addcode ("memfilld:");
			addcode ("	call byteEAX");
			addcode ("	cmp ecx,0");
			addcode ("	jz memfilld3");
			addcode ("memfilld2:");
			addcode ("cld");
			addcode ("memfilld10 db 66h,67h");
			addcode ("rep stosd");
			addcode ("memfilld3:");
			addcode ("ret");
			addcode ("memfill:");
			addcode ("	cmp ecx,0");
			addcode ("	jz memfill3");
			addcode ("memfill2:");
			addcode ("cld");
			addcode ("memfill10 db 66h,67h");
			addcode ("rep stosb");
			addcode ("memfill3:");
			addcode ("ret");
			addcode ("hlined32:");
			addcode ("	mov si,hlinex");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,640");
			addcode ("	cmp ax,bx");
			addcode ("	jb hlined32xxl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("hlined32xxl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg hlined32xxh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("hlined32xxh:");
			addcode ("	mov si,hliney");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,400");
			addcode ("	cmp ax,bx");
			addcode ("	jb hlined32yyl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("hlined32yyl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg hlined32yyh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("hlined32yyh:");
			addcode ("	mov si,hlinex1");
			addcode ("	mov ax,[si]");
			addcode ("	mov bx,640");
			addcode ("	cmp ax,bx");
			addcode ("	jb hlined32xxxl");
			addcode ("	dec bx");
			addcode ("	mov [si],bx");
			addcode ("hlined32xxxl:");
			addcode ("	mov bx,-1");
			addcode ("	cmp ax,bx");
			addcode ("	jg hlined32xxxh");
			addcode ("	inc bx");
			addcode ("	mov [si],bx");
			addcode ("hlined32xxxh:");
			addcode ("	mov si,hlinex");
			addcode ("	mov ax,[si]");
			addcode ("	mov si,hlinex1");
			addcode ("	mov bx,[si]");
			addcode ("	cmp ax,bx");
			addcode ("	ja hlined32end");
			addcode ("	jz hlined32end");
			addcode ("	mov si,hliney");
			addcode ("	xor eax,eax");
			addcode ("	mov ax,[si]");
			addcode ("	mov ebx,640");
			addcode ("	mov ecx,0");
			addcode ("	mov edx,0");
			addcode ("	mul ebx");
			addcode ("	mov ebx,140000h");
			addcode ("	add eax,ebx");
			addcode ("	mov si,hlinex");
			addcode ("	xor ebx,ebx");
			addcode ("	mov bx,[si]");
			addcode ("	add eax,ebx");
			addcode ("	mov edi,eax");
			addcode ("	mov si,hlinex1");
			addcode ("	xor eax,eax");
			addcode ("	mov ax,[si]");
			addcode ("	sub eax,ebx");
			addcode ("	mov ecx,eax");
			addcode ("	mov si,hlinecolor");
			addcode ("	mov al,[si]");
			addcode ("	push eax");
			addcode ("	push ebx");
			addcode ("	push edx");
			addcode ("	mov eax,ecx");
			addcode ("	mov ecx,0");
			addcode ("	mov edx,0");
			addcode ("	mov ebx,4");
			addcode ("	div ebx");
			addcode ("	mov ecx,eax");
			addcode ("	pop edx");
			addcode ("	pop ebx");
			addcode ("	pop eax");
			addcode ("	push ds");
			addcode ("	push es");
			addcode ("	mov bp,0");
			addcode ("	mov ds,bp");
			addcode ("	mov es,bp");
			addcode ("	call memfilld");
			addcode ("	pop es");
			addcode ("	pop ds");
			addcode ("hlined32end:");
			addcode ("	ret");
			addcode ("nosound:");
			addcode ("	mov dh,0fch");
			addcode ("	in al,61h");
			addcode ("	and al,dh");
			addcode ("	out 61h,al");
			addcode ("	ret");
			addcode ("sound:");
			addcode ("	mov ebx,eax");
			addcode ("	mov eax,1193181");
			addcode ("	mov ecx,0");
			addcode ("	mov edx,0");
			addcode ("	div ebx");
			addcode ("	mov bx,ax");
			addcode ("	mov dh,3");
			addcode ("	in al,61h");
			addcode ("	or al,dh");
			addcode ("	out 61h,al");
			addcode ("	mov al,0b6h");
			addcode ("	out 43h,al");
			addcode ("	mov al,bl");
			addcode ("	out 42h,al");
			addcode ("	mov al,bh");
			addcode ("	out 42h,al");
			addcode ("	ret");
			addcode ("memlen:");
			addcode ("mov edi,esi");
			addcode ("mov al,[esi]");
			addcode ("cmp al,0");
			addcode ("jz memlen22");
			addcode ("mov ecx,100000h");
			addcode ("mov al,0");
			addcode ("cld");
			addcode ("memlen10 db 66h,67h");
			addcode ("repne scasb");
			addcode ("je memlen11");
			addcode ("memlen22:");
			addcode ("mov ecx,0");
			addcode ("ret");
			addcode ("memlen11:");
			addcode ("mov ecx,edi");
			addcode ("sub ecx,esi");
			addcode ("dec ecx");
			addcode ("ret");
			addcode ("memlower:");
			addcode ("cmp ecx,0");
			addcode ("jz memlower22");
			addcode ("mov edi,esi");
			addcode ("memlower20:");
			addcode ("memlower30 db 66h,67h");
			addcode ("lodsb");
			addcode ("cmp al,65");
			addcode ("jb memlower90");
			addcode ("cmp al,90");
			addcode ("ja memlower90");
			addcode ("or al,20h");
			addcode ("memlower90:");
			addcode ("memlower40 db 66h,67h");
			addcode ("stosb");
			addcode ("loop memlower20");
			addcode ("cld");
			addcode ("memlower10 db 66h,67h");
			addcode ("rep movsb");
			addcode ("memlower22:");
			addcode ("ret");
			addcode ("memhigth:");
			addcode ("cmp ecx,0");
			addcode ("jz memhigth22");
			addcode ("mov edi,esi");
			addcode ("memhigth20:");
			addcode ("memhigth30 db 66h,67h");
			addcode ("lodsb");
			addcode ("cmp al,97");
			addcode ("jb memhigth90");
			addcode ("cmp al,122");
			addcode ("ja memhigth90");
			addcode ("and al,223");
			addcode ("memhigth90:");
			addcode ("memhigth40 db 66h,67h");
			addcode ("stosb");
			addcode ("loop memhigth20");
			addcode ("cld");
			addcode ("memhigth10 db 66h,67h");
			addcode ("rep movsb");
			addcode ("memhigth22:");
			addcode ("ret");
			addcode ("findchr:");
			addcode ("cmp ecx,0");
			addcode ("jz findchr22");
			addcode ("mov edi,esi");
			addcode ("findchr30 db 66h,67h");
			addcode ("cld");
			addcode ("findchr10 db 66h,67h");
			addcode ("repne scasb");
			addcode ("je findchr20");
			addcode ("findchr22:");
			addcode ("mov eax,-1");
			addcode ("ret");
			addcode ("findchr20:");
			addcode ("mov eax,edi");
			addcode ("sub eax,esi");
			addcode ("dec eax");
			addcode ("ret");
			addcode ("comps:");
			addcode ("cmp ecx,0");
			addcode ("jz comps20");
			addcode ("inc ecx");
			addcode ("comps30 db 66h,67h");
			addcode ("cld");
			addcode ("comps10 db 66h,67h");
			addcode ("repe cmpsb");
			addcode ("jecxz comps20");
			addcode ("mov ecx,2");
			addcode ("dec esi");
			addcode ("dec edi");
			addcode ("mov ax,0");
			addcode ("mov bx,0");
			addcode ("mov al,[esi]");
			addcode ("mov bl,[edi]");
			addcode ("cmp ax,bx");
			addcode ("ja comps21");
			addcode ("mov ecx,1");
			addcode ("comps21:");
			addcode ("mov eax,ecx");
			addcode ("ret");
			addcode ("comps20:");
			addcode ("mov eax,0");
			addcode ("ret");
			addcode ("findstr:");
			addcode ("push esi");
			addcode ("findstrs:");
			addcode ("mov al,[edi]");
			addcode ("mov bp,ax");
			addcode ("push edi");
			addcode ("push esi");
			addcode ("call memlen");
			addcode ("pop esi");
			addcode ("cmp ecx,0");
			addcode ("jz findstr223");
			addcode ("mov ax,bp");
			addcode ("call findchr");
			addcode ("cmp eax,-1");
			addcode ("jz findstr223");
			addcode ("mov esi,edi");
			addcode ("pop edi");
			addcode ("push esi");
			addcode ("push edi");
			addcode ("mov esi,edi");
			addcode ("call memlen");
			addcode ("pop edi");
			addcode ("pop esi");
			addcode ("cmp ecx,0");
			addcode ("jz findstr22");
			addcode ("push esi");
			addcode ("push edi");
			addcode ("dec esi");
			addcode ("call comps");
			addcode ("pop edi");
			addcode ("pop esi");
			addcode ("cmp eax,0");
			addcode ("jz findstr20");
			addcode ("jmp findstrs");
			addcode ("findstr222:");
			addcode ("pop esi");
			addcode ("findstr223:");
			addcode ("pop esi");
			addcode ("findstr22:");
			addcode ("mov eax,-1");
			addcode ("pop esi");
			addcode ("ret");
			addcode ("findstr20:");
			addcode ("mov edi,esi");
			addcode ("pop esi");
			addcode ("mov eax,edi");
			addcode ("sub eax,esi");
			addcode ("dec eax");
			addcode ("ret");
			addcode ("WRITE16:           ");     
			addcode ("          push bx                ");
			addcode ("          push dx                ");
			addcode ("          mov dx,si");
			addcode ("          mov bx,di");
			addcode ("          mov ah,40h");
			addcode ("          int 21h                ");
			addcode ("          pop dx                 ");
			addcode ("          pop bx                ");
			addcode ("          RET                ");
			addcode ("READ16:                ");
			addcode ("          push bx                ");
			addcode ("          push dx                ");
			addcode ("          mov dx,si");
			addcode ("          mov bx,di");
			addcode ("          mov ah,3fh");
			addcode ("          int 21h                ");
			addcode ("          pop dx                 ");
			addcode ("          pop bx                ");
			addcode ("          RET      ");

			addcode ("WRITE32:             ");   
			addcode ("          push eax   ");             
			addcode ("          push ebx   ");             
			addcode ("          push ecx   ");             
			addcode ("          push edx   ");             
			addcode ("          push esi   ");             
			addcode ("          push edi   ");             
			addcode ("          push ebp   ");             
			addcode ("          push ds    ");            
			addcode ("          push es    ");            
			addcode ("          mov bp,0   ");             
			addcode ("          mov ds,bp");
			addcode ("          mov es,bp");
                         
			addcode ("          WRITE321:");
                          
			addcode ("          cs");
			addcode ("          mov [write32addrs1],esi");
			addcode ("          cs");
			addcode ("          mov [write32counter1],ecx");
			addcode ("          cs");
			addcode ("          mov [write32f1],di");
			addcode ("          mov ax,0                ");
			addcode ("          cs");
			addcode ("          mov [write32seg2],ax");
			addcode ("          mov eax,ecx");
			addcode ("          cmp eax,0");
			addcode ("          JZ WRITE325");
                          
			addcode ("          xor edx,edx");
			addcode ("          xor ecx,ecx");
			addcode ("          mov ebx,0ffffh");
			addcode ("          clc                ");
			addcode ("          div ebx                ");
			addcode ("          cs");
			addcode ("          mov [write32counter3],eax");
			addcode ("          cs");
			addcode ("          mov [write32output],edx");
			addcode ("          mov ax,cs");
			addcode ("          mov bx,2000h");
			addcode ("          clc                ");
			addcode ("          add ax,bx");
			addcode ("          cs");
			addcode ("          mov [write32seg1],ax");
			addcode ("          mov si,0                ");
			addcode ("call MEM32");
			addcode ("          cs");
			addcode ("          mov [write32addrs2],eax");
			addcode ("          mov eax,0");
			addcode ("          cs");
			addcode ("          mov [write32counter2],eax");
			addcode ("          mov eax,0ffffh");
			addcode ("          cs");
			addcode ("          mov [write32size],eax");
			addcode ("          cs");
			addcode ("          mov eax,[write32counter3]");
			addcode ("          cmp eax,0");
			addcode ("          JZ WRITE323");
			addcode ("          WRITE322:");
			addcode ("          cs");
			addcode ("                    mov ax,[write32seg2]");
			addcode ("                    mov ds,ax");
			addcode ("          cs");
			addcode ("                    mov ecx,[write32size]");
			addcode ("          cs");
			addcode ("                    mov esi,[write32addrs1]");
			addcode ("          cs");
			addcode ("                    mov edi,[write32addrs2]");
			addcode ("                    mov edx,1");
			addcode ("          push eax");
			addcode ("          push ebx");
			addcode ("          push ecx");
			addcode ("          push edx");
			addcode ("          push esi");
			addcode ("          push edi");
			addcode ("          push ebp");
			addcode ("          push ds");
			addcode ("                    call memcopy");
			addcode ("          pop ds");
			addcode ("          pop ebp");
			addcode ("          pop edi");
			addcode ("          pop esi");
			addcode ("          pop edx");
			addcode ("          pop ecx");
			addcode ("          pop ebx");
			addcode ("          pop eax");
			addcode ("          cs");
			addcode ("                    mov ax,[write32seg1]");
			addcode ("                    mov ds,ax");
			addcode ("                    mov si,0                ");
			addcode ("          cs");
			addcode ("                    mov di,[write32f1]");
			addcode ("                    mov cx,0ffffh");
			addcode ("                    call WRITE16");
			addcode ("          cs");
			addcode ("                    mov eax,[write32addrs1]");
			addcode ("          cs");
			addcode ("                    mov ebx,[write32size] ");
			addcode ("                    clc                ");
			addcode ("                    add eax,ebx");
			addcode ("          cs");
			addcode ("                    mov [write32addrs1],eax");
			addcode ("          cs");
			addcode ("                    mov eax,[write32counter3]");
			addcode ("                    dec eax                ");
			addcode ("          cs");
			addcode ("                    mov [write32counter3],eax");
			addcode ("                    cmp eax,0");
			addcode ("                    JNZ WRITE322");
			addcode ("          WRITE323:");
			addcode ("          cs");
			addcode ("          cmp DWORD [write32output],0");
			addcode ("          JZ WRITE325");
			addcode ("          cs");
			addcode ("          mov ax,[write32seg2]");
			addcode ("          mov ds,ax");
			addcode ("          cs");
			addcode ("          mov ecx,[write32output]");
			addcode ("          cs");
			addcode ("          mov esi,[write32addrs1]");
			addcode ("          cs");
			addcode ("          mov edi,[write32addrs2]");
			addcode ("          mov edx,1");
			addcode ("          push eax");
			addcode ("          push ebx");
			addcode ("          push ecx");
			addcode ("          push edx");
			addcode ("          push esi");
			addcode ("          push edi");
			addcode ("          push ebp");
			addcode ("          push ds");
			addcode ("          call memcopy");
			addcode ("          pop ds");
			addcode ("          pop ebp");
			addcode ("          pop edi");
			addcode ("          pop esi");
			addcode ("          pop edx");
			addcode ("          pop ecx");
			addcode ("          pop ebx");
			addcode ("          pop eax");
			addcode ("          cs");
			addcode ("          mov ax,[write32seg1]");
			addcode ("          mov ds,ax");
			addcode ("          mov si,0                ");
			addcode ("          cs");
			addcode ("          mov di,[write32f1]");
			addcode ("          cs");
			addcode ("          mov cx,[write32output]");
			addcode ("          call WRITE16");
                          
			addcode ("          WRITE324:");
			addcode ("WRITE325:");
			addcode ("                    pop es                ");
			addcode ("                    pop ds                ");
			addcode ("                    pop ebp                ");
			addcode ("                    pop edi                ");
			addcode ("                    pop esi                ");
			addcode ("                    pop edx                ");
			addcode ("                    pop ecx                 ");
			addcode ("                    pop ebx                ");
			addcode ("                    pop eax                ");
			addcode ("                    RET                ");
			addcode ("READ32:                ");
			addcode ("          push eax                ");
			addcode ("          push ebx                ");
			addcode ("          push ecx                ");
			addcode ("          push edx                ");
			addcode ("          push esi                ");
			addcode ("          push edi                ");
			addcode ("          push ebp                ");
			addcode ("          push ds                ");
			addcode ("          push es                ");
			addcode ("          mov bp,0                ");
			addcode ("          mov ds,bp");
			addcode ("          mov es,bp");
			addcode ("          READ321:                ");
			addcode ("          cs");
			addcode ("          mov [read32addrs1],esi");
			addcode ("          cs");
			addcode ("          mov [read32counter1],ecx");
			addcode ("          cs");
			addcode ("          mov [read32f1],di");
			addcode ("          cs");
			addcode ("          mov DWORD [read32seg2],0");
			addcode ("          mov eax,ecx");
			addcode ("          cmp eax,0");
			addcode ("          JZ READ325");
			addcode ("          xor edx,edx");
			addcode ("          xor ecx,ecx");
			addcode ("          mov ebx,0ffffh");
			addcode ("          clc                ");
			addcode ("          div ebx                ");
			addcode ("          cs");
			addcode ("          mov [read32counter3],eax");
			addcode ("          cs");
			addcode ("          mov [read32output],edx");
			addcode ("          mov ax,cs");
			addcode ("          mov bx,2000h");
			addcode ("          clc                ");
			addcode ("          add ax,bx");
			addcode ("          cs");
			addcode ("          mov [read32seg1],ax");
			addcode ("          mov si,0                ");
			addcode ("          call MEM32");
			addcode ("          cs");
			addcode ("          mov [read32addrs2],eax");
			addcode ("          mov eax,0");
			addcode ("          cs");
			addcode ("          mov [read32counter2],eax");
			addcode ("          mov eax,0ffffh");
			addcode ("          cs");
			addcode ("          mov [read32size],eax");
			addcode ("          cs");
			addcode ("          mov eax,[read32counter3]");
			addcode ("          cmp eax,0");
			addcode ("          JZ READ323");
			addcode ("          READ322:                ");
			addcode ("          cs");
			addcode ("	          mov ax,[read32seg1]");
			addcode ("                    mov ds,ax");
			addcode ("                    mov si,0             ");   
			addcode ("          cs");
			addcode ("                    mov di,[read32f1]");
			addcode ("                    mov cx,0ffffh");
			addcode ("                    call READ16");
			addcode ("          cs");
			addcode ("                    mov ax,[read32seg2]");
			addcode ("                    mov ds,ax");
			addcode ("          cs");
			addcode ("                    mov ecx,[read32size]");
			addcode ("          cs");
			addcode ("                    mov esi,[read32addrs2]");
			addcode ("          cs");
			addcode ("                    mov edi,[read32addrs1]");
			addcode ("                    mov edx,1");
			addcode ("          push eax");
			addcode ("          push ebx");
			addcode ("          push ecx");
			addcode ("          push edx");
			addcode ("          push esi");
			addcode ("          push edi");
			addcode ("          push ebp");
			addcode ("          push ds");
			addcode ("          call memcopy");
			addcode ("          pop ds");
			addcode ("          pop ebp");
			addcode ("          pop edi");
			addcode ("          pop esi");
			addcode ("          pop edx");
			addcode ("          pop ecx");
			addcode ("          pop ebx");
			addcode ("          pop eax");
			addcode ("          cs");
			addcode ("                    mov eax,[read32addrs1]");
			addcode ("          cs");
			addcode ("                    mov ebx,[read32size] ");
			addcode ("                    clc                ");
			addcode ("                    add eax,ebx");
			addcode ("          cs");
			addcode ("                    mov [read32addrs1],eax");
			addcode ("          cs");
			addcode ("                    mov eax,[read32counter3]");
			addcode ("                    dec eax                ");
			addcode ("          cs");
			addcode ("                    mov [read32counter3],eax");
			addcode ("                    cmp eax,0");
			addcode ("                    JNZ READ322");
			addcode ("          READ323:                ");
			addcode ("          cs");
			addcode ("          cmp DWORD [read32output],0");
			addcode ("          JZ READ325");
			addcode ("          cs");
			addcode ("          mov ax,[read32seg1]");
			addcode ("          mov ds,ax");
			addcode ("          mov si,0                ");
			addcode ("          cs");
			addcode ("          mov di,[read32f1]");
			addcode ("          cs");
			addcode ("          mov ecx,[read32output]");
			addcode ("          call READ16");
			addcode ("          cs");
			addcode ("          mov ax,[read32seg2]");
			addcode ("          mov ds,ax");
			addcode ("          cs");
			addcode ("          mov cx,[read32output]");
			addcode ("          cs");
			addcode ("          mov esi,[read32addrs2]");
			addcode ("          cs");
			addcode ("          mov edi,[read32addrs1]");
			addcode ("          mov edx,1");
			addcode ("          push eax");
			addcode ("          push ebx");
			addcode ("          push ecx");
			addcode ("          push edx");
			addcode ("          push esi");
			addcode ("          push edi");
			addcode ("          push ebp");
			addcode ("          push ds");
			addcode ("          call memcopy");
			addcode ("          pop ds");
			addcode ("          pop ebp");
			addcode ("          pop edi");
			addcode ("          pop esi");
			addcode ("          pop edx");
			addcode ("          pop ecx");
			addcode ("          pop ebx");
			addcode ("          pop eax");
			addcode ("          READ324:               "); 
			addcode ("                    READ325:     ");           
			addcode ("                    pop es       ");         
			addcode ("                    pop ds       ");         
			addcode ("                    pop ebp      ");          
			addcode ("                    pop edi      ");          
			addcode ("                    pop esi      ");          
			addcode ("                    pop edx      ");          
			addcode ("                    pop ecx      ");           
			addcode ("                    pop ebx      ");          
			addcode ("                    pop eax      ");          
			addcode ("                    RET         ");
			addcode ("chain:");
			addcode ("	mov bx,0x100");
			addcode ("	mov dx,bx");
			addcode ("	mov cx,65050");
			addcode ("	mov bx,65298");
			addcode ("	mov ax,[bx]");
			addcode ("	mov bx,ax");
			addcode ("	mov ah,0x3f");
			addcode ("	int 0x21");
			addcode ("	mov bx,65298");
			addcode ("	mov ax,[bx]");
			addcode ("	mov bx,ax");
			addcode ("	mov al,2");
			addcode ("	mov ah,0x3e");
			addcode ("	int 0x21");
			addcode ("	ret");
			addcode ("cicle:");
			addcode ("	cmp eax,0");
			addcode ("	jz cicle2");
			addcode ("	mov ecx,eax");
			addcode ("	cicle1:");
			addcode ("		dec ecx");
			addcode ("		cmp ecx,0");
			addcode ("		jnz cicle1");
			addcode ("cicle2:");
			addcode ("ret");
			addcode ("bitmapattr:");
			addcode ("	mov eax,[esi]");
			addcode ("	mov ecx,4");
			addcode ("	add esi,ecx");
			addcode ("	mov ebx,[esi]");
			addcode ("	add esi,ecx");
			addcode ("	ret");
			addcode ("");
			addcode ("section .data");
			addcode ("          read32addrs1 dd 0");
			addcode ("          read32addrs2 dd 0");
			addcode ("          read32counter1 dd 0");
			addcode ("          read32counter2 dd 0");
			addcode ("          read32counter3 dd 0");
			addcode ("          read32output     dd 0");
			addcode ("          read32f1             dw 0");
			addcode ("          read32seg1        dw 0");
			addcode ("          read32seg2        dw 0");
			addcode ("          read32size         dd 0");
			addcode ("          write32addrs1 dd 0");
			addcode ("          write32addrs2 dd 0");
			addcode ("          write32counter1 dd 0");
			addcode ("          write32counter2 dd 0");
			addcode ("          write32counter3 dd 0");
			addcode ("          write32output     dd 0");
			addcode ("          write32f1             dw 0");
			addcode ("          write32seg1        dw 0");
			addcode ("          write32seg2        dw 0");
			addcode ("          write32size         dd 0");
			addcode ("hlinex     dw 0");
			addcode ("hliney     dw 0");
			addcode ("hlinex1     dw 0");
			addcode ("hliney1     dw 0");
			addcode ("hlinecolor     db 0");
			addcode ("hlinedx     dw 0");
			addcode ("hlinedy     dw 0");
			addcode ("hlinedx1     dw 0");
			addcode ("hlinedy1     dw 0");
			addcode ("hlinedcolor     db 0");
			addcode ("vlinex     dw 0");
			addcode ("vliney     dw 0");
			addcode ("vlinex1     dw 0");
			addcode ("vliney1     dw 0");
			addcode ("vlinecolor     db 0");
			addcode ("boxdx     dw 0");
			addcode ("boxdy     dw 0");
			addcode ("boxdx1     dw 0");
			addcode ("boxdy1     dw 0");
			addcode ("boxdcolor     db 0");
			addcode ("boxx     dw 0");
			addcode ("boxy     dw 0");
			addcode ("boxx1     dw 0");
			addcode ("boxy1     dw 0");
			addcode ("boxcolor     db 0");
			addcode ("x     db 0");
			addcode ("y     db 0");
			addcode ("color dw 07h");
			addcode ("L4 db 0,0,0,0,0");
			addcode ("L18 dw 0,0");
			addcode ("L20 dw 0,0,0,0,0,0,0,0");
			addcode ("L21 dw 0,0,0,0");
			addcode ("L6 db 'press a key to go on, esc key to exit scroll',13,10,0");
			addcode ("L16 db '..........................................',13,10,0");
			addcode ("L17 db '0000000000 ',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0");
			addcode ("L22 db '00000000000 ',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0");
			addcode ("L50 times 260 db 32");
			addcode ("L51 db 0");
			addcode ("rreservemem dd 0");
			addcode ("rreservemem2 dd 0");

			addcode (";start tail");
			addcode ("");


			subcursor=0;
			cursor=0;

		addkey ("print",2); //0
		addkey ("set",3); //1
		addkey ("",1); //2
		addkey ("echo",2); //3
		addkey ("wait",2); //4
		addkey ("integer",3); //5
		addkey ("let",3); //6
		addkey ("add",4); //7
		addkey ("sub",4); //8
		addkey ("exit",1); //9
		addkey ("label",2); //10
		addkey ("goto",2); //11
		addkey ("return",1); //12
		addkey ("like",8); //13
		addkey ("diferent",8); //14
		addkey ("big",8); //15
		addkey ("less",8); //16
		addkey ("rem",2); //17
		addkey ("gosub",2); //18
		addkey ("memfill",4); //19
		addkey ("memcopy",4); //20
		addkey ("string",3); //21
		addkey ("strcat",3); //22
		addkey ("strcopy",3); //23
		addkey ("memmove",4); //24
		addkey ("input",3); //25
		addkey ("memback",4); //26
		addkey ("memford",4); //27
		addkey ("strfrom",4); //28
		addkey ("for",10); //29
		addkey ("next",1); //30
		addkey ("pointer",3);//31
		addkey ("copy",4); //32
		addkey ("str",3); //33
		addkey ("val",3); //34
		addkey ("getnumber",2); //35
		addkey ("printnumber",2); //36
		addkey ("machine",2); //37
		addkey ("reset",2);  //38
		addkey ("mul",4); //39
		addkey ("div",4); //40
		addkey ("move",3); //41
		addkey ("alocate",3); //42
		addkey ("call",6); //43
		addkey ("file.creat",2); //44
		addkey ("file.open",3); //45
		addkey ("file.close",2); //46
		addkey ("file.read",4);  //47
		addkey ("file.write",4);  //48
		addkey ("string.len",3);  //49
		addkey ("timer.sleep",2); //50
		addkey ("timer.rnd",2);  //51
		addkey ("stack.push",2); //52
		addkey ("mem.peek",3); //53
		addkey ("mem.poke",3); //54 
		addkey ("bits.and",4);  //55
		addkey ("bits.not",3);  //56
		addkey ("mem.reserve",3); //57
		addkey ("far.into",4);  //58
		addkey ("far.from",4);  //59
		addkey ("text",3); //60
		addkey ("string.comp",4); //61
		addkey ("string.lower",2); //62
		addkey ("string.high",2); //63
		addkey (":",2); //64
		addkey ("string.findchr",4); //65
		addkey (";",2); //66
		addkey ("string.findstr",4); //67
		addkey ("inkey",2);  //68
		addkey ("const",2);  //69
		addkey ("locate",4);  //70
		addkey ("screen",2);  //71
		addkey ("textout",4);  //72
		addkey ("border",2);  //73
		addkey ("float",3);   //74
		addkey ("back",2);    //75
		addkey ("hline",5);   //76
		addkey ("doevents",1);  //77
		addkey ("box",6);   //78
		addkey ("file.chain",2);  //79
		addkey ("file.exec",2);   //80
		addkey ("timer.cicle",2);  //81
		addkey ("memory",3);   //82
		addkey ("fillstep",5);  //83
		addkey ("color",2);  //84
		addkey ("vline",5); //key 85
		addkey ("nosound",1); //key 86
		addkey ("sound",2); //key 87
		addkey ("beep",1); //key 88
		addkey ("memory.set",3); //key 89
		addkey ("bitmap.creat",4); //key 90
		addkey ("bitmap.back",3); //key 91
		addkey ("bitmap.attr",4); //key 92
		addkey ("declare",2); //93
		addkey ("function",2); //94
		addkey ("pointer.to",3); //95
		addkey ("pointer.from",3); //96
		addkey ("while",8); //97
		addkey ("do",8); //98
		addkey ("inside",8); //99
		addkey ("outside",8); //100
		addkey ("loop",8); //101
		addkey ("eval",3); //102
		addkey ("printfloat",2); //103
		addkey ("(integer)",3); //104
		addkey ("(float)",3); //105
		addkey ("double",3); //106
		addkey ("(double)",3); //107
		addkey ("printdouble",2); //108
		varsart=cursor;
		substart=subcursor;
}

//==*===============================================================
//addcode
void addcode(char *s1){
	fprintf(f1,"%s\n",s1);
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
//findkey
int findkey(char *s){
	int n;
	int i=-1;
	for (n=0;n<subcursor;n++){
		if(strcmp(s,subs[n])==0){
			i=n;
			n=subcursor+1;
		}
		
	}
	return i;
}

//=================================================================
//addtxtbody
void addtxtbody(char *s){
	fprintf(f2,"%s\n",s);
}
//=================================================================
//addtxtbodynx
void addtxtbodynx(char *s){
	fprintf(f2,"%s",s);
}
//=================================================================
//addtxtbodynb
void addtxtbodynb(int n){
	fprintf(f2,"%d",n);
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
//declair
int declair(char *s){
	char *ss1;
	if(paramets[93]==count){
		ss1=uppercase(s);
		addkey (ss1,5);
		error=0;
		// debug line printf("add function:%s\n",s);
		varsart=cursor;
		error=0;
		return 0;
	}
}
//=================================================================
//function
int function(char *s){
	int i;
	char *ss1;
	if(paramets[94]==count){
		ss1=uppercase(ss[1]);
		i=findkey(ss1);
		if (i==-1){
			addkey (ss1,5);
			i=findkey(ss1);
		}
		varnextstart=varnext;
		varcursor=0;
		cursor=varsart;
		if (mainsub==0){
			mainsub=1;
		}else{
			fprintf(f2,"ret\n");
		}	
		fprintf(f2,"; sub, %s:\n",ss[1]);
		fprintf(f1,"; sub, %s:\n",ss[1]);
		fprintf(f2,"sub%d:\n",i);
		fprintf(f1,"varnext%d dd 0\n",varnext);
		fprintf(f2,"	mov di,varnext%d\n",varnext);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov [di],eax\n");
		varnext++;
		fprintf(f1,"varnext%d dd 0\n",varnext);
		fprintf(f2,"	mov di,varnext%d\n",varnext);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov [di],ebx\n");
		varnext++;
		fprintf(f1,"varnext%d dd 0\n",varnext);
		fprintf(f2,"	mov di,varnext%d\n",varnext);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov [di],ecx\n");
		varnext++;
		fprintf(f1,"varnext%d dd 0\n",varnext);
		fprintf(f2,"	mov di,varnext%d\n",varnext);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov [di],edx\n");
		varnext++;
		addvar("ARGV0");
		addvar("ARGV1");
		addvar("ARGV2");
		addvar("ARGV3");
		error=0;
	}

}

//=================================================================
//echos
int echos(){
		int vvar;
		if(paramets[3]==count){
			vvar=register_var(ss[1]);
			addtxtbodynx("	mov si,var");
			addtxtbodynb(vvar);
			addtxtbody("");
			addtxtbody("	call echo");

			error=0;
		}
		return 0;
}

//=================================================================
//integer
int iinteger(char *s){
	int i;
	char *ss1;
	char *ss2;
	long l;
	if(paramets[5]==count){
		error=0;
		ss1=uppercase(ss[1]);
		i=findvar(ss1);
		if (i==-1){
			addvar (ss1);
			i=findvar(ss1);
		}else{
			error=1;
		}
		ss2=uppercase(ss[2]);
		l=atol(ss2);
		fprintf(f1,"varnext%d dd %lu\n",varnext,l);
		varnext++;
									fprintf(f2,"	mov eax,%lu\n",l);
									fprintf(f2,"	mov bx,varnext%d\n",i+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],eax");


	}
	return 0;
}
//=================================================================

int callfunction(char *s){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(5==count){

		error=0;
		ss1=uppercase(ss[0]);
		i=findkey(ss1);
		if (i==-1){
			printf("error key\n");
			error=1;
		}

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
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edx,[si]\n");
		fprintf(f2,"	call sub%d\n",i);

		
	}
	
}
//=================================================================

int locate(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(paramets[70]==count){

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


									addtxtbody("	mov bx,x");
									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	mov al,[si]");
									addtxtbody("	mov [bx],al");
									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	mov al,[si]");
									addtxtbody("	inc bx");
									addtxtbody("	mov [bx],al");

									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	mov dl,[si]");
									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	mov dh,[si]");
									addtxtbody("	mov ah,2");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	mov bh,[si]");
									addtxtbody("	int 0x10");

	}
	return 0;
}

//=================================================================

int color(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(paramets[84]==count){

		error=0;

		ss1=uppercase(ss[1]);
		i1=findvar(ss1);
		if (i1==-1){
			printf("error var1\n");
			error=1;
		}
									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	mov al,[si]");
									addtxtbody("	mov si,color");
									addtxtbody("	mov [si],al");



	}


	return 0;
}
//=================================================================

int add(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(paramets[7]==count){

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
									addtxtbody("	add eax,ecx");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],eax");

		}
		return 0;
}



//=================================================================


int sub(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(paramets[8]==count){

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
									addtxtbody("	sub eax,ecx");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],eax");

		}
		return 0;
}

//=================================================================

int consts(){
	int i;
	int n;
	char *ss1;
	char *ss2;
	long l;
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
		
			l=atol(ss1);
			fprintf(f1,"varnext%d dd %lu\n",varnext,l);
			varnext++;
		}
	}
	return 0;
}

//=================================================================


int printnumber(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(paramets[36]==count){

		error=0;

		ss1=uppercase(ss[1]);
		i1=findvar(ss1);
		if (i1==-1){
			printf("error var1\n");
			error=1;
		}

									addtxtbody("	mov si,L17");
									addtxtbody("	mov ax,cs");
									addtxtbody("	call MEM32");
									addtxtbody("	mov edi,eax");
									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	call STR32");
									addtxtbody("	mov si,L17");
									addtxtbody("	mov ax,cs");
									addtxtbody("	call MEM32");
									addtxtbody("	mov esi,eax");
									addtxtbody("	call len32");
									addtxtbody("	mov ecx,eax");
									addtxtbody("	call PRINT32");
	}
	return 0;
}

//=================================================================


int pointers(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(paramets[31]==count){

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
										addtxtbody("	mov ax,cs");
										addtxtbody("	call MEM32");
										fprintf(f2,"	mov di,varnext%d\n",i1+varnextstart);
										addtxtbody("	cs");
										addtxtbody("	mov [di],eax");


		}

		return 0;
}

//=================================================================

int pointersto(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(paramets[95]==count){

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



										fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
										fprintf(f2,"	cs\n");
										fprintf(f2,"	mov eax,[si]\n");
										addtxtbody("	mov edi,eax\n");
										addtxtbody("	mov ax,0");
										addtxtbody("	mov ds,ax");
										fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
										addtxtbody("	cs");
										addtxtbody("	mov eax,[si]");
										addtxtbody("	ds");
										addtxtbody("	mov [edi],eax");
										addtxtbody("	mov ax,cs");
										addtxtbody("	mov ds,ax");
		}

		return 0;
}

//=================================================================

int pointersfrom(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(paramets[96]==count){

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
										fprintf(f2,"	cs\n");
										fprintf(f2,"	mov eax,[si]\n");
										addtxtbody("	mov esi,eax");
										addtxtbody("	mov ax,0");
										addtxtbody("	mov ds,ax");
										addtxtbody("	ds");
										addtxtbody("	mov edx,[esi]");
										addtxtbody("	mov ax,cs");
										addtxtbody("	mov ds,ax");
										fprintf(f2,"	mov di,varnext%d\n",i1+varnextstart);
										addtxtbody("	cs");
										addtxtbody("	mov [di],edx");
		}

		return 0;
}

//=================================================================

int ford(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(10==count){

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
		i5=findkey(ss1);
		if (i5<substart){
			printf("error key\n");
			error=1;
		}



		ss1=uppercase(ss[6]);
		i6=findvar(ss1);
		if (i6==-1){
			printf("error var6\n");
			error=1;
		}

		ss1=uppercase(ss[7]);
		i7=findvar(ss1);
		if (i7==-1){
			printf("error var7\n");
			error=1;
		}

		ss1=uppercase(ss[8]);
		i8=findvar(ss1);
		if (i8==-1){
			printf("error var9\n");
			error=1;
		}

		ss1=uppercase(ss[9]);
		i9=findvar(ss1);
		if (i9==-1){
			printf("error var9\n");
			error=1;
		}





		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov di,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov [di],eax\n");
		fprintf(f2,"	lineno%d:\n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i6+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i7+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i8+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i9+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edx,[si]\n");
		fprintf(f2,"	call sub%d\n",i5);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	clc\n");
		fprintf(f2,"	add eax,ebx\n");
		fprintf(f2,"	mov di,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov [di],eax\n");
		fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp eax,ebx\n");
		fprintf(f2,"	jle lineno%d \n",lineno);
		
	}
	
}



//=================================================================

//=================================================================

int dowhile(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(8==count){

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

		ss1=uppercase(ss[5]);
		i5=findvar(ss1);
		if (i5==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}


		ss1=uppercase(ss[3]);
		i3=findkey(ss1);
		if (i3<substart){
			printf("error key\n");
			error=1;
		}



		ss1=uppercase(ss[6]);
		i6=findvar(ss1);
		if (i6==-1){
			printf("error var6\n");
			error=1;
		}

		ss1=uppercase(ss[7]);
		i7=findvar(ss1);
		if (i7==-1){
			printf("error var7\n");
			error=1;
		}


		fprintf(f2,"	lineno%d:\n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i5+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i6+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i7+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edx,[si]\n");
		fprintf(f2,"	call sub%d\n",i3);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp eax,ebx\n");
		fprintf(f2,"	jnz lineno%d \n",lineno);
		
	}
	
}



//=================================================================


int dodo(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(8==count){

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

		ss1=uppercase(ss[5]);
		i5=findvar(ss1);
		if (i5==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}


		ss1=uppercase(ss[3]);
		i3=findkey(ss1);
		if (i3<substart){
			printf("error key\n");
			error=1;
		}



		ss1=uppercase(ss[6]);
		i6=findvar(ss1);
		if (i6==-1){
			printf("error var6\n");
			error=1;
		}

		ss1=uppercase(ss[7]);
		i7=findvar(ss1);
		if (i7==-1){
			printf("error var7\n");
			error=1;
		}


		fprintf(f2,"	lineno%d:\n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp eax,ebx\n");
		fprintf(f2,"	jz linenos%d \n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i5+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i6+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i7+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edx,[si]\n");
		fprintf(f2,"	call sub%d\n",i3);
		fprintf(f2,"	jmp lineno%d \n",lineno);
		fprintf(f2,"	linenos%d:\n",lineno);
	}
	
}



//=================================================================


int like(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(8==count){

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

		ss1=uppercase(ss[5]);
		i5=findvar(ss1);
		if (i5==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}


		ss1=uppercase(ss[3]);
		i3=findkey(ss1);
		if (i3<substart){
			printf("error key\n");
			error=1;
		}



		ss1=uppercase(ss[6]);
		i6=findvar(ss1);
		if (i6==-1){
			printf("error var6\n");
			error=1;
		}

		ss1=uppercase(ss[7]);
		i7=findvar(ss1);
		if (i7==-1){
			printf("error var7\n");
			error=1;
		}


		fprintf(f2,"	lineno%d:\n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp eax,ebx\n");
		fprintf(f2,"	jnz linenos%d \n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i5+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i6+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i7+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edx,[si]\n");
		fprintf(f2,"	call sub%d\n",i3);
		fprintf(f2,"	linenos%d:\n",lineno);
	}
	
}



//=================================================================

int diferent(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(8==count){

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

		ss1=uppercase(ss[5]);
		i5=findvar(ss1);
		if (i5==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}


		ss1=uppercase(ss[3]);
		i3=findkey(ss1);
		if (i3<substart){
			printf("error key\n");
			error=1;
		}



		ss1=uppercase(ss[6]);
		i6=findvar(ss1);
		if (i6==-1){
			printf("error var6\n");
			error=1;
		}

		ss1=uppercase(ss[7]);
		i7=findvar(ss1);
		if (i7==-1){
			printf("error var7\n");
			error=1;
		}


		fprintf(f2,"	lineno%d:\n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp eax,ebx\n");
		fprintf(f2,"	jz linenos%d \n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i5+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i6+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i7+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edx,[si]\n");
		fprintf(f2,"	call sub%d\n",i3);
		fprintf(f2,"	linenos%d:\n",lineno);
	}
	
}



//=================================================================


int big(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(8==count){

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

		ss1=uppercase(ss[5]);
		i5=findvar(ss1);
		if (i5==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}


		ss1=uppercase(ss[3]);
		i3=findkey(ss1);
		if (i3<substart){
			printf("error key\n");
			error=1;
		}



		ss1=uppercase(ss[6]);
		i6=findvar(ss1);
		if (i6==-1){
			printf("error var6\n");
			error=1;
		}

		ss1=uppercase(ss[7]);
		i7=findvar(ss1);
		if (i7==-1){
			printf("error var7\n");
			error=1;
		}


		fprintf(f2,"	lineno%d:\n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp eax,ebx\n");
		fprintf(f2,"	jle linenos%d \n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i5+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i6+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i7+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edx,[si]\n");
		fprintf(f2,"	call sub%d\n",i3);
		fprintf(f2,"	linenos%d:\n",lineno);
	}
	
}



//=================================================================

int less(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(8==count){

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

		ss1=uppercase(ss[5]);
		i5=findvar(ss1);
		if (i5==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}


		ss1=uppercase(ss[3]);
		i3=findkey(ss1);
		if (i3<substart){
			printf("error key\n");
			error=1;
		}



		ss1=uppercase(ss[6]);
		i6=findvar(ss1);
		if (i6==-1){
			printf("error var6\n");
			error=1;
		}

		ss1=uppercase(ss[7]);
		i7=findvar(ss1);
		if (i7==-1){
			printf("error var7\n");
			error=1;
		}


		fprintf(f2,"	lineno%d:\n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp eax,ebx\n");
		fprintf(f2,"	jae linenos%d \n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i5+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i6+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i7+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edx,[si]\n");
		fprintf(f2,"	call sub%d\n",i3);
		fprintf(f2,"	linenos%d:\n",lineno);
	}
	
}



//=================================================================


int inside(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(8==count){

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

		ss1=uppercase(ss[5]);
		i5=findvar(ss1);
		if (i5==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}


		ss1=uppercase(ss[3]);
		i3=findkey(ss1);
		if (i3<substart){
			printf("error key\n");
			error=1;
		}



		ss1=uppercase(ss[6]);
		i6=findvar(ss1);
		if (i6==-1){
			printf("error var6\n");
			error=1;
		}

		ss1=uppercase(ss[7]);
		i7=findvar(ss1);
		if (i7==-1){
			printf("error var7\n");
			error=1;
		}


		fprintf(f2,"	lineno%d:\n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp ebx,eax\n");
		fprintf(f2,"	jl linenos%d \n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	mov ax,4\n");
		fprintf(f2,"	clc\n");
		fprintf(f2,"	add si,ax\n");
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp ebx,eax\n");
		fprintf(f2,"	jg linenos%d \n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i5+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i6+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i7+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edx,[si]\n");
		fprintf(f2,"	call sub%d\n",i3);
		fprintf(f2,"	linenos%d:\n",lineno);
	}
	
}



//=================================================================


int outside(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(8==count){

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

		ss1=uppercase(ss[5]);
		i5=findvar(ss1);
		if (i5==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}


		ss1=uppercase(ss[3]);
		i3=findkey(ss1);
		if (i3<substart){
			printf("error key\n");
			error=1;
		}



		ss1=uppercase(ss[6]);
		i6=findvar(ss1);
		if (i6==-1){
			printf("error var6\n");
			error=1;
		}

		ss1=uppercase(ss[7]);
		i7=findvar(ss1);
		if (i7==-1){
			printf("error var7\n");
			error=1;
		}


		fprintf(f2,"	lineno%d:\n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp ebx,eax\n");
		fprintf(f2,"	jl linenoss%d \n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	mov ax,4\n");
		fprintf(f2,"	clc\n");
		fprintf(f2,"	add si,ax\n");
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp ebx,eax\n");
		fprintf(f2,"	jle linenos%d \n",lineno);
		fprintf(f2,"	linenoss%d:\n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i5+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i6+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i7+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edx,[si]\n");
		fprintf(f2,"	call sub%d\n",i3);
		fprintf(f2,"	linenos%d:\n",lineno);
	}
	
}



//=================================================================

int rem (){
	fprintf(f2,"; , %s\n",ss[1]);
	fprintf(f1,"; , %s\n",ss[1]);
	error=0;
	return 0;
}


//=================================================================
//string
int sstring(){
	int i;
	char *ss1;
	char *ss2;
	long l;
	if(paramets[21]==count){
		error=0;
		ss1=uppercase(ss[1]);
		i=findvar(ss1);
		if (i==-1){
			addvar (ss1);
			i=findvar(ss1);
		}else{
			error=1;
		}
		ss2=uppercase(ss[2]);
		l=atol(ss2);
		fprintf(f1,"varnext%d dd %lu\n",varnext,l);
								fprintf(f2,"	mov ecx,%lu\n",l);
								fprintf(f2,"	call RESERVES\n");
								fprintf(f2,"	mov si,varnext%d\n",varnext);
								fprintf(f2,"	cs\n");
								fprintf(f2,"	mov [si],eax\n");
		varnext++;
	}
	return 0;
}
//=================================================================

//=================================================================
//memory
int memory(){
	int i;
	char *ss1;
	char *ss2;
	long l;
	if(paramets[82]==count){
		error=0;
		ss1=uppercase(ss[1]);
		i=findvar(ss1);
		if (i==-1){
			addvar (ss1);
			i=findvar(ss1);
		}else{
			error=1;
		}
		ss2=uppercase(ss[2]);
		l=atol(ss2);
		fprintf(f1,"varnext%d dd %lu\n",varnext,l);
		varnext++;
									fprintf(f2,"	mov eax,%lu\n",l);
									fprintf(f2,"	mov bx,varnext%d\n",i+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],eax");

	}
	return 0;
}
//=================================================================

//=================================================================


int fillmmem(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
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






		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edi,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov al,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");



									addtxtbody("	mov bp,0");
									addtxtbody("	mov ds,bp");
									addtxtbody("	mov es,bp");
									addtxtbody("	call memfill");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov ds,ax");
									addtxtbody("	mov es,ax");



	}
	return 0;	
}


int copymem(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
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






		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edi,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov bx,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov esi,[bx]\n");



									fprintf(f2,"	mov bp,0\n");
									fprintf(f2,"	mov ds,bp\n");
									fprintf(f2,"	mov es,bp\n");
									fprintf(f2,"	call memcopy\n");
									fprintf(f2,"	mov ax,cs\n");
									fprintf(f2,"	mov ds,ax\n");
									fprintf(f2,"	mov es,ax\n");



	}
	return 0;	
}

int printstring(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
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
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov esi,[bx]\n");



										
										fprintf(f2,"	call len32\n");
										fprintf(f2,"	mov ecx,eax\n");
										fprintf(f2,"	call PRINT32\n");



	}
	return 0;	
}

//=================================================================
//set
int sets(){
	int i;
	char *ss1;
	char *ss2;
	long l;
	if(paramets[1]==count){
		error=0;
		ss1=uppercase(ss[1]);
		i=findvar(ss1);
		if (i==-1){
			addvar (ss1);
			i=findvar(ss1);
		}else{
			error=1;
		}
		fprintf(f1,"varnext%d db \"%s\",0\n",varnext,ss[2]);
		varnext++;
	}
	return 0;
}
//=================================================================


int timerrnd(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(2==count){

		error=0;

		ss1=uppercase(ss[1]);
		i1=findvar(ss1);
		if (i1==-1){
			printf("error var1\n");
			error=1;
		}




									fprintf(f2,"	mov si,L20\n");
									fprintf(f2,"	cs\n");
									fprintf(f2,"	mov cx,[si]\n");
									fprintf(f2,"	mov ax,4\n");
									fprintf(f2,"	add cx,ax\n");
									fprintf(f2,"	cs\n");
									fprintf(f2,"	mov [si],cx\n");
									fprintf(f2,"	mov ax,endf\n");
									fprintf(f2,"	cmp cx,ax\n");
									fprintf(f2,"	jl linenumbers%d\n",lineno);
									fprintf(f2,"	sub cx,ax\n");
									fprintf(f2,"	mov ax,257\n");
									fprintf(f2,"	add cx,ax\n");
									fprintf(f2,"	cs\n");
									fprintf(f2,"	mov [si],cx\n");
									fprintf(f2,"linenumbers%d:\n",lineno);
									fprintf(f2,"	mov si,cx\n");
									fprintf(f2,"	xor ax,ax\n");
									fprintf(f2,"	cs\n");
									fprintf(f2,"	mov eax,[si]\n");
									fprintf(f2,"	mov di,varnext%d\n",i1+varnextstart);
									fprintf(f2,"	cs\n");
									fprintf(f2,"	mov [di],eax\n");



	}
	return 0;	
}

//=================================================================


int ands(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(paramets[55]==count){

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
									addtxtbody("	and eax,ecx");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],eax");

		}
		return 0;
}

//=================================================================


int inkeys(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(2==count){

		error=0;

		ss1=uppercase(ss[1]);
		i1=findvar(ss1);
		if (i1==-1){
			printf("error var1\n");
			error=1;
		}



									fprintf(f2,"	call inkey\n");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									fprintf(f2,"	cs\n");
									fprintf(f2,"	mov [bx],ax\n");



	}
	return 0;	
}

//=================================================================

int sleeps(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
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
									fprintf(f2,"	cs\n");
									fprintf(f2,"	mov eax,[bx]\n");
									fprintf(f2,"	call sleep\n");



	}
	return 0;	
}

//=================================================================

//=================================================================


int divs(){
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
									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[si]");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ebx,[si]");
									addtxtbody("	mov ecx,0");
									addtxtbody("	mov edx,0");
									addtxtbody("	clc");
									addtxtbody("	div ebx");
									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [si],eax");

		}
		return 0;
}

//=================================================================

//=================================================================


int muls(){
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
									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[si]");
									fprintf(f2,"	mov si,varnext%d\n",i3+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov ebx,[si]");
									addtxtbody("	mov ecx,0");
									addtxtbody("	mov edx,0");
									addtxtbody("	clc");
									addtxtbody("	mul ebx");
									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [si],eax");

		}
		return 0;
}

//=================================================================

int getnumbers(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(2==count){

		error=0;

		ss1=uppercase(ss[1]);
		i1=findvar(ss1);
		if (i1==-1){
			printf("error var1\n");
			error=1;
		}

									addtxtbody("	mov bx,L50");
									addtxtbody("	mov dx,bx");
									addtxtbody("	mov cl,10");
									addtxtbody("	mov bx,dx");
									addtxtbody("	xor ch,ch");
									addtxtbody("	cs");
									addtxtbody("	mov [bx],cx");
									addtxtbody("	mov ah,0xa");
									addtxtbody("	int 0x21");
									addtxtbody("	mov si,L50");
									addtxtbody("	inc si");
									addtxtbody("	cs");
									addtxtbody("	mov al,[si]");
									addtxtbody("	mov ah,0");
									addtxtbody("	add si,ax");
									addtxtbody("	inc si");
									addtxtbody("	mov al,0");
									addtxtbody("	cs");
									addtxtbody("	mov [si],al");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov si,L50");
									addtxtbody("	inc si");
									addtxtbody("	inc si");
									addtxtbody("	call MEM32 ");
									addtxtbody("	mov esi,eax");
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	mov di,bx");
									addtxtbody("	call val");




	}
	return 0;	
}

//=================================================================

int doloops(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	int i8;
	int i9;
	char *ss1;
	if(8==count){

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

		ss1=uppercase(ss[5]);
		i5=findvar(ss1);
		if (i5==-1){
			printf("error var3\n");
			error=1;
		}

		ss1=uppercase(ss[4]);
		i4=findvar(ss1);
		if (i4==-1){
			printf("error var4\n");
			error=1;
		}


		ss1=uppercase(ss[3]);
		i3=findkey(ss1);
		if (i3<substart){
			printf("error key\n");
			error=1;
		}



		ss1=uppercase(ss[6]);
		i6=findvar(ss1);
		if (i6==-1){
			printf("error var6\n");
			error=1;
		}

		ss1=uppercase(ss[7]);
		i7=findvar(ss1);
		if (i7==-1){
			printf("error var7\n");
			error=1;
		}


		fprintf(f2,"	lineno%d:\n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	cmp eax,ebx\n");
		fprintf(f2,"	jnz linenos%d \n",lineno);
		fprintf(f2,"	mov si,varnext%d\n",i4+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov eax,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i5+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ebx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i6+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov ecx,[si]\n");
		fprintf(f2,"	mov si,varnext%d\n",i7+varnextstart);
		fprintf(f2,"	cs\n");
		fprintf(f2,"	mov edx,[si]\n");
		fprintf(f2,"	call sub%d\n",i3);
		fprintf(f2,"	jmp lineno%d \n",lineno);
		fprintf(f2,"	linenos%d:\n",lineno);
	}
	
}



//=================================================================

int lets(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	if(paramets[6]==count){

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
									fprintf(f2,"	mov bx,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],eax");

		}
		return 0;
}



//=================================================================

int evals(){
	int i;
	int i1;
	int i2;
	int i3;
	int i4;
	char *ss1;
	char *ss2;
	char *ss3;
	if(3==count){

		error=0;

		ss1=uppercase(ss[1]);
		i1=findvar(ss1);
		returneval=i1+varnextstart;
		if (i1==-1){
			printf("error var1\n");
			error=1;
		}

		ss2=ss[2];
		ss3=strstr(ss2,"!");
		if(ss3!=NULL){
			error=-1;
			printf("error ! symbol\n");
		}else{
			//printf("eval debug:,var %s:, %s\n",ss1,ss2);

			ss2=uppercase(ss[2]);
			emain(ss2);
		}
	}
	return 0;
}



//=================================================================
//eval

void evalsums(int d0,int d1,int d2){
	fprintf(f3,"\n");
	fprintf(f3,"	mov si,varnext%d\n",d1);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov eax,[si]\n");
	fprintf(f3,"	mov si,varnext%d\n",d2);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov ebx,[si]\n");
	fprintf(f3,"	clc\n");
	fprintf(f3,"	add eax,ebx\n");
	fprintf(f3,"	mov di,varnext%d\n",d0);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov [di],eax\n");
	lastslasts=d0;
}

//=================================================================

void evalsubs(int d0,int d1,int d2){
	fprintf(f3,"\n");
	fprintf(f3,"	mov si,varnext%d\n",d1);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov eax,[si]\n");
	fprintf(f3,"	mov si,varnext%d\n",d2);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov ebx,[si]\n");
	fprintf(f3,"	clc\n");
	fprintf(f3,"	sub eax,ebx\n");
	fprintf(f3,"	mov di,varnext%d\n",d0);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov [di],eax\n");
	lastslasts=d0;

}

//=================================================================

void evalmuls(int d0,int d1,int d2){
	fprintf(f3,"\n");
	fprintf(f3,"	mov si,varnext%d\n",d1);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov eax,[si]\n");
	fprintf(f3,"	mov si,varnext%d\n",d2);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov ebx,[si]\n");
	fprintf(f3,"	mov ecx,0\n");
	fprintf(f3,"	mov edx,0\n");
	fprintf(f3,"	clc\n");
	fprintf(f3,"	mul ebx\n");
	fprintf(f3,"	mov di,varnext%d\n",d0);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov [di],eax\n");
	lastslasts=d0;

}

//=================================================================

void evaldivs(int d0,int d1,int d2){
	fprintf(f3,"\n");
	fprintf(f3,"	mov si,varnext%d\n",d1);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov eax,[si]\n");
	fprintf(f3,"	mov si,varnext%d\n",d2);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov ebx,[si]\n");
	fprintf(f3,"	mov ecx,0\n");
	fprintf(f3,"	mov edx,0\n");
	fprintf(f3,"	clc\n");
	fprintf(f3,"	div ebx\n");
	fprintf(f3,"	mov di,varnext%d\n",d0);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov [di],eax\n");
	lastslasts=d0;

}

//=================================================================

void evalclears(int p1,int size){
		int i;
		char* c=&labels[p1*50];
		memset(c,0,size);
}

//=================================================================

int evalssplint(char *destiny,char *list[],char separete){
	char *v1;
	char *v2;
	char *v3;
	int count=1;
	v1=destiny;
	list[0]=v1;
	do{
		v2=v1;
		v1=strchr(v2,separete);
		v3=NULL;
		if (v1!=NULL) v3=v1+1;
		if (v1!=NULL) list[count]=v3;
		if (v1!=NULL) count++;
		if (v1!=NULL) v1[0]=0;
		v1=v3;
	}while(v1!=NULL);
	return count;
}

//=================================================================

void priorityString(int sizes)
{
    int i=0;
    int ppi=0;
    long d=0;
    long dd=0;
    char *p;
    char *p1;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
	}

}

//=================================================================


int strchr1(char *argv){
		int i=-1;
		int pos=-1;
		int size=strlen(argv);
		for (i=0;i<size;i++){
			if(argv[i]==')') {
				pos=i;
				i=size+1;				
			}
		}
		return pos;
}


//=================================================================

int evalgetnumbers(char *s1){
	int d=0;
	char *ss1;
	if (s1[0]>('0'-1) && s1[0]<('9'+1)){
		d=atoi(s1);
		fprintf (f1,"varnext%d dd  %d\n",varnext,d);
		d=varnext;
		varnext++;
	}else{
		if(s1[0]=='!'){
			ss1=&s1[1];
			d=atoi(ss1);			
		}else{
			d=getvar(s1)+varnextstart;
		}
	}
	
return d;
}

//=================================================================

int getvar(char *s1){
	int n=0;
	long d=0;
	int i1=0;

		s1=uppercase(s1);
		d=findvar(s1);
		if (i1==-1){
			printf("var %s error \n",s1);
			error=1;
		}

	return d;
}


//=================================================================


void priorityList(int sizes)
{
    int dddd=0;
    int i=0;
    int ppi=0;
    int d=0;
    int dd=0;
    char *p;
    char *p1;
nextsnexts=0;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		if (labels[i*50]!=0){
			if((labels[i*50]>'A'-1 && labels[i*50]<'Z'+1)||(labels[i*50]>'a'-1 && labels[i*50]<'z'+1)||(labels[i*50]>'0'-1 && labels[i*50]<'9'+1)||(labels[i*50]=='!')||(labels[i*50]=='-' && labels[i*50+1]!=0)){
				
				d=evalgetnumbers(p);

				
			}else{
				if (labels[i*50]=='+'){
					d=0;
				}else{
					if (labels[i*50]=='-'){
						d=0;
					}else{
						if (labels[i*50]=='/'){
							p1=&labels[(i+1)*50];
							if(d==0){
								d=varnext;
								fprintf (f1,"varnext%d dd  0\n",d);
								varnext++;
								
							}
							dddd=varnext;
							fprintf (f1,"varnext%d dd  0\n",dddd);
							varnext++;
							evaldivs(dddd,d,evalgetnumbers(p1));	
							d=dddd;
							evalclears(i-1,50*3);
							labels[i*50]='+';
							labels[(i-1)*50]='0';
							p1=&labels[(i+1)*50];
							sprintf(p1,"!%d",d);
							
						}else{
							if (labels[i*50]=='\\'){
								p1=&labels[(i+1)*50];
								if(d==0){
									d=varnext;
									fprintf (f1,"varnext%d dd  0\n",d);
									varnext++;
								}
								dddd=varnext;
								fprintf (f1,"varnext%d dd  0\n",dddd);
								varnext++;
								evaldivs(dddd,d,evalgetnumbers(p1));	
								d=dddd;
								evalclears(i-1,50*3);
								labels[i*50]='+';
								labels[(i-1)*50]='0';
								p1=&labels[(i+1)*50];
								sprintf(p1,"!%d",d);
							}else{
								if (labels[i*50]=='*'){
									p1=&labels[(i+1)*50];
									if(d==0){
										d=varnext;
										fprintf (f1,"varnext%d dd  0\n",d);
										varnext++;
									
									}
									dddd=varnext;
									fprintf (f1,"varnext%d dd  0\n",dddd);
									varnext++;
									evalmuls(dddd,d,evalgetnumbers(p1));	
									d=dddd;
									evalclears(i-1,50*3);
									labels[i*50]='+';
									labels[(i-1)*50]='0';
									p1=&labels[(i+1)*50];
									sprintf(p1,"!%d",d);

								}else{						
									printf("\n error !!!!!!!!!\n");
									error=1;
									
							}
						}
					}
				}
		}
		
		}
    }

i=i+ppi;
ppi=0;
}	
}


//=================================================================





int PrintList(int sizes)

{
    int i=0;
    int ppi=0;
    int d1=0;
    int d=0;
    int dd=0;
    char *p;
    char *p1;
    int dddd;
nextsnexts=0;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		if (labels[i*50]!=0){
			if((labels[i*50]>'A'-1 && labels[i*50]<'Z'+1)||(labels[i*50]>'a'-1 && labels[i*50]<'z'+1)||(labels[i*50]>'0'-1 && labels[i*50]<'9'+1)||(labels[i*50]=='!')||(labels[i*50]=='-' && labels[i*50+1]!=0)){
				if (i==0) {
					d=evalgetnumbers(p);
				
			}}else{
				if (labels[i*50]=='+'){
					p1=&labels[(i+1)*50];
						if(d==0){
							d=varnext;
							fprintf (f1,"varnext%d dd  0\n",d);
							varnext++;
						}
					dddd=varnext;
					fprintf (f1,"varnext%d dd  0\n",dddd);
					varnext++;
					evalsums(dddd,d,evalgetnumbers(p1));	
					d=dddd;
					ppi=1;
				}else{
					if (labels[i*50]=='-'){
						p1=&labels[(i+1)*50];
							if(d==0){
								d=varnext;
								fprintf (f1,"varnext%d dd  0\n",d);
								varnext++;
							}
						dddd=varnext;
						fprintf (f1,"varnext%d dd  0\n",dddd);
						varnext++;
						evalsubs(dddd,d,evalgetnumbers(p1));	
						d=dddd;
						ppi=1;

					}else{
						if (labels[i*50]=='/'){
						}else{
							if (labels[i*50]=='\\'){
								;
							}else{
							if (labels[i*50]=='*'){
								;
							}else{						
								printf("\n error !!!!!!!!!\n");
								error=1;		
							}
						}
					}
				}
		}
		
		}
    }

i=i+ppi;
ppi=0;
}	
	return d;
}

//=================================================================


int lists(char *argv){
    int i;
    int ii=0;
    int iii=0;
    int iiii=0;
    int ti=0;
    int t2=0;
    int t3=0;
    
    for (i = 0;i<strlen(argv); i++) {
		t2=0;
		if (i==0 && argv[i]=='-') t2=-1;
		if (t3==-1 && argv[i]=='-') t2=-1;
		if ((argv[i]=='+' || argv[i]=='-' || argv[i]=='*' || argv[i]=='/' || argv[i]=='\\' || argv[i]=='(' || argv[i]==')') && t2!=-1 ){
			if (i!=0 && iiii!=1) {
				labels[ii*50+iii]=0;
				ii++;
				iii=0;
				ti++;
				t3=-1;
			}
			labels[ii*50+iii]=(char) argv[i];
			labels[ii*50+iii+1]=0;
			ii++;
			iii=0;
			iiii=1;
			ti++;
			t3=-1;
		}else{
			if(t2==-1){
				labels[ii*50+iii]='-';
				iii++;
				iiii=0;
				i++;
			}
			labels[ii*50+iii]=(char) argv[i];
			iii++;
			iiii=0;
			t2=0;
			t3=0;
		}
		
    }
	labels[ii*50+iii+1]=0;
	return ti+1;

	}


//=================================================================


int solver(char *argv){
	int ii=0;
	int r=0;
	memset(labels,0,50*50-1);
	ii=lists(argv);
	priorityList(ii);
	priorityString(ii);
	r=PrintList(ii);
	return r;
}



//=================================================================

void params(char *argv){
	char c[1024*8];
	char cc[128];
	int i;
	int pos=0;
	int ti;
	int size=0;
	int n=1024*4;
	int counter=0;
	int cond=0;
	int d=0;
	char *p1;
	char *p2;
	char *p3;
	char *p4;
	char *p5;
	char *p6;
	char *p7;
	p1=&c[0];
	p2=&c[n];
	memset(c,0,1024*8);
	strcpy(p1,argv);
	p4=&p1[0];


	for(ti=0;ti<16000;ti++){
		size=strlen(p4);
		for (i=0;i<size;i++){
			if(p4[i]=='(') p3=&p4[i];
			if(p4[i]==')') {
				p7=&p3[1];
				p3[0]=0;
				p5=&p4[i+1];
				p4[i]=0;
				i=size+1;				
			}
		}
		

	fprintf (f1,"varnext%d dd  0\n",varnext);
	lastslasts=varnext;
	varnext++;

		d=solver(p7);
		memset(cc,0,127);

		if(counter==0){
			memset(p2,0,n);
			strcpy(p2,p4);
			sprintf(cc,"!%d",d);
			strcat(p2,cc);
			strcat(p2,p5);
			p4=&p2[0];
			pos=strchr1(p4);
			if (pos==-1)ti=16001;
		}else{
			memset(p1,0,n);
			strcpy(p1,p4);
			sprintf(cc,"!%d",d);
			strcat(p1,cc);
			strcat(p1,p5);
			p4=&p1[0];
			pos=strchr1(p4);
			if (pos==-1)ti=16001;
			
		}
		counter++;
		if(counter>1) counter=0;
	}
	d=solver(p4);
	fprintf(f3,"\n");
	fprintf(f3,"	mov bx,varnext%d\n",d);//lastslasts);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov eax,[bx]\n");
	fprintf(f3,"	mov bx,varnext%d\n",returneval);
	fprintf(f3,"	cs\n");
	fprintf(f3,"	mov [bx],eax\n");


}


//=================================================================

void emain(char *argv){
	int n=0;
	char *c0=var0;
	char *c1;
	char *c2=var2;
	char *c3=varvar;
	char *c4=var3;
	char *c5;
	char argvs[1000];
	char aargvs[1000];
	char *aargvss=aargvs;
	char *argvss;
	int vc=0;
	argvss=argvs;
	strcpy(argvss,"");
	argvss=argvs;
	strcpy(argvss,argv);
	strcpy(aargvss,"(");
	strcat(aargvss,argvss);
	strcat(aargvss,"+0)");
	params(aargvss);

}


//=================================================================

int ffloat(char *s){
	int i;
	char *ss1;
	char *ss2;
	long l;
	double dd=0;
	if(3==count){
		error=0;
		ss1=uppercase(ss[1]);
		i=findvar(ss1);
		if (i==-1){
			addvar (ss1);
			i=findvar(ss1);
		}else{
			error=1;
		}
		ss2=uppercase(ss[2]);
		dd=atof(ss2);
		dd=dd*100;
		l=(long) dd;
		fprintf(f1,"varnext%d dd %lu\n",varnext,l);
		varnext++;
									fprintf(f2,"	mov eax,%lu\n",l);
									fprintf(f2,"	mov bx,varnext%d\n",i+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],eax");


	}
	return 0;
}
//=================================================================

int printfloat(){
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
									addtxtbody("	mov si,L22");
									addtxtbody("	mov ax,cs");
									addtxtbody("	call MEM32");
									addtxtbody("	mov edi,eax");
									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	call STR32");
									addtxtbody("	mov si,L22");
									addtxtbody("	mov ax,cs");
									addtxtbody("	call MEM32");
									addtxtbody("	mov esi,eax");
									addtxtbody("	mov eax,9");
									addtxtbody("	clc");
									addtxtbody("	add esi,eax");
									addtxtbody("	mov edi,esi");
									addtxtbody("	inc edi");
									addtxtbody("	mov ecx,2");
									addtxtbody("	call MOVEMEM32");
									addtxtbody("	mov al,46");
									addtxtbody("	mov bp,0");
									addtxtbody("	mov ds,bp");
									addtxtbody("	dec esi");
									addtxtbody("	mov [esi],al");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov ds,ax");
									addtxtbody("	mov si,L22");
									addtxtbody("	mov ax,cs");
									addtxtbody("	call MEM32");
									addtxtbody("	mov esi,eax");
									addtxtbody("	call len32");
									addtxtbody("	mov ecx,eax");
									addtxtbody("	call PRINT32");



	}
	return 0;
}

//=================================================================

int tinteger(){
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

									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[si]");
									addtxtbody("	mov ebx,100");
									addtxtbody("	mov ecx,0");
									addtxtbody("	mov edx,0");
									addtxtbody("	clc");
									addtxtbody("	div ebx");
									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [si],eax");

		}
		return 0;
}

//=================================================================

int tfloat(){
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

									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[si]");
									addtxtbody("	mov ebx,100");
									addtxtbody("	mov ecx,0");
									addtxtbody("	mov edx,0");
									addtxtbody("	clc");
									addtxtbody("	mul ebx");
									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [si],eax");

		}
		return 0;
}

//=================================================================

//=================================================================

int ddouble(char *s){
	int i;
	char *ss1;
	char *ss2;
	long l;
	double dd=0;
	if(3==count){
		error=0;
		ss1=uppercase(ss[1]);
		i=findvar(ss1);
		if (i==-1){
			addvar (ss1);
			i=findvar(ss1);
		}else{
			error=1;
		}
		ss2=uppercase(ss[2]);
		dd=atof(ss2);
		dd=dd*10000;
		l=(long) dd;
		fprintf(f1,"varnext%d dd %lu\n",varnext,l);
		varnext++;
									fprintf(f2,"	mov eax,%lu\n",l);
									fprintf(f2,"	mov bx,varnext%d\n",i+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [bx],eax");


	}
	return 0;
}
//=================================================================

int tdouble(){
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

									fprintf(f2,"	mov si,varnext%d\n",i2+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov eax,[si]");
									addtxtbody("	mov ebx,10000");
									addtxtbody("	mov ecx,0");
									addtxtbody("	mov edx,0");
									addtxtbody("	clc");
									addtxtbody("	mul ebx");
									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	cs");
									addtxtbody("	mov [si],eax");

		}
		return 0;
}

//=================================================================

//=================================================================

int printdouble(){
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
									addtxtbody("	mov si,L22");
									addtxtbody("	mov ax,cs");
									addtxtbody("	call MEM32");
									addtxtbody("	mov edi,eax");
									fprintf(f2,"	mov si,varnext%d\n",i1+varnextstart);
									addtxtbody("	call STR32");
									addtxtbody("	mov si,L22");
									addtxtbody("	mov ax,cs");
									addtxtbody("	call MEM32");
									addtxtbody("	mov esi,eax");
									addtxtbody("	mov eax,9");
									addtxtbody("	clc");
									addtxtbody("	add esi,eax");
									addtxtbody("	mov edi,esi");
									addtxtbody("	inc edi");
									addtxtbody("	mov ecx,4");
									addtxtbody("	call MOVEMEM32");
									addtxtbody("	mov al,46");
									addtxtbody("	mov bp,0");
									addtxtbody("	mov ds,bp");
									addtxtbody("	dec esi");
									addtxtbody("	dec esi");
									addtxtbody("	dec esi");
									addtxtbody("	mov [esi],al");
									addtxtbody("	mov ax,cs");
									addtxtbody("	mov ds,ax");
									addtxtbody("	mov si,L22");
									addtxtbody("	mov ax,cs");
									addtxtbody("	call MEM32");
									addtxtbody("	mov esi,eax");
									addtxtbody("	call len32");
									addtxtbody("	mov ecx,eax");
									addtxtbody("	call PRINT32");



	}
	return 0;
}

//=================================================================









