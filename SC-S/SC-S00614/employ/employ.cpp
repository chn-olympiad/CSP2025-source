#include<bits/stdc++.h>
using namespace std;
int a[20],b[20],n,m,mod=998244353,ans;
string s;
void dfs(int d,int sum,int c){
	if(d==n){
		//cout<<sum<<" "<<c<<"\n";
		ans+=(sum>=m);
		return;
	}
	for(int i=0;i<n;i++){
		if(b[i])continue;
		b[i]=1;
		if(s[d]=='0' || c>=a[i]){
			dfs(d+1,sum,c+1);
		}
		else dfs(d+1,sum+1,c);
		b[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//测试点1~2 目标8分
	cin>>n>>m;
	if(n<=10){
		cin>>s;
		for(int i=0;i<n;i++)cin>>a[i];
		dfs(0,0,0);
		cout<<ans;
	}else{
		cout<<"答案加载中 请稍后...";
	}
	return 0;
}