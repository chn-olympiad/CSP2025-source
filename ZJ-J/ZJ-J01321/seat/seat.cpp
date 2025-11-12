#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,t,x,y,op;
struct no{
	int x,id;
}a[110];
bool cmp(no q,no h){return q.x>h.x;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>a[i].x,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	t=1;x=1;y=1;op=0;
	while(a[t].id!=1){
		t++;
		if(op==0)x++;
		else x--;
		if(x>n)x=n,y++,op=1;
		if(x<1)x=1,y++,op=1;
	}
	cout<<y<<" "<<x;
	return 0;
}
