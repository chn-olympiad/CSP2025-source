#include<bits/stdc++.h>
using namespace std;
int n,l=0,r=3,maxn,sum,a[5001],ans=0;
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(i<=3){
    		sum=sum+a[i];
    		maxn=max(maxn,a[i]);
		}
	}
	if(sum>2*maxn) ans++;
	while(l<=n-2&&r<=n){
		while(sum<2*maxn){
			sum=sum+a[++r];
			maxn=max(maxn,a[r]);
		}while(sum>=2*maxn&&r-l>=2){
			ans++;
			sum=sum-a[++l];
		}
	}
	cout<<ans%998244353;
	return 0;
}

