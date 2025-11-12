#include<bits/stdc++.h>
using namespace std;
int n,m;
int v;
struct node{
	int x,num;
}a[105];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			v=i;
			break;
		}
	}
	int h,l;
	l=(v+m-1)/m;
	if(l%2!=0){
		h=v-(l-1)*m;
	}
	else{
		h=m-(v-(l-1)*m)+1;
	}
	cout<<l<<" "<<h;
	return 0;
}
