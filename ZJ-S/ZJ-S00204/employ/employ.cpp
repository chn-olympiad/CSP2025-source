#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	char c=getchar();x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
const int N=505,P=998244353;
int n,m,a[N];
char c[N];
void work1(){
	int t=0,s=1;
	for (int i=1;i<=n;i++)
		if(a[i]==0)return printf("0\n"),void();
	for (int i=1;i<=n;i++)s=1ll*s*i%P;
	printf("%d\n",s);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);read(m);
	scanf("%s",c+1);
	for (int i=1;i<=n;i++)read(a[i]);
	if(m==n){work1();return 0;}
	work2();
}
