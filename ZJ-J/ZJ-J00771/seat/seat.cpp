#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int n,m,sum,h,i,t,l;
struct no{
	int x,y;
}a[110];
bool cmp(no q,no h){
	return q.x>h.x;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>a[i].x,a[i].y=i;
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++)
		if(a[i].y==1){sum=i;break;}
	t=1;h=1;l=1;
	while(t!=sum){
		if(h>n)h-=n,l++;
		h++;t++;
	}
	if(h>n)h-=n,l++;
	if(l%2==1)cout<<l<<" "<<h;
	else cout<<l<<" "<<n-h+1;
}