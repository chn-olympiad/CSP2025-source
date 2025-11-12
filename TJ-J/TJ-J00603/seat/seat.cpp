#include <bits/stdc++.h>
using namespace std;

int a[1000];

bool cmp(int x,int y){return x > y;}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	for(int i=0;i<s;i++)cin>>a[i];
	int my=a[0];
	sort(a,a+s,cmp);
	int pos=find(a,a+s,my)-a,y=(pos-(pos%m))/m, x=((pos-pos%m)/m%2==1)?m-1-(pos%m):(pos%m);
	cout<<y+1<<' '<<x+1;
	return 0;
}
