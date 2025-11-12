#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,m,l,r;
struct node{
	int id,w;
}a[N];
bool cmp(node x,node y){
	return x.w>y.w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].w;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			l=(i/n)+1,r=i%n;
			if(r==0) r=n,l--;
			if(l%2==0) r=n-r+1;
			cout<<l<<" "<<r;
			return 0; 
		}
	}
	return 0;
}