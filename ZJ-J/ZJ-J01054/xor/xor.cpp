#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long a[N],v[N];
long long y(long long a,long long b){
	long long l=a|b,z=a&b;
	return l-z;
}
map<long long,long long> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,k;
	cin>>n>>k;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			v[a[i]]=1;
			ans++;
		}
	}
	
	for(int i=1;i<=n;i++){
		int f=a[i];
		if(a[i]==k){
			continue;
		}
		for(int j=i+1;j<=n;j++){
			if(v[a[j]])break;
			if(y(a[j],f)==k){
				ans++;
				break;
			}
			f=y(a[j],f);			
		}
	}
	
	cout<<ans;
	return 0;
}

