#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[105],b[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,r;
	int x,y;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		r=a[0];
	}
	sort(a,a+m*n);
	for(int i=0;i<m*n;i++) b[i]=a[n*m-i-1];
	for(int i=0;i<n*m;i++){
		if(r==b[i]){
			r=i+1;
		}
	}
	if(r%n==0) cout<<r/n<<" ";
	else cout<<r/n+1<<" ";
	if(r%n==0) y=r/n;
	else y=r/n+1;
	if(y/2==0){
		r=r-y*n+n;
		cout<<n-r;	
	}
	else{
		r=r-y*n+n;
		cout<<r;
	}
	return 0;
}

