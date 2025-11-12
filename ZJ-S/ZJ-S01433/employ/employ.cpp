#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,a[N],c[N],v[N],cnt;
string s;
void dfs(int l){
	if(l>n){
		int ct=0;
		for(int i=1;i<=n;i++){
			if(ct>=c[a[i]]||s[i]=='0'){
				ct++;
				continue;
			}
		}
		if(n-ct>=m) cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		a[l]=i;
		v[i]=1;
		dfs(l+1);
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<cnt;
	return 0;
}