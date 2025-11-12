#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n=0,m=0,a[105]={},r=0,cnt=0;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==r){
			cnt=i-1;
			break;
		}
	}
	ll x=1,y=1,way=1;
	while (cnt--){
		if (x+way<1||x+way>n){
			y++;
			if (way==1){
				way=-1;
			}
			else{
				way=1;
			}
		}
		else{
			x+=way;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
