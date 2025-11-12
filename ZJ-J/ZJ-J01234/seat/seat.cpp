#include<bits/stdc++.h>
using namespace std;
int n,m,i,now,x,y;
struct node{
	int val,id;
}a[110];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i].val,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	now=x=y=1;
	while(now<=n*m){
		if(a[now].id==1){
			cout<<x<<" "<<y;
			return 0;
		}
		if(x%2==1){
			if(now%n==0) x++;
			else y++;
		}
		else{
			if(now%n==0) x++;
			else y--;
		}
		now++;
	}
}
