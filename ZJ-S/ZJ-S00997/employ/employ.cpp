#include<bits/stdc++.h>
using namespace std;
bool b[100005];
int s[100005];
int n,m;
int z[15];
bool Use[15];
int ans=0;
void solve(int x){
	if(x==n){
		int checkin=0,checkout=0;
		for(int i=1;i<=x;i++){
			if(checkout>=s[z[i]])checkout++;
			else if(b[i])checkin++;
			else checkout++;
		}
		if(checkin>=m){
			ans++;
			if(ans>=998244353)ans-=998244353;
	//		for(int i=1;i<=x;i++)printf("%d ",z[i]);
	//		putchar('\n');
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!Use[i]){
			z[x+1]=i;
			Use[i]=1;
			solve(x+1);
			Use[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool A=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch<'0'||ch>'1')ch=getchar();
		b[i]=ch-'0';
		if(b[i]==0)A=0;
	//	printf("b[%d]=%d\n",i,b[i]);
	}
	int B=0;
	for(int i=1;i<=n;i++){
		scanf("%d",s+i);
		if(s[i]==0)B++;
	}
	if(n==m){
		long long Quan=1;
		for(int i=n;i>1;i--)Quan=Quan*i%998244353;
		if(A && B==0)printf("%lld\n",Quan);
		else puts("0");
		return 0;
	}
	else if(n<=10){
		solve(0);
		printf("%d\n",ans);
	} 
	else puts("0");
}
/*
10 10
1111111101
1 1 1 1 1 1 1 1 1 1
*/
