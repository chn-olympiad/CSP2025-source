// SN-J00980 谈子航  西安经开第二中学
#include<bits/stdc++.h>
using namespace std;
int n,m,k,e=1;
struct node{
	int x,y,cj;
}d[100010];
bool cmp(node a,node b){
	return a.cj>b.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>d[i].cj;
	k=d[1].cj;
	sort(d+1,d+n+1,cmp);
	for(int a=1;a<=n*m;a++){
		for(int i=m;i>=1;i--){
			d[a].x=i;
			for(int j=n;j>=1;j--)d[a].y=j;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(d[i].cj==k){
			cout<<d[i].x<<" "<<d[i].y;
			break;
		}
	}
 return 0;
}

