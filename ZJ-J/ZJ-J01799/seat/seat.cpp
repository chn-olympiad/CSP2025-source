#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	int j=1,x=1,y=1,d=1;
	while(a[j]!=sum){
		if(x+d>n||x+d<1)d*=-1,y++;
		else x+=d;
		j++;
	}
	cout<<y<<' '<<x;
	return 0;
}