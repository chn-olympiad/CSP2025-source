#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5000+10;
const int inf=0x3f3f3f3f3f;
int a[N];
int ts[N];
int n,ans=0;
void dfs(int now,ll sum,int maxx){
	if(now==n+1){
		if(sum>maxx*2){
			ans++;
		}
		return ;
	}
	//cout<<now<<endl;
	dfs(now+1,sum,maxx);
	dfs(now+1,sum+a[now],max(maxx,a[now]));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//don't forget to delete the '//' 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag){
		int k=1;
		for(int i=3;i<=n;i++){
			ts[i]=ts[i-1]*2+k;
			k+=i-1;
		}
		cout<<ts[n]<<endl;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans/2<<endl;
	return 0;
}
