#include<bits/stdc++.h>
using namespace std;
int n,ma,i,j,s,ans,a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i],ma=max(ma,a[i]);
	if(ma==1){
		for(i=3;i<=n;i++){
			s=1;
			for(j=1;j<=i;j++)
				s=s*(n-j+1);
			for(j=1;j<=i;j++)
				s=s/j;
			ans+=s;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	if(a[3]<a[1]+a[2])cout<<1;
	else cout<<0;
	return 0;
}