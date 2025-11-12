#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,id;	
}a[105];
bool cmp(node a,node b){
	return a.v>b.v;
}
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int f;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			f=i;
			break;
		}
	}
	if(int(ceil(f*1.0/n))%2) cout<<ceil(f*1.0/n)<<" "<<(f%n!=0?f%n:n);
	else cout<<ceil(f*1.0/n)<<" "<<n+1-(f%n!=0?f%n:n);
	return 0;
}