#include<bits/stdc++.h>
using namespace std;
long long int n,m,ans,num;
const int N=550;
const long long int M=998244353;
int a[N],c[N];
bool vis[N];
char c1;
void dfs(int k,int num,int cnt){
	if(num>n-m) return ;
	if(k+num==n){
		ans++;
		ans=ans%M;
		//cout<<num<<endl;
		return ;
	}if(cnt==n+1) return ;
	for(int i=1;i<=n;i++){
		//cout<<i<<' '<<vis[i]<<' '<<k<<' '<<num<<endl;
		if(!vis[i]){
			//cout<<i<<' ';
			vis[i]=true;
			if(num>=c[i] or a[cnt]==0) dfs(k,num+1,cnt+1);
			else dfs(k+1,num,cnt+1);
			vis[i]=false; 
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c1;
		a[i]=c1-48;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0,0,1);
	cout<<ans;
	return 0;
}
