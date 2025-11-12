#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
int ans=0;
string s[N][2];
string t1,t2;
void dfs(int nn,string ss,int l){
	if(ss==t2){
		ans++;
		return;
	}
	if(nn==n+1){
		return;
	}
	bool mainflag=false;
	int nnn=-1;
	for(int i=l;i<ss.size();i++){
		if(ss[i]==s[nn][0][0]){
			if(ss.size()-i<s[nn][0].size()){
				continue;
			}
			bool flag=true;
			for(int j=1;j<s[nn][0].size();j++){
				if(ss[i+j]!=s[nn][0][j]){
					flag=false;
					break;
				}
			}
			if(flag){
				mainflag=true;
				nnn=i;
				break;
			}
		}
	}
	if(mainflag){
		dfs(nn,ss.replace(nnn,s[nn][0].size(),s[nn][1]),l+1);
		dfs(nn,ss,l+1);
	}else{
		dfs(nn+1,ss,0);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		dfs(1,t1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
