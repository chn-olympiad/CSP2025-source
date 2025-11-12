#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int v,id;
}a[101];
bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].v,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].id==1){
			int l,h,r=i%n;
			if(r==0){
				l=i/n;
				if(l&1)
					h=n;
				else
					h=1;
			}
			else{
				l=i/n+1;
				if(l&1)
					h=r;
				else
					h=n-r+1;
			}
			cout<<l<<' '<<h;
			break;
		}
	return 0;
}
