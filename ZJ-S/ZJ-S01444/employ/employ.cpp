#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
const int mod=998244353;
int n,m,a[N],p[N],cot;
long long ans;
string s;
bool vis[N];
void dfs(int i){
	if(i==n+1){
		int cnt=0,c=0;
		for(int i=1;i<=n;i++)
			if(cnt>=a[p[i]]||s[i]=='0')cnt++;
			else c++;
		if(c>=m)
			ans=(ans+1)%mod;
		return ;
	}
	for(int x=1;x<=n;x++)
		if(vis[x]==0){
			vis[x]=1;
			p[i]=x;
			dfs(i+1);
			vis[x]=0;
			p[i]=0;
		}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	system("fc employ.out employ3.ans");
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	bool flag=1;
	for(int i=1;i<=n;i++)
		if(s[i]!='1'){
			flag=0;
			break;
		}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)cot++;
	}
	if(n<=18){
		dfs(1);
		cout<<ans;
	}
	else if(flag==1){
		ans=1;
		for(int i=1;i<=n-m+1;i++)ans=ans*i%mod;
		cout<<ans;
	}
	return 0;
}
//n<=18 20pts Yes
//A 20pts No
//B 12pts No

//now 20pts