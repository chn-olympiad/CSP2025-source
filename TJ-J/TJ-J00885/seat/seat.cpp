#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],c;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1);
	if(a[1]==c){
		cout<<1<<" "<<1;
		return 0;
	}
	int x=1,y=0,f=0;
	for(int i=n*m;i>0;i--){
		if(f==0){
			y++;
		}
		if(f==1){
			y--;
		}
		if(y<1&&f==1){
			y=1;
			x++;
			f=0;
		}
		if(y>n&&f==0){
			y=n;
			x++;
			f=1;
		}
		if(a[1]==c){
			cout<<n<<" "<<m;
			return 0;
		}
		if(a[i]==c){
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}
