#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,cnt;
long long zuhe(int m,int n){
	long long res=1;
	if(m>n-m) m=n-m;
	for(int i=0;i<m;i++){
		res*=(n-i);
	}
	for(int i=1;i<=m;i++){
		res/=i;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		sort(1+a,1+a+n);
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;		
	}
	sort(1+a,1+a+n);
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			ans+=zuhe(i,n);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans+=zuhe(i,n);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]<=a[k]) cnt++;
			}
		}
	}
	cout<<ans-1-cnt*3;
	return 0;
}
/*


*/