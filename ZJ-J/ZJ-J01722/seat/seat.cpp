#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2010;
int n,m,i,j;
struct no{
	int x,y,id,cj;
}a[N];
bool cmp(no q,no h){
	if(q.cj>h.cj) return 1;
	else if(q.cj==h.cj&&q.id<h.id) return 1;
	else return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n*m;i++)
			cin>>a[i].cj,a[i].id=i;
		sort(a+1,a+1+n*m,cmp);
		a[1].x=1;a[1].y=1;
		for(int i=2;i<=n*m;i++){
			if(a[i-1].y%2==1){
				if(a[i-1].x<n) a[i].x=a[i-1].x+1,a[i].y=a[i-1].y;
				else if(a[i-1].x==n) a[i].x=a[i-1].x,a[i].y=a[i-1].y+1;
			}
			else if(a[i-1].y%2==0){
				if(a[i-1].x>1) a[i].x=a[i-1].x-1,a[i].y=a[i-1].y;
				else if(a[i-1].x==1) a[i].x=a[i-1].x,a[i].y=a[i-1].y+1;
			}
		}
		for(int i=1;i<=n*m;i++)
			if(a[i].id==1){
				cout<<a[i].y<<" "<<a[i].x;
				return 0;
			}
		return 0;
}
