#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
struct node{
	int val,id;
}a[N];
bool cmp(node x,node y){
	return x.val>y.val;
}
int n,m;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,cnt=0;
	while(x<=n&&y<=m){
		cnt++;
		if(a[cnt].id==1){
			cout<<x<<" "<<y;
			return 0;
		}
		if(x%2==0)y--;
		else y++;
		if(y==0){
			x++;
			y=1;
		}
		if(y==n+1){
			x++;
			y=n;
		}
	}
	return 0;
}



