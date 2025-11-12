#include<bits/stdc++.h>
using namespace std;
string s[200001],t[200001],a,b;
long long n,q,ans,i,j,k;
bool check(long long x,long long y){
	for(int i=0;i<s[x].size();i++){
		if(s[x][i]!=a[y+i]) return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++) cin>>s[i]>>t[i];
	while(q--){
		cin>>a>>b,ans=0;
		for(i=1;i<=n;i++){
			for(j=0;j<a.size()-s[i].size()+1;j++){
				if(check(i,j)){
					for(k=j;k<j+s[i].size();k++) a[k]=t[i][k-j];
					if(a==b) ans++;
					for(k=j;k<j+s[i].size();k++) a[k]=s[i][k-j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}