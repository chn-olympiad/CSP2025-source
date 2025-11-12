#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
struct node{
	int id,x;
}a[105];
bool cmp(node l,node r){
	return l.x>r.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	int now;
	stable_sort(&a[1],&a[n*m+1],cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			now=i;
			break;
		}
	}
	int r=ceil(now*1.0/n);
	if(r&1)cout<<r<<' '<<now-(r-1)*n;
	else cout<<r<<' '<<n-(now-((r-1)*n))+1;
	return 0;
}

