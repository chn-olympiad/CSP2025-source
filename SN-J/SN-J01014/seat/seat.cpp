//SN-J01014 赵子晗 西安市曲江第二中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,z,w,x,y;
ll a[110];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	z=n*m;
	for(int i=1;i<=z;i++) cin>>a[i];
	w=a[1];
	sort(a+1,a+z+1);
	for(int i=1;i<=z;i++){
		if(a[i]==w){
			w=z-i+1;
			break;
		}
	}
	if(w%n==0) x=w/n;
	else x=w/n+1;
	y=w-(x-1)*n;
	if(!(x&1)) y=n-y+1;
	cout<<x<<" "<<y;
	
	return 0;
}
