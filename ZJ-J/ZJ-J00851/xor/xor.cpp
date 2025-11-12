#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a[500005];
int ans;
bool flag=1;
bool check(int mid){
	long long xorans=a[1];
	int anser=0;
	for(int i=2;i<=n;i++){
		if(xorans==k){
			anser++;
			xorans=a[i];
		}
		else xorans=xorans xor a[i];
	}
	return anser>=mid;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[0]=a[1];
		if(a[i]!=a[i-1])flag=0;
	}
	if(k==0&&flag)cout<<n/2;
	else{
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)){
				l=mid+1;
				ans=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
