#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[100010],x,y,t,op,r;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	x=1;y=1;t=1;op=1;
	while(t<=n*m){
		if(a[t]==r)return cout<<x<<' '<<y,0;
		if(op==0){
			x++;
			op=-1;
		}
		else if(op==1){
			y++;
			if(y==n)op=0;
		}
		else if(op==-1){
			y--;
			if(y==1)op=0;
		}
		t++;
	}
}
/*
*/
