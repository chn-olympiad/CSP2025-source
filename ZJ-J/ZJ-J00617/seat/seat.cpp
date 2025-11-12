#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,id;
}a[110];
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}sort(a+1,a+m*n+1,cmp);
	int tmp=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			tmp=i;
			break;
		}
	}int sum=0;
	for(int i=1;i<=m;i++){
		
		if(i%2==1){
			for(int j=1;j<=n;j++){
				sum++;
				if(sum==tmp){
					cout<<i<<' '<<j;
					
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				sum++;
				if(sum==tmp){
					cout<<i<<' '<<j;
					
					return 0;
				}
			}
		}
		
	}
	return 0;
}
