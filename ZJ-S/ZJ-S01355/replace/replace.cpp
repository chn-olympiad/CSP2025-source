#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int ans=0,n,q,cnt;
string x[N],y[N];
bool ck(string a,string b,int i,int j){
	string c;
	for(int k=i;k<=j;k++) c+=a[k];
	return c==b;
}
void bfs(string st,string t){
	queue<string> q;
	q.push(st);
	while(!q.empty()){
		cnt++;
		string u=q.front();q.pop();
		if(u==t){
			ans++;
		}
		if(cnt>=2) continue;
		for(int i=1;i<=n;i++){
			for(int j=0;j<u.size();j++){
				if(j+x[i].size()-1>u.size()) continue;
				string s=u;
				if(ck(s,x[i],j,j+x[i].size()-1)){
					int cnt=0;
					for(int k=j;k<=j+x[i].size()-1;k++) s[k]=y[i][cnt++];
					q.push(s);
				}
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdin);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	while(q--){
		string s,e;cin>>s>>e;
		ans=0;bfs(s,e);
		cout<<ans<<"\n";
	}
}