#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,nx[N];
long long ans=0;
vector <char> s[N],t[N]; 
char c[N],d[N];
bool check(int l,int r){
	for(int i=l;i<=r;i++){
		if(c[i]!=d[i]) return 0;
	}
	return 1;
}
bool check2(int u,int l,int r){
	for(int i=l;i<=r;i++){
		if(t[u][i]!=d[i]) return 0;
	}
	return 1;
}
int kmp(int u){
	for(int i=0,j=-1;i<s[u].size();i++){
		while(j&&s[u][i]!=s[u][j+1]&&j!=-1) j=nx[j];
		if(s[u][i]==s[u][j+1]) nx[i]=j+1;
	}
	for(int i=0,j=-1;i<strlen(c);i++){
		while(j&&c[i]!=s[u][j+1]&&j!=-1) j=nx[j];
		if(j>=s[u].size()-1){
			return i-s[u].size()+2;	
		}
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string ss,tt;
		cin>>ss>>tt;
		for(int j=0;j<ss.length();j++) s[i].push_back(ss[j]);
		for(int j=0;j<tt.length();j++) t[i].push_back(tt[j]);
	}
	for(int ii=1;ii<=q;ii++){
		cin>>c>>d;
		for(int i=1;i<=n;i++){
			int m=kmp(i);
			cout<<ii<<' '<<i<<' '<<m<<endl;
			if(m!=-1){
				if(check2(i,m,m+s[i].size()-1)&&check(0,m-1)&&check(m+s[i].size(),strlen(c)-1)){
					ans++;
				}
			}
		}
		ans=0;
		cout<<ans<<endl;
	}
	return 0;
}
