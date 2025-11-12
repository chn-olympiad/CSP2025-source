#include<bits/stdc++.h>
using namespace std;
int n,Q;
map<string,string> mp;
string t,tt;
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string tmp,tm;
	n=read(),Q=read();
	for(int i=1;i<=n;i++){
		cin>>tm>>tmp;
		mp[tm]=tmp;
	}
	while(Q--){
		int ans=0;
		cin>>t>>tt;
		for(int i=0;i<t.size();i++){
			for(int j=t.size()-1;j>=0;j--){
				if(t.substr(0,i+1)+mp[t.substr(i,j-i+1)]+t.substr(j,t.size()-j)==tt) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
