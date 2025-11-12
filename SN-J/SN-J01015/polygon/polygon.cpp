#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=1,k;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)k++;
	}
	sort(a+1,a+n+1);
	if(n==3){
		cout<<(a[1]+a[2]>a[3]);
	}else{
		for(int i=1;i<=k;i++){
			ans*=2;
		}
		ans-=1;
		ans-=k*(k-1)/2;
		ans-=k;
		cout<<ans;
	}
	return 0;
}
