#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long a=0;
	short b=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') b=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<3)+(a<<1)+c-48;
		c=getchar();
	}
	return a*b;
}
int ac[100005][3];
int f[305][305][305];
int dp(int n,int a,int b){
	if(n==0) return 0;
	if(f[n][a][b]>0) return f[n][a][b];
	int c=n-a-b,ans=0;
	if(a) ans=max(ans,dp(n-1,a-1,b)+ac[n][0]);
	if(b) ans=max(ans,dp(n-1,a,b-1)+ac[n][1]);
	if(c) ans=max(ans,dp(n-1,a,b)+ac[n][2]);
	return f[n][a][b]=ans; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	for(int i=1;i<=T;i++){
		int n=read();
		for(int i=1;i<=n;i++){
			ac[i][0]=read();
			ac[i][1]=read();
			ac[i][2]=read();
		}
		cout <<dp(n,n/2,n/2);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}