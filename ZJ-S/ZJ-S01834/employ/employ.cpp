#include<bits/stdc++.h>
#define mo 998244353
using namespace std;
int n,m,s[501],c[501],a1[11],b1[11],ff,s2[1<<18],f2[1<<18][20],b[501];
long long ss,f[501][501];
void aa1(int i){
	if(i>n){
		int s1=0;
		for(int j=1;j<=n;j++)s1+=(c[a1[j]]<=s1||s[j]==0);
		ss+=(s1<=n-m);
		return;
	}
	for(int j=1;j<=n;j++)if(!b1[j])b1[j]=1,a1[i]=j,aa1(i+1),b1[j]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+1+n);
	if(n<=10){
		aa1(1);
		cout<<ss;
		return 0;
	}
	if(n<=18){
		f2[0][0]=1;
		for(int i=0;i<=(1<<n)-1;i++){
			int xx=i;
			while(xx)s2[i]+=xx&1,xx>>=1;
		}
		for(int i=0;i<(1<<n)-1;i++){
			for(int j=1;j<=n;j++){
				if(!((i>>(j-1))&1)){
					for(int k=0;k<=s2[i];k++){
						f2[i^(1<<(j-1))][k+!!(k>=c[j]||s[s2[i]+1]==0)]=(f2[i^(1<<(j-1))][k+!!(k>=c[j]||s[s2[i]+1]==0)]+f2[i][k])%mo;
					}
				}
			}
		}
		for(int i=0;i<=(n-m);i++)ss=(ss+f2[(1<<n)-1][i])%mo;
		cout<<ss;
		return 0;
	}
	for(int i=1;i<=n;i++)b[c[i]]++;
	for(int i=1;i<=n;i++)b[i]+=b[i-1];
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(s[i]==1)f[i][j]=(f[i][j]+f[i-1][j]*(n-b[j]-(i-j)))%mo,f[i][j+1]=(f[i][j+1]+f[i-1][j]*(b[j]-j));
			else f[i][j+1]=(f[i][j+1]+(n-i)*f[i-1][j])%mo;
		}
	}
	for(int i=0;i<=(n-m);i++)ss=(ss+f[n][i])%mo;
	cout<<(ss+mo)%mo;
	return 0;
}

