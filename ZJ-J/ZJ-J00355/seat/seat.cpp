#include <bits/stdc++.h>
using namespace std;
struct node{
	int s,x;
}a[10010];
int n,m,p,x=1,y=1;
bool cmp(node a,node b){
	return a.s>b.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[1].x=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].x==1){
			p=i;
			break;
		}
	}
	for(int i=0;i<p-1;i++){
		if(x&1){
			y++;
			if(y==n+1){
				y=n;
				x++;
			}
		}else{
			y--;
			if(y==0){
				y=1;
				x++;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}

