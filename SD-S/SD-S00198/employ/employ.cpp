#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;

int n,m;

string s;

struct ss{
	int id,c;
}b[N];

int a[N];
int c[N];

int ans=0;

int vis[N];

void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=b[c[i]].c){
				cnt++;
				continue;
			}
			if(a[i]==0){
				cnt++;
			}
		}
		if(n-cnt>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			c[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
	
}

signed main(){
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		a[i+1]=s[i]-'0';
	}
	
	for(int i=1;i<=n;i++){
		cin>>b[i].c;
		b[i].id=i;
	}
	
	dfs(1);
	
	cout<<ans;
	
	return 0;
} 
