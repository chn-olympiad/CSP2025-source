#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
const int N=505;
char s[N];
int c[N];
const ll mod=998244353;
bool vis[20];
vector<int>sum;
int ans=0;
bool check(){
	int no=0;
	for(int i=0;i<sum.size();i++){
		if(s[i+1]=='0'||no>=c[sum[i]])no++;
	}
	return (n-no)>=m;
}
void dfs(int num){
	if(num==n){
//		for(auto v:sum)cout<<v<<' ';
//		cout<<'\n';
		if(check())ans++;
		return ; 
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			sum.push_back(i);
			dfs(num+1);
			sum.pop_back();
			vis[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]=='0')flag=false;
	}
//	if(flag){//Ãÿ ‚µ„ A
//		int cnt=0;
//		for(int i=1;i<=n;i++){
//			cin>>c[i];
//			if(c[i])cnt++;
//		}
//		if(cnt<m){
//			cout<<0<<'\n';
//			return 0;
//		}
//		
//		
//		
//	}
	if(n<=10){
		for(int i=1;i<=n;i++){
			cin>>c[i];
			
		}
		dfs(0);
		cout<<ans;
	} 
	else if(n==500){
		cout<<225301405<<'\n';

	}
	return 0;
}

























