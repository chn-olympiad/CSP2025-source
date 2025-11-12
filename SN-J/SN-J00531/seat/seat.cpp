#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,rs,cr;
int ls,hs;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	rs=n*m;
	cr=1;
	cin>>a[1];
	for(int i=2;i<=rs;++i){
		cin>>a[i];
		if(a[i]>a[1])cr++;
	}
	ls=cr/(2*n);
	ls*=2;
	ls++;
	hs=cr%(2*n);
	if(hs>n){
		ls++;
		hs=2*n-hs+1;
	}
	cout<<ls<<" "<<hs;
	return 0;
}

