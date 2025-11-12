#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,idx=1,idy;
struct node{
	int a,f;
}a[105];
bool cmp(node a,node b){
	return a.a>b.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].a;
	}
	a[1].f=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[idx].f==1){
				c=i;
				cout<<i<<" ";
				break;
			}
			idx++;
		}
	}
	for(int i=(c==1?1:(c-1)*n+1);i<=c*n;i++){
		if(a[i].f==1){
			if(c%2==1){
				cout<<(i-(c==1?0:(c-1)*n+1))+1<<endl;
			}else{
				cout<<m-(i-(c==1?0:(c-1)*n+1))<<endl;
			}
			break;
		}
	}
	return 0;
}
