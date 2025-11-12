#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,k,o,a[500005],s[500005],ans,f[500005],g;
bool d(int l,int r){
	for(int i=l;i<=r;i++)
		if(f[i]==1)
		return 0;
	return 1;
}
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
		g=1;
		s[i]=a[i]^s[i-1];
	} 
	if(k==0&&g==0){
		cout<<n/2;
		return 0;
	}
	for(int l=1;l<=n;l++)
	for(int i=1;i<=n;i++){
		int j=l+i-1;
		if(s[i-1]^s[j]==k&&d(i,j)){
			for(int k=i;k<=j;k++)
			f[k]=1;
			ans++;
			i=j+1;
		}
	}
	cout<<ans;
	return 0;
}
