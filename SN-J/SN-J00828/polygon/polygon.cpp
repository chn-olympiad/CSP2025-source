#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Q=998244353;
bool flag=0;
int n,a[5005],m,ans=0;
void dfs(int x,int y,int maxn,int num){
	if(y==m){
		if(num>2*maxn) ans++;
		return ;
	}
	if(x>n) return ;
	dfs(x+1,y,maxn,num);
	dfs(x+1,y+1,max(maxn,a[x]),num+a[x]);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=1;
	}
	//特例都为1 
	if(!flag){
		int num=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) num++;
		}
		for(int i=3;i<=num;i++){
			int s=1; 
			for(int j=1;j<=i;j++) s=(s*(num-j+1))%Q;
			ans=(ans+s)%Q;
		}
		cout<<ans%Q<<endl;
		return 0;
	}
	for(m=3;m<=n;m++) dfs(1,0,0,0);
	cout<<ans%Q;
	return 0;
}
//64分 
