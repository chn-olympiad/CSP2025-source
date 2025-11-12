#include<bits/stdc++.h>
using namespace std;
int n,maxa=INT_MIN,ans;
int a[5005],cnt;
int main(){
	freopen("polygon.in ","r",stdin);
	freopen("polygon.out ","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		cnt+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*maxa) cout<<1;
		else cout<<0;
		return 0;
	}
	if(maxa==1){
		for(int m=3;m<=n-1;m++){
			long long int x=1,y=1;
			for(int i=m+1;i<=n;i++){
		    	x*=i;
	    	}
		    for(int i=1;i<=n-m;i++){
	    		y*=i;
	    	}
	    	ans+=x/y;
	    	ans=ans%998244353;
		}
		cout<<ans+1;
		return 0;
	}
	int l=1;
	for(int r=1;r<=n;r++){
		cnt-=a[r];
		if(a[r]==maxa){
			for(int i=1;i<=n;i++){
				maxa=max(maxa,a[i]);
			}
		}
		if(cnt>2*maxa){
			ans++;
		}
		else{
			l++;
			cnt+=a[l];
		}
	}
	cout<<ans;
	return 0;
}














/*
int maxa=INT_MIN;
		int sum=0;
		maxa=max(maxa,a[i]);
		maxa=max(maxa,a[i+1]);
		sum+=a[i];
		sum+=a[i+1];
		for(int j=i+2;j<=n;j++){
			maxa=max(maxa,a[j]);
			sum+=a[j];
			if(sum<=2*maxa) continue;
			else ans++;
			ans=ans%998244353;
		}
*/
