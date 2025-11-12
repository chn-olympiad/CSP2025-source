#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
struct r{int x,id;}a[114];
ll n,m,h=1;
bool cmp(r x,r y){return x.x>y.x;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].x,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*m+j].id==1){
				if(h==1) cout<<i<<" "<<h+j-1;
				else cout<<i<<" "<<h-j+1;
				return 0;
			}
		}
		if(h==1) h=n;
		else h=1;
	}
	return 0;
}