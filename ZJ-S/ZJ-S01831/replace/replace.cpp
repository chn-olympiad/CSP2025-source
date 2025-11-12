#include<bits/stdc++.h>
using namespace std;
string s[200001],e[200001];
int vis[200001],vis1[200001];
int ans=0;
int n,q;
void DFS(string s1,string s2){
	if(s1==s2){
		ans++;
		return ;
	}
	int len=s1.size();
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		int len1=s[i].size();
		for(int j=0;j<len-len1+1;j++){
			if(vis1[j])continue;
			string tmp=s1.substr(j,len1);
			if(tmp==s[i]){
				string aa=s1;
				aa.erase(j,len1);
				aa.insert(j,e[i]);
				vis[i]=1;
				vis1[j]=1;
				DFS(aa,s2);
				vis[i]=0;
				vis1[j]=0;
			}
		}
	}
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i]>>e[i];
	for(int i=1;i<=q;i++){
		string ss,ee;cin>>ss>>ee;
		memset(vis,0,sizeof(vis));
		ans=0;
		DFS(ss,ee);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
