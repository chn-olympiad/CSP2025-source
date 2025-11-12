#include<bits/stdc++.h>
using namespace std;
int n,k,l=1,ans=0;
long long ai;
long long a[500005];
long long xo(long long x,long long y){
	long long an=0;
	for(int i=1;i<=max(x,y);i=i<<1){
		if((x&i)!=(y&i)) an+=i;
	}
	return an;
}
long long va(int f,int e){
	return xo(a[f-1],a[e]);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ai;
		a[i]=xo(a[i-1],ai);
		for(int j=l;j<=i;j++){
			if(va(j,i)==k){
				l=i+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
//	cout<<xo(n,k);
	return 0;
} 
