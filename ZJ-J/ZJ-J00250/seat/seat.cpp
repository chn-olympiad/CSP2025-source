#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[104],k,x,ra;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
	  cin>>a[i];
	  if(a[i]>=a[1])
	    ra++;
	}
	int g=n*2;
	int l=ra/g;
	int r=ra%g;
	if(r==0)
	  l--,r+=2*n;
	if(r<=n)
	  cout<<l*2+1<<" "<<r;
	else{
	  r-=n;
	  cout<<l*2+2<<" "<<n-r+1;
	}
	return 0;
}
