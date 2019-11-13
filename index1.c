
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define textsize 900000
#define nlines 12000

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
int count;
int tindex=0;
char s[textsize];
char *ss[500];
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
FILE *f1;
FILE *f2;


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
			system("nasm -o out.com index.dat");
			printf("\ndone...\nopen file index.dat and index1.dat to see codes\n");
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
	if (n==2) error=0;
	if (n==3) echos();
	if (n==5) iinteger(ss[1]);
	if (n==93) declair(ss[1]);
	if (n==94) function(ss[1]);
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
			addcode ("section .text");
			addcode ("org 0x100");
			addcode ("main1:");
			addcode ("jmp start");
			addcode ("db 'build in index32 developer tools.... '");
	fprintf(f1,"\nechos:\nmov ah,9\nint 0x21\nret\n");
	fprintf(f1,"\nvarm1 db 13,10,\"press key to continue ,esc to exit\",13,10,\"$\"\n");
	fprintf(f1,"\nkey:\nmov dx,varm1\ncall echos\nmov ah,0\nint 0x16\ncmp al,27\njz keyesc\nret\nkeyesc:\njmp exit\nret\n");
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
			addcode ("          mov [si+1],al        ");   
			addcode ("          cs             ");   				
			addcode ("          mov [si],dl ");
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
		addkey ("like",4); //13
		addkey ("diferent",4); //14
		addkey ("big",4); //15
		addkey ("less",4); //16
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
		addkey ("for",5); //29
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
		varsart=cursor;
		substart=subcursor;
}

//=================================================================
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
			addtxtbody("	mov bx,x");
			addtxtbody("	mov ax,0");	
			addtxtbody("	cs");	
			addtxtbody("	mov [bx],ax");	
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
		error=0;
	}
	return 0;
}


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














