#include<bits/stdc++.h>

using namespace std;

const int N=305;

int n,m;
struct node{
	int i;
	int x;	
	bool operator < (node nd)const{
		return x > nd.x;
	}
}a[N];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].x,a[i].i=i;
	sort(a+1,a+n*m+1);
	int x=1,y=1,g=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].i==1){
			cout<<y<<" "<<x<<"\n";
			return 0;
		}
		x+=g;
		if(x>n){
			x=n;
			y++;
			g=-1;
		}
		if(x<1){
			x=1;
			y++;
			g=1;
		}
	}
	return 0;
}
