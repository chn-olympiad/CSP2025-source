#include<bits/stdc++.h>
#define int long long
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
using namespace std;
int n,m,a[1000],b[3]={-1,1};
signed main(){
	ioi;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1];
	sort(a+1,a+1+n*m);
	int h=1,l=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			cout<<l<<" "<<h;
			return 0;
		}
		if((i-1)%n==0) l++;
		else h+=b[l%2];
	}
	return 0;
}