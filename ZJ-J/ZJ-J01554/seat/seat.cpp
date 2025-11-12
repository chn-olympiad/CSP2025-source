#include<bits/stdc++.h>
using namespace std;
struct node{
	int pts,id;
}a[250];
bool cmp(node a1,node a2){
	return a1.pts>a2.pts;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].pts,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<y<<" "<<x;
			return 0;
		}
		if(x==n&&y%2==1) y++;	
		else if(x==1&&y%2==0) y++;
		else if(y%2==1) x++;
		else x--;
	}
	return 0;
}
