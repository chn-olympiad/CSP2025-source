#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxx=0,sum=0,aaa=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sum+=a[i];
	}
	if(maxx*2<sum){
		aaa++;
	}
	cout<<aaa;
	return 0;
}
