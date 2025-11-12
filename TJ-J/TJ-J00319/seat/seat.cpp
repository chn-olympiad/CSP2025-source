#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],sum;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0){
			sum=a[i];
		}
	}
	sort(a,a+n*m,cmp);
	int t;
	for(int i=0;i<n*m;i++){
		if(a[i]==sum){
			t=i;
			break;
		}
	}
	int l=t/n;
	int r=t%n;
	if(l%2==0){
		cout<<l+1<<' '<<r+1;
	}
	else{
		cout<<l+1<<' '<<n-r;
	}
	return 0;
}
