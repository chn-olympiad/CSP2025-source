#include<bits/stdc++.h>
using namespace std;
int n,m,w;
struct node{
	int x,y;
}a[101];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].y==1){
			w=i;
			break;
		}
	cout<<ceil(w*1.0/n)<<' ';
	int b=w%n;
	if(!b)
		b=n;
	if((int)ceil(w*1.0/n)%2==1)
		cout<<b;
	else
		cout<<n-b+1;
	return 0;
}