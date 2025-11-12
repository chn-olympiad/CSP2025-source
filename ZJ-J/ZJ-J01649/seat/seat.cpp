#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[105];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int re=a[1];
	sort(a+1,a+1+n*m);
	int l=1,r=n*m;
	int seat;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<re)l=mid+1;
		else if(a[mid]>re)r=mid-1;
		else seat=n*m-mid+1,l=r+1;
	}
	int C,R;
//	cout<<seat<<"\n";
	if(seat%n==0)C=seat/n;
	else C=seat/n+1;
	if(C%2==1){
		R=seat-seat/n*n;
		if(R==0)R=n;
	}
	else if(C%2==0){
		R=n-(seat-seat/n*n)+1;
		if(R==0)R=n;
	}
	cout<<C<<" "<<R;
	return 0;
}
