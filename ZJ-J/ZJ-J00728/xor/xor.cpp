#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s[500010],ls[(1<<20)+20],t[500010],f[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]^a[i];
	memset(ls,-1,sizeof ls);
	ls[0]=0;
	for(int i=1;i<=n;i++){
		t[i]=ls[s[i]^k];
		ls[s[i]]=i;
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(t[i]!=-1)f[i]=max(f[i],f[t[i]]+1);
	}
	cout<<f[n];
	return 0;
}
