#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
int n,m,c,f[505][505];
char s[505];
ll ans,tmp;
using namespace std;
int read(){
	int x=0,f=1;char aa=getchar();
	while(aa<'0'||aa>'9'){
		if(aa=='-')f=-1;
		aa=getchar();
	}
	while('0'<=aa&&aa<='9'){
		x=x*10+aa-'0';
		aa=getchar();
	}
	return x*f;
}
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	f[0][0]=1;
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;
		}
	}
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c>i)tmp++;
	}
	for(int i=tmp+1;i<=n+1;i++)ans=(ans+f[n+1][i])%mod;
	cout<<ans;
	
	return 0;
}
