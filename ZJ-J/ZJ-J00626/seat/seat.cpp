#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct www{
	int x;
	int rand;
}a[101010];
int zw;
int y;
bool cmp(www x,www y){
	return x.x>y.x;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].rand=i;
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].rand==1){
			zw=i;
		}
	}
	y=1;
	while(zw-n>0){
		zw-=n;
		y++;
	}
	cout<<y<<" ";
	if(y%2==0){
		cout<<n-zw+1;
	}
	else cout<<zw;
}