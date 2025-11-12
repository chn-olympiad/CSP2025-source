#include<bits/stdc++.h>
using namespace std;
string s1[200009],s2[200009];
int n,m;
int ans=0;
unordered_map<string,int> ma;
void dfs(string a,string b,int c){
	if(a==b){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		int x=0;
		while(x=a.find(s1[i],x)){
			int l=s1[i].size();
			for(int j=0;j<l;j++){
				a[j+x]=s2[i][j];
			}
			if(ma[a]==c+1)continue;
			ma[a]=c+1;
			dfs(a,b,c+1);
			for(int j=0;j<l;j++){
				a[j+x]=s1[i][j];
			}
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++){
		ans=0;
		string s3,s4;
		cin>>s3>>s4;
		dfs(s3,s4,0);
		cout<<ans;
	}
	
	return 0;
}
