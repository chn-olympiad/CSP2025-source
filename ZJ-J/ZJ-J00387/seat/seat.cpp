#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
struct node{
	int a,i;
}a[N];
int n,m;
bool cmp(node a,node b){
	return a.a>b.a;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].a;
		a[i].i=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int ii=(i-1)*n+j;
			if(a[ii].i==1){
				if(i%2==1) cout<<i<<" "<<j;
				else cout<<i<<" "<<n-j+1;
				return 0;
			}
		}
	}
	return 0;
}
