#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5005];
int n;
int dfs(int x,int len,int maxx){
	int cnt=0;
	if(x>n){
		if(len>maxx*2){
			return 1;
		}else{
			return 0; 
		}
	}
	cnt+=dfs(x+1,len+a[x],max(maxx,a[x]));
	cnt+=dfs(x+1,len,maxx);
	return cnt;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,0,0);
	return 0;
}
