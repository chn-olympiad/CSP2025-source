#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=1e5;
int p[N],sum,i,n,m,c[N],f[110][110][110],fl[N],su[N];
char s[N];
void sc(int x,int pass,int out){
	if(m-pass>p[pass+out+1])return ;
	if(pass>=m||f[x][pass][out]){
		f[x][pass][out]=su[n-pass-out];
		sum=(sum+f[x][pass][out])%mod;
		return ;
	}
	int i;
	for(i=1;i<=n;i++)
	  if(fl[i]==0){
	  	fl[i]=1;
	  	if(s[pass+out+1]=='0')sc(i,pass,out+1);
	    else if(c[i]<=out)sc(i,pass,out+1);
	    else sc(i,pass+1,out);
		fl[i]=0;
	  }
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s+1;
	su[0]=1;
	for(i=n;i>=1;i--)p[i]=p[i+1]+(s[i]=='1');
	for(i=1;i<=n;i++)cin>>c[i];
	for(i=1;i<=n;i++)su[i]=su[i-1]*i;
	sort(c+1,c+1+n);
	if(n<=100){
		sc(0,0,0);
		cout<<sum;
		return 0;
	}
	/*
	for(i=1;i<=n;i++)   //i=pass+out
	  for(j=1;j<=i;j++)  //j=pass
	  	for(k=1;k<=n;k++)  //k=x
	*/	  
	return 0;
}
