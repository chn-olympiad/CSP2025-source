#include<bits/stdc++.h>
using namespace std;
int x,y,n,m,i,bao;
struct no{
	int x,y;
}a[110];
bool cmp(no q,no h){
	return q.x>h.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		cin>>a[i].x,a[i].y=i;
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
		if(a[i].y==1){
			bao=i;
			break;
		}
	x=(bao-1)/n+1;
	y=(bao-1)%n+1;
	if(x%2==0)y=m-y+1;
	cout<<x<<" "<<y;
	return 0;
}