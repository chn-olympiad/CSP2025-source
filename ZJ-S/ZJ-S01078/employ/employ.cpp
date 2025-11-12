#include<bits/stdc++.h>
using namespace std;

const int N=505,mod=998244353;
int n,m;
char s[N];
int c[N];
int f[1<<18][20];

int cont(int x){
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}

int dfs(int sta,int num){//cout<<sta<<endl;
	if(f[sta][num]==-1){
		int x=cont(sta)+1;
		if(x>n){
			if(n-num>=m) return f[sta][num]=1;
			else return f[sta][num]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if((sta&(1<<i-1))==0){
				if(s[x]=='0'||num>=c[i]) ans=(ans+dfs((sta|(1<<i-1)),num+1))%mod;
				else ans=(ans+dfs((sta|(1<<i-1)),num))%mod;
			}
		}
		f[sta][num]=ans;
	} 
	return f[sta][num];	
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(f,-1,sizeof(f));
	scanf("%d%d",&n,&m);
	scanf("%s",(s+1));
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(n<=20) printf("%d",dfs(0,0));
	else printf("0");
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
