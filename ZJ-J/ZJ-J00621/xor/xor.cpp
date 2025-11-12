#include<bits/stdc++.h>
using namespace std;
long long s[500005],a[500005],k,n,x;
int check(int ds){
	int j,l,ans;
	for(int i=1;i<=n;i++){
		j=i;l=i;ans=0;
		while(j<=n){
			while(j<=n&&(s[j]^s[l-1])!=k)j++;
			if(j<=n){
				ans++;
				j++;
				l=j;
			}
			if(ans==ds)return 1;
		}
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(a[i]^s[i-1]);
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)==1)l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}