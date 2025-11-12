#include<bits/stdc++.h>
//#define int long long 
using namespace std;
int n,m,k,x,y,a[110];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[1]<=a[i])k++;
	}
//	cout<<k<<"\n";//1
	y=((k-1)/n)+1;
//	cout<<(k-1)/n<<"\n";//2
	x=k%n;
//	cout<<y<<" "<<x<<"\n";//3
	if(x==0)x=n;
	if(y%2==0) x=n-x+1;
	cout<<y<<" "<<x<<"\n";
	return 0;
}
//operator
//priority_queue<int> q;

