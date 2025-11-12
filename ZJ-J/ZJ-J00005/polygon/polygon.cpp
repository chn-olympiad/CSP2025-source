#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,MOD=998244353;
int n,a[N],m;
long long sum,shu,c[1005][1005];
void dfs(int s,int f,int m,int t){
	if(f==m){
		if(s>t) shu++;
		return;
	}
	for(int i=0;i<=1;i++){
		if(i==1) s+=a[f];
		f++;
		dfs(s,f,m,t);
		f--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],m=max(a[i],m);
	if(m==1){
		for(int i=1;i<=500;i++){
			c[i][0]=c[i][i]=1;
			c[i][1]=i;
		}
		for(int i=3;i<=500;i++){
			for(int j=2;j<=i;j++){
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
		}
		for(int i=3;i<=n;i++){
			sum=(sum+c[n][i])%MOD;
		}
		cout<<sum;
	}else{
		sort(a+1,a+n+1);
		for(int i=3;i<=n;i++){
			shu=0;
			dfs(0,1,i,a[i]);
			sum+=(shu%MOD);
		}
		cout<<sum;
	}
	return 0;
}
