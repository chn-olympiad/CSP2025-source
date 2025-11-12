#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=200005;
const int INF=0x3f3f3f3f;
string s[N][2];
int l[N];
vector<int> G[26];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		l[i]=(int)s[i][0].size();
		G[s[i][0][0]-'a'].push_back(i);
	}
	for(int i=0;i<26;i++){
		sort(G[i].begin(),G[i].end(),[&](int x,int y){return l[x]<l[y];});
	}
	for(int _=1;_<=q;_++){
		string t1,t2;
		cin>>t1>>t2;
		int len=(int)t1.size();
		int cnt=0;
		for(int j=0;j<len;j++){
			if(j!=0&&t1[j-1]!=t2[j-1]) break;
			for(auto id:G[t1[j]-'a']){
				if(j+l[id]-1>=len) break;
				if(s[id][0]!=t1.substr(j,l[id])) continue;
				string tmp=t1.substr(0,j)+s[id][1];
				if(j+l[id]<len) tmp+=t1.substr(j+l[id]);
				if(tmp==t2) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
