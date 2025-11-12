#include<iostream>
#include<algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
int vis[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	FASTIO;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>vis[i];
	int R=vis[1];
	sort(vis+1,vis+1+n*m,cmp);
	int c=1,r=1;
	for(int i=1;i<=n*m;i++){
		if(c>m)break;
		if(r>n){
			c++;
			r--;
		}
		else if(r<1){
			c++;
			r++;
		}
		if(vis[i]==R)break;
		if(c%2==1)r++;
		else r--;
	}
	cout<<c<<' '<<r;
	return 0;
}
