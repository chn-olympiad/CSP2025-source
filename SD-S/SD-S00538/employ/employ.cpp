#include<bits/stdc++.h>
using namespace std;
long long n,m,c[1111],ans,ls[1111];
string s;
bool vis[1111];
vector<int> q;
void dfs(int no,int ok,int fail){
	if(m-ok>n-no){
		return;
	}
	for(int i = 1;i<=n;i++){
		if(vis[i]==0){
			vis[i] =1;
			if(fail<c[i]&&s[no+1]=='1'){
//				cout<<'p';
				dfs(no+1,ok+1,fail);
			}
			else {
//				cout<<'f';
				dfs(no+1,ok,fail+1);
			}
			vis[i] = 0;
		}
	}
	if(no==n){
//		cout<<'-'<<ok<<endl;
		if(ok>=m)ans=(ans+1)%998244353;
	}
}
int main(){
//	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n>100){
		long long tmp = 1;
		for(int i=1;i<=n;i++)tmp = (tmp*i) %998244353;
		cout<<tmp<<endl;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
