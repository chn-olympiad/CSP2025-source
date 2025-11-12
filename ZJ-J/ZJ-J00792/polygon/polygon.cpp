#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n;
int a[5005];
bool vis[5005];
unsigned long long v[5005][5005];
unsigned long long ans=0;
void dfs(int x,int dqwz,int mx,int sum){
	if(x>=3&&mx*2<sum){
		ans++;
		ans%=M;
	}
	for(int i=dqwz;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			int p=max(mx,a[i]);
			dfs(x+1,i,p,sum+a[i]);
			vis[i]=0;
		}
	}
}
int lll,ppp,ooo,kkk,jjj,asdfghjkl,zxc;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,1,0,0);// ji ge shu    mx   zong he     
		cout<<ans%M;
	}else{
		unsigned long long p=1,x=2;
		for(int i=3;i<=n;i++){
			v[1][i]=v[1][i-1]+p;
			v[1][i]%=M;
			p+=x;
			x++;
		}
		p=4;
		for(int i=2;i<=n;i++){
			v[i][p]=1;
			for(int j=p+1;j<=n;j++){
				v[i][j]=v[i][j-1]+v[i-1][j-1];
				v[i][j]%=M;
			}
			p++;
		}
		for(int i=1;i<=n;i++){
			ans+=v[i][n];
			ans%=M;
		}
		cout<<ans;
	}
	return 0;
}
