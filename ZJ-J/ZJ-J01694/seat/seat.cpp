#include<bits/stdc++.h>
using namespace std;
long long l,r,n,m,R,a[1005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long t=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[t];
			t++;
		}
	}
	R=a[1];
	long long h=n*m;
	sort(a+1,a+1+h,cmp);
	l=1,r=1;
	int u=0;
	while(true){
		if(l%2==1){
			if(a[++u]==R){
				cout<<l<<" "<<r;
				return 0;
			}
			if(r==n){
				l++;
				r=n-1;
			}
			r++;
		}
		else{
			if(a[++u]==R){
				cout<<l<<" "<<r;
				return 0;
			}
			if(r==1){
				l++;
				r=2;
			}
			r--;
		}
	}
	return 0;
}
