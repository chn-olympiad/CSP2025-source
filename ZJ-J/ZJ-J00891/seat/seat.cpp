#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int n,m;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			int t=(i+n-1)/n;
			cout<<t<<" ";
			if(t%2==0){
				if(i%n==0) cout<<1;
				else cout<<n-(i%n)+1;
			}
			else{
				if(i%n==0) cout<<n;
				else cout<<i%n;
			}
			return 0;
		}
	}
	return 0;
}