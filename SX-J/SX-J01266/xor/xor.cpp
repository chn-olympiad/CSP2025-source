#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],s[500010],v[500010],ans=0,z;
long long hs(long long l,long long r){
	for(int i=l;i<=r;i++){
		if(a[i]==1)return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)ans++,v[i]=1;
		s[i]=(a[i]^s[i-1]);
	}
	memset(a,0,sizeof(a));
	memcpy(a,v,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			v[j]=a[j]-a[j-1];
		}
		for(int j=i;j<=n;j++){
			if((s[j]^s[j-i])==k&&hs(j-i+1,j)){
				ans++;
				v[j-i+1]++;
				v[j+1]--;
				j+=i;
			}
		}
		memset(a,0,sizeof(0));
		for(int j=1;j<=n;j++){
			z=v[j];
			a[j]=a[j-1]+v[j];
		}
	}
	cout<<ans;
	return 0;
}
