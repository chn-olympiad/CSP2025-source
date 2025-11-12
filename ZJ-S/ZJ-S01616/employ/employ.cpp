#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505,TT=998244353;
int n,m,ez,c[maxn],f[maxn][maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f^=!(ch^'-'),ch=getchar();
	while( isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*(f-(f^1));
}
void get_date(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while( isdigit(ch)){
		if(ch=='1') ez++;
		ch=getchar();
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();get_date();
	for(int i=1;i<=n;i++) c[i]=read();
	int cnt=0;
	for(int i=1;i<=n;i++) if(c[i]==0) cnt++;
	if(ez-cnt<m){
		printf("0\n");
		return 0;
	}
	if(ez==n){
		int sum=1;
		for(int i=1;i<=n;i++) sum=sum*i%TT;
		printf("%lld\n",sum);
		return 0;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=ez;j++){
		if(i==1){f[i][j]=1;continue;}
		for(int k=i-c[i];k<i;k++)
			f[i][j]+=f[k][j-1],f[i][j]%=TT;	
		for(int k=1;k<i;k++)
			f[i][j]+=f[k][j],f[i][j]%=TT;
	}
	printf("%lld\n",f[n][ez]);
	return 0;
}