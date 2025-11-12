#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1e2;
int n,m;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int pa=a[1];
	sort(a+1,a+1+n*m,cmp);
	int t,y,cnt=1;
	for(int i=1;i<=n;i++){
		if(i&1) t=1,y=1;
		else t=-1,y=m;
		while((y>=1&&y<=m)){
			if(a[cnt]==pa){
				cout<<i<<" "<<y;
				return 0;
			}
			cnt++;
			y+=t;
		}
	}
	return 0;
}
/*
input

2 4
99 91 71 78 12 89 98 100

output

1 2

*/
