#include<bits/stdc++.h>
using namespace std;
int n,m,num,x,y,ans_x,ans_y;struct node{int x,id;}a[200];bool cmp(node x,node y){return x.x>y.x;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;for(int i=1;i<=n*m;i++) cin>>a[i].x,a[i].id=i;sort(a+1,a+n*m+1,cmp);
	x=1,y=1,num=1;
	for(int i=1;i<=n*m;i++){
		if(a[num].id==1) ans_x=y,ans_y=x;
//		cout<<x<<" "<<y<<":"<<a[num].id<<"\n";
		num++;
		if((x==1&&y%2==0)||(x==n&&y%2==1)) y++;
		else x+=(y%2==1?1:-1);
	}
	cout<<ans_x<<" "<<ans_y;
	return 0;
}
//9:37  shenminga,qingzaijuanguwoyici
