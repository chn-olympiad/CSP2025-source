#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=110;
int n,m,ans,pos,h,l;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(i%n==1) {
			l++;
			if(l&1){
				h=1;
				pos=1;
			}
			else {
				h=n;
				pos=2;
			}
		}
		if(a[i]==ans){
			cout<<l<<' '<<h;
			break;
		}
		if(pos==1) h++;
		else h--;
	}
	return 0;
}
