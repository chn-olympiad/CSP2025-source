#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid(l,r) (l+r>>1)
#define lowbit(x) (x&-x)
using namespace std;
const int N=1e2+10,M=1+10,mod=1e9+7;
const double eps=1e-1;
const long double pi=acos(-1);
int n,m;
pair<int,int>a[N];
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.first>y.first;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].second==1){
			cout<<y<<" "<<x<<endl;
			return 0;
		}
		if(y%2)x++;
		else x--;
		if(x>n){
			y++;
			x=n;
		}
		else if(x<1){
			y++;
			x=1;
		}
	}
	return 0;
}
