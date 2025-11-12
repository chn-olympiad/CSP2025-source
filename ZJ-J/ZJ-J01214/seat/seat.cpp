#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,c;
}a[1001];
int n,m,k;
bool cmp(node p,node q){
	return p.c>q.c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			k=i;
			break;
		}
	}
	int l=(k-1)/n+1,h=(k-1)%n+1;
	if(l&1){
		cout<<l<<" "<<h;
	}
	else{
		cout<<l<<" "<<n-h+1;
	}
	return 0;
}
