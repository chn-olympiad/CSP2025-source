#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
pii a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	int tot=n*m;
	for(int i = 1;i <= tot;i ++)	cin >> a[i].fi,a[i].se=i;
	sort(a+1,a+1+tot,greater<pii>());
	int x;
	for(int i = 1;i <= tot;i ++){
		if(a[i].se==1){
			x=i;
			break;
		}
	}
	int l=ceil(x*1.0/n),r;
	if(l%2==1){
		r=x%n;
		if(r==0)	r=m;
	}else{
		r=m-x%n+1;
	}
	cout << l << " " << r << '\n';
	return 0;
}