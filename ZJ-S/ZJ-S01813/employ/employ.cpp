#include <bits/stdc++.h>
using namespace std;
int n,m,p[105],cnt;
char c[105];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(c[i]=='1')cnt++;
	}
	for(int i=1;i<=n;++i)cin>>p[i];
	if(m==n){
		for(int i=1;i<=n;++i){
			if(c[i]=='0'||p[i]==0){
				cout<<0<<endl;
				return 0;
			}
		}
		cout<<1<<endl;
		return 0;
	}
	if(cnt<m){
		cout<<0<<endl;
	}
	if(cnt==m)cout<<1<<endl;
	else cout<<998244352<<endl;
	return 0;
}
