#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int n,m,a[N];

bool cmp(int a,int b){
	return a>b;
}

signed main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1],f=1,r=0,c=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(f==1){
			r++;
			if(r>n){
				r=n;
				f=2;
				c++;
			}
		}
		else if(f==2){
			r--;
			if(r<1){
				r=1;
				f=1;
				c++;
			}
		}
		if(a[i]==t) cout<<c<<" "<<r;
	}
	return 0;
}