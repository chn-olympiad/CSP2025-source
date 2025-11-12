#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[105];
int x,y,t,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)cin>>a[i];
	a[0]=a[1];
	sort(a+1,a+k+1);
	x=y=1;t=k;f=1;
	while(t>=1){
		if(a[t]==a[0]){cout<<y<<" "<<x;return 0;}
		x+=f;
		if(x<1){f=1;x++;y++;}
		if(x>n){f=-1;x--;y++;}
		t--;
	}
	return 0;
}
