#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}fs[101];
int in[101];
int main(){
	int c,r,x,y,n=1,h;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	x=c;
	if(x%2==0)y=1;
	else y=r;
	for(int i=1,k=1;i<=c;i++) for(int j=1;j<=r;j++) cin>>in[k++];
	h=in[1];
	sort(in+1,in+1+c*r);
	for(int i=1;i<=c*r;i++){
			fs[in[n]].x=x;
			fs[in[n]].y=y;
			n++;
		if(x%2==1&&y!=1) y--;
		else if(x%2==1&&y==1) x--;
		else if(x%2==0&&y!=r) y++;
		else if(x%2==0&&y==r) x--;
	}
	cout<<fs[h].x<<" "<<fs[h].y;
	return 0;
}