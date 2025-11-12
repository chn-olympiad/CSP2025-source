#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5;
int n,m,a[110],t,ii;
bool cmp(int aa,int bb){
	return aa>bb;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			ii=i;
			break;
		}
	}
	int c=ii/n;
	if(ii%n!=0)c++;
	int r=(ii-1)%n+1;
//	cout<<ii<<" "<<c<<" "<<r<<endl;
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

