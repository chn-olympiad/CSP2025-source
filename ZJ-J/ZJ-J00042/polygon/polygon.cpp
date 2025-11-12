#include<bits/stdc++.h>
using namespace std;
int a[5005];
int ans=0,max1=0,cnt=0;
int n;
int f(int pa,int jg){
	if(pa<2||jg<0) return 0;
	else{
		if(max1*2<cnt){
			ans++;
			ans%=998244353;
		}
		for(int i=jg;i>=1;i--){
			if(a[i]==max1){
				max1=a[i-1];
				cnt-=a[i];
				f(pa-1,i-1); 
				cnt+=a[i];
				max1=a[i];
			}
			else{
				cnt-=a[i];
				f(pa-1,i-1);
				cnt+=a[i];
			}
		}
	return 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	sort(a+1,a+n+1);
	max1=a[n];
	f(n,n);
	cout<<ans;
	return 0;
}          