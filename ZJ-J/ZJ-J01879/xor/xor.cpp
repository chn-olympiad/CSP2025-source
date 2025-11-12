#include<bits/stdc++.h>
using namespace std;
long long n,k,a,s[500002],f[500002],maxn,l[1100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[i]=s[i-1]^a;
		maxn=max(maxn,a);
	}
	if(s[1]==k)f[1]=1;
	l[s[1]]=2;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1];
		if((s[i]^s[i-1])==k)f[i]=f[i-1]+1;
		else if(l[k^s[i]]>0)f[i]=max(f[i],f[l[k^s[i]]-1]+1);
		l[s[i]]=i+1;
	}
	cout<<f[n];
	return 0;
}
