/*
*  kernel.c
*/
#define addr(idx, off) (idx * 256 + off)
void print_str(char *buf);

void kernel(void)
{
	char *str = "costa ricaaa";
	//init_syscalls(); // ecrase interruption 80 pour la notre
	//print_string(str);
	print_str("hello");
	//interrupt(0x80,1,&str,0,0,0);
	while(1); 	// évite d'aller lire plus loin
}

void print_str(char *buf){ 
/*
	int ax = addr(0x0E,buf);
	int bx = addr(0x0,0x07);
	interrupt(0x10, ax, bx, 0, 0,0);*/
	int i=0; 
	int ax;
	int bx = addr(0x0, 0x07);
	for(i=0;buf[i]!='\0';i++){ 
		char al = buf[i];
		ax = addr(0x0E,buf[i]);
		interrupt(0x10, ax, bx, 0, 0,0);
	}
	
}