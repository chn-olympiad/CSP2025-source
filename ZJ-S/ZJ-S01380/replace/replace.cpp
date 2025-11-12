#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,M=5e6+10;
int n,q;
string s[N][3];
string t[N][3];
int ans[N];
int ne[M];
void suan(string p){
	for(int i=2,j=0;i<(int)p.size();i++){
		while(j&&p[i]!=p[j+1])j=ne[j];
		if(p[i]==p[j+1])j++;
		ne[i]=j;
	}
}
int kmp(string s,string p,string s2,string t){
	for(int i=1,j=0;i<(int)s.size();i++){
		while(j&&s[i]!=p[j+1])j=ne[j];
		if(s[i]==p[j+1])j++;
		if(j+1==p.size()){
			string x=s.substr(0,i-j);
			string z=s.substr(i+1,(int)s.size()-i);
			if(x+s2+z==t)return 1;
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	for(int i=1;i<=n;i++){
		suan(s[i][1]);
		for(int j=1;j<=q;j++){
			int k=kmp(t[j][1],s[i][1],s[i][2],t[j][2]);
			ans[j]+=k;
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}