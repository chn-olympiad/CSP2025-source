#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,M=1e6+10;
int ne[N],vis[M];
string a[N],b[N];
void init(string s){
	int n=s.size();
	s=' '+s;
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[j+1]!=s[i])j=ne[j];
		if(s[j+1]==s[i])j++;
		ne[i]=j;
	}
}
int l,r;
void cmp(string a,string b){
	int n=a.size(),m=b.size();
	a=' '+a,b=' '+b;
	for(int i=max(1,r-m+1),j=0;i<=min(n,l+m-1);i++){
		while(j&&a[i]!=b[j+1])j=ne[j];
		if(a[i]==b[j+1])j++;
		if(j==m){
			vis[i-m+1]++;
			j=ne[j];
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(m--){
		string s,t;
		cin>>s>>t;
		int ls=s.size(),lt=t.size();
		if(ls!=lt){
			cout<<0<<'\n';
			continue;
		}
		ll ans=0;
		l=ls,r=0;
		for(int i=0;i<ls;i++){
			if(s[i]!=t[i]){
				l=min(l,i+1);
				r=max(r,i+1);
			}
		}
		for(int i=1;i<=n;i++){
			int len=a[i].size();
			if(len<r-l+1||len>ls)continue;
			for(int j=max(1,r-len+1);j<=min(ls,l+len-1);j++){
				vis[j]=0;
			}
			init(a[i]);
			cmp(s,a[i]);
			init(b[i]);
			cmp(t,b[i]);
			for(int j=max(1,r-len+1);j<=min(ls,l+len-1);j++)if(vis[j]>1){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}