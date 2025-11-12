#include<bits/stdc++.h>
using namespace std;
int c,r,n,m,d;
struct node{
	int data,idx;
}a[120];
bool cmp(node x,node y){
	return x.data>y.data;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].data;
		a[i].idx=i;
//		printf("id=%d,data=%d\n",a[i].idx,a[i].data);
	}
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		printf("id=%d,data=%d\n",a[i].idx,a[i].data);
//	}
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
//				cout<<a[(i-1)*n+j].idx<<':'<<a[(i-1)*n+j].data<<'\n';
				if(a[(i-1)*n+j].idx==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
//				cout<<a[(i-1)*n+n-j+1].idx<<':'<<a[(i-1)*n+n-j+1].data<<'\n'; 
				if(a[(i-1)*n+n-j+1].idx==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
}
