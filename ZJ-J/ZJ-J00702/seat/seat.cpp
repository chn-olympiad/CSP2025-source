#include <bits/stdc++.h>
using namespace std;
int n,m,i,now,ans1,ans2;
struct node{
	int x,y;
}a[110];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++){
		if(a[i].y==1){
			now=i;break;
		}
	}
	ans1=(now-1)/n+1;now-=(ans1-1)*n;
	if(ans1%2==1) ans2=now;
	else ans2=n-now+1;
	cout<<ans1<<" "<<ans2;
	return 0;
}
