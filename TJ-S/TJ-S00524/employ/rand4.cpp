#include<cstdio>
#include<cstdlib>
#include<ctime>
int r16(){return rand()%32768;}
int r32(){return r16()<<15|r16();}
int rd(int l,int r){
	return r32()%(r-l+1)+l;
}

int main(){
	freopen(".in","w",stdout);
	srand(time(NULL));
	return 0;
}

