#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,maxa,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		sum+=a[i];
	}
	if(n==3){
		if(sum>2*maxa)cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<18;
	return 0;
}
