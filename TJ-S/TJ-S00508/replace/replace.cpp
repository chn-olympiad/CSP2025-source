/*
5 1
aabaa aaaab
aabaa baaaa
baaaa aaaab
baaaa abaaa
abaaa aaaab
aabaa aaaab



*/ 
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
int n,q;
string a[200010], b[200010];
string aska[200010], askb[200010];
vector< vector<int> >g;
int gsize;
bool isSpecial(string s){
	gsize=max(gsize,(int)s.size());
	int len=s.size();
	int ca=0,cb=0;
	for(int i=0;i<len;i++){
		if(s[i]!='a' && s[i]!='b') return 0;
		if(s[i]=='a') ca++;
		if(s[i]=='b') cb++;
	}
	if(cb==1) return 1;
	else return 0;
}
bool vis[5000010];
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(!isSpecial(a[i]) || !isSpecial(b[i])) flag=0;
	}
	for(int i=1;i<=q;i++){
		cin>>aska[i]>>askb[i];
		if(!isSpecial(aska[i]) || !isSpecial(askb[i])) flag=0;
	}
	if(flag){
		g.resize(gsize+1);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			int len=a[i].size();
			int p,q;
			for(int j=0;j<len;j++){
				if(a[i][j]=='b'){
					p=j;
					break;
				}
			}
			for(int j=0;j<len;j++){
				if(b[i][j]=='b'){
					q=j;
					break;
				}
			}
			g[p].push_back(q);
		}
		for(int i=1;i<=q;i++){
			int len=aska[i].size();
			int p,q;
			for(int j=0;j<len;j++){
				if(aska[i][j]=='b'){
					p=j;
					break;
				}
			}
			for(int j=0;j<len;j++){
				if(askb[i][j]=='b'){
					q=j;
					break;
				}
			}
			queue<int> qu;
			qu.push(p);
			vis[p]=1;
			int ans=0;
			while(!qu.empty()){
				int u=qu.front();
				qu.pop();
				for(int rf=0;rf<g[u].size();rf++){
					int v=g[u][rf];
					if(vis[v]) continue;
					if(v==q){
						++ans;
						continue;
					}
					vis[v]=1; 
					qu.push(v);
				}
			}
			cout<<ans<<"\n";
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
