#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,a[105],sum,ans1,ans2;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]>a[1])sum++;
	}
	ans1=sum/n+1;
	if(ans1%2==1){
		ans2=sum%n+1;
	}else{
		ans2=n-sum%n;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}

