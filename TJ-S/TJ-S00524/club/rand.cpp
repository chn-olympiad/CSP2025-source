#include<cstdio>
#include<cstdlib>
#include<ctime>
int r16(){return rand()%32768;}
int r32(){return r16()<<15|r16();}
int rd(int l,int r){
	return r32()%(r-l+1)+l;
}

int N = 2,V = 5;

void gen(){
	int n = rd(1,N);
	n*=2;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) printf("%d %d %d\n",rd(0,V),rd(0,V),rd(0,V));
}
int main(){
	freopen("club.in","w",stdout);
	srand(time(NULL));
	int t = rd(1,N);
	printf("%d\n",t);
	while(t--) gen();
	srand(time(NULL));
	return 0;
}

