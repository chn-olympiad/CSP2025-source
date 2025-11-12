#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
int cnt,a[N];
int nx[4]={0,1,0,1};
int ny[4]={1,0,-1,0};
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1,f=0;cin>>n>>m;
//	cout<<n<<" "<<m<<"\n";
	for(int i=1;i<=n*m;i++) cin>>a[i];
//	for(int i=1;i<=n*m;i++) cout<<a[i]<<"\n";
	for(int i=2;i<=n*m;i++) if(a[i]>a[1]) cnt++;
	while(cnt--) {
		if(f==1||f==3) f++,f%=4;
		if(y==m&&f==0||y==1&&f==2) f++,f%=4;
		x+=nx[f];
		y+=ny[f];
//		cout<<x<<" "<<y<<" "<<f<<" "<<(y==m&&f==1)<<"\n";
	}
	cout<<x<<" "<<y<<"\n";
	return 0;
}
