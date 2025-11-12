#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[15][15],a[105],sc;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>sc;
	a[0]=sc,a[1]=sc;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m,greater<int>());
	int x=1,y=1,delta_x=1;
	for(int i=1;i<=n*m;i++,x+=delta_x){
		if(x>n||x<1){
			x-=delta_x;
			delta_x*=-1;
			y++;
		}
		ans[x][y]=a[i];
		if(a[i]==sc){
			cout<<y<<' '<<x;
			return 0;
		}
	}
	return 0;
}
