#include<bits/stdc++.h>
using namespace std;
int n,k,i,a[1000010],s,f[1000010],b[1000010],j;
int pd(int x,int y){
	return b[y]^b[x-1];
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	if(k==0){
		s=0;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++){
			if(a[i]==0) s++;
			if(a[i]==1&&a[i-1]==1&&f[i-1]==0&&f[i]==0) s++,f[i-1]=f[i]=1;
		}
		return cout<<s,0;
	}
	else{
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++){
			f[i]=f[i-1];
			for(j=i;j>=1;j--){
				if(f[i]-f[j-1]>=1) break;
				if(pd(j,i)==k){
					f[i]++;
					break;
				}
			}
		}
		cout<<f[n];
	}
	return 0;
}
