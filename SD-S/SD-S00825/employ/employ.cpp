#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,nd[510],c[510],ans,vis[510];
string s;
vector<int> q;
void dfs(int x){
	if(x>n){
		int cnt=0,sum=n;
		for(int i=0;i<q.size();i++){
		//	cout<<c[q[i]]<<' ';
			if(cnt>=c[q[i]]){
				cnt++;
				sum--;
			}
			if(nd[i+1]==0){
				cnt++;
				sum--;
			}
		}//cout<<endl;
		if(sum>=m) ans++;
		ans%=mod;//cout<<sum<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			q.push_back(i);
			dfs(x+1);
			vis[i]=0;
			q.pop_back();
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	int f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			f=1;
		}
		nd[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",c+i);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
 }


