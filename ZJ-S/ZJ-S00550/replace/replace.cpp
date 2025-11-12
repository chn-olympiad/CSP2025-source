#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long n,q,si,ans;
struct hd{
	string a,b;
}s[N];
int vis[N];
void dfs(string x,string y){
	if(x==y){
		ans++;
		return;
	}
	for(int i=1;i<=si;i++){
		if(vis[i])continue;
		vis[i]=1;
		int t=0;
		while(1){
			t=x.find(s[i].a,t);
			if(t>=x.size()||t==-1){
				break;
			}
			string s2=x;
			for(int j=t;j<t+s[i].b.size();j++)s2[j]=s[i].b[j-t];
			t+=s[i].b.size();
			dfs(s2,y);
		}
		vis[i]=0;
	}
	return;
}
int main(){
	 freopen("replace.in","r",stdin);
	 freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		if(x!=y)s[++si].a=x,s[si].b=y;
	}string a,b;
	for(int i=1;i<=q;i++){
		ans=0;
		string x,y;
		cin>>x>>y;
		dfs(x,y);
		cout<<ans<<"\n";
	}
	return 0;
}
 
