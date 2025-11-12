#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mo=998244353;
const int maxn=5005;
ll n;
ll a[maxn];
ll b[maxn];
bool vis[maxn];
ll sum,ans,num,tmp;

void dfs(int x,int y,int z){
	if(y>tmp-3||x>sum){
		return;
	}
	ans++;
	for(int i=z+1;i<=tmp-1;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+a[i],y+1,i);
			vis[i]=0;
		}
	}
	
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num=max(num,a[i]);
	}
	if(num==1){
		int x=0;
		x=pow(2,n)-((n*n)+n)/2-1;
		cout<<x;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	} 
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(a[1]+a[2]>a[3])ans++;
	for(int i=4;i<=n;i++){
		if(b[i]<=2*a[i])continue;
		sum=b[i]-2*a[i]-1;
		tmp=i;
		memset(vis,0,sizeof(vis));
		dfs(0,0,0);
//		for(int j=1;j<=i-1;j++){
//			if(a[j]<=sum)ans++;
//		}
	}
	ans%=mo;
	cout<<ans;
	return 0;
}


