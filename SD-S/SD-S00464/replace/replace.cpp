#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,q,ans;
char a[5000005],t1[5000005],t2[5000005],cc[5000005];
vector<char>s[200005][3],ss;
vector<char>substr(int l,int r,int len) {
	ss.clear();
	ss.push_back('=');
	for(int i=l; i<=min(r,len); i++)ss.push_back(t1[i]);
	return ss;
}
void dfs(int x,int len,int flag) {
	if(flag||x==len+1) {
		for(int i=1; i<=len; i++) {
			if(t1[i]!=t2[i])return;
		}
		ans++;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(substr(x,x+s[i][1].size()-2,len).size()==s[i][1].size()&&substr(x,x+s[i][1].size()-2,len)==s[i][1]) {
			for(int j=x; j<=min(int(x+s[i][2].size()-2),len); j++) {
				t1[j]=s[i][2][j-x+1];
			}
			dfs(x+s[i][2].size()-1,len,flag||1);
			for(int j=x; j<=min(int(x+s[i][2].size()-2),len); j++)t1[j]=cc[j];
		}
		if(t1[x]==t2[x])dfs(x+1,len,flag);
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>(a+1);
		int len=strlen(a+1);
		s[i][1].push_back('=');
		s[i][2].push_back('=');
		for(int j=1; j<=len; j++)s[i][1].push_back(a[j]);
		for(int j=1; j<=len; j++) {
			char c;
			cin>>c;
			s[i][2].push_back(c);
		}
	}
	while(q--) {
		cin>>(t1+1);
		cin>>(t2+1);
		int len=strlen(t1+1);
		for(int i=1; i<=len; i++)cc[i]=t1[i];
		ans=0;
		dfs(1,len,0);
		cout<<ans<<"\n";
	}
	return 0;
}
