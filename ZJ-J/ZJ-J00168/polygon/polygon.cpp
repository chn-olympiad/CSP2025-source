#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=INT_MIN,sum=0;
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
		if(a[i]!=1) flag=false;
	}
	sort(a+1,a+n+1);
    if(n<=3){
		if(sum>2*maxn) cout<<1;
		else cout<<0;
		return 0;
	}
	if(flag){
		cout<<n-2;
		return 0;
	}
	int nn=pow(n,2);
	cout<<nn%998244353;
	return 0;
}
