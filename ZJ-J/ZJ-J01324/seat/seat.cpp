#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	bool yes;
}a[1000];
int cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	a[1].yes=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[m*(i-1)+j].v;
		}
	}
	int top=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[top++].yes){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[top++].yes){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}