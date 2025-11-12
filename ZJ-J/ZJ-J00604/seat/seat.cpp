//seat
#include<bits/stdc++.h>
#define N 101
using namespace std;
int n,m,a[N*N],a1,id;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==a1) {id=i;break;}
	int v=id%n,u=id/n;
	if(v==0) v=n,u-=1;
//	cout<<id<<" ";
	if(u%2==1)
		cout<<u+1<<" "<<n-v+1;
	else 
		cout<<u+1<<" "<<v;
	return 0;
}
