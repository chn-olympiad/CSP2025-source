#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,ans,sz[200100];
string s[200100][5],t1,t2;
vector<int>S[30];
bool cmp(int x,int y){
	return sz[x]<sz[y];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2],sz[i]=s[i][1].size();
		S[s[i][1][0]-'a'+1].push_back(i);
	}
	for(int i=1;i<=26;i++)sort(S[i].begin(),S[i].end(),cmp);
	while(q--){
		ans=0;
		cin>>t1>>t2;
		int len=t1.size();
		for(int i=0;i<len;i++){
			for(int j:S[t1[i]-'a'+1]){
				if(sz[j]>len-i)break;
				if(t1.substr(i,sz[j])==s[j][1]){
					string x=t1;
					t1.replace(i,sz[j],s[j][2]);
					if(t1==t2)++ans;
					t1=x;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
