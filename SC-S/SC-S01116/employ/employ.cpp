#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[510];string s;
int cho[20];
bool check[20];
int ans=0;int n,m;
void dfs(int x){
	if(x>n){
		int tot=0,w=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				w++;
			}else{
				if(w>=c[cho[i]])w++;
				else tot++;
			}
		}
		if(tot>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!check[i]){
			check[i]=1;
			cho[x]=i;
			dfs(x+1);
			check[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}
