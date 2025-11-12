#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	for(;c>'9'||c<'0';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
signed main(){
	srand(time(0));
	freopen("rand.in","w",stdout);
	int n=10000,m=1000000,k=10;
	printf("%d %d %d\n",n,m,k);
	for(int i=1;i<n;i++){
		printf("%d %d %d\n",i,i+1,rand()+1);
	}
	for(int i=n;i<=m;i++){
		printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()+1);
	}
	for(int i=1;i<=k;i++){
		printf("%d ",rand()+1);
		for(int j=1;j<=n;j++){
			printf("%d ",rand()+1);
		}
		printf("\n");
	}
	return 0;
}
