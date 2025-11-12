#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	if(n==m && n==1 && m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	int a[n*m+10]={};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r;
	int sum=0;
	for(int i=2;i<=m*n;i++){
		if(a[i]>a[1]){
			sum+=1;
		}
	}
	r=sum+1;
	if(r>n+1){
		if((r+1)/(n+1)%2==0){
			if(r/(n+1)==0 || ((r+1)/(n+1))%2 == 0){
				cout<<(r+1)/(n+1)+1<<" "<<(r+1)/(n+1)+(r+1)%(n+1)-1;
				return 0;
			}
		}
	}else{
		if(r/(n+1)%2==0){
			if(r/(n+1)==0 || (r/(n+1))%2 == 0){
				cout<<r/(n+1)+1<<" "<<(r+1)/(n+1)+(r+1)%(n+1)-1;
				return 0;
			}
		}
	}
	if(r>=n+1){
		if((r+1)/(n+1)%2==1){
			if(((r+1)/(n+1))%2 == 1){
				cout<<(r+1)/(n+1)+1<<" "<<(n+1)-((r+1)/(n+1)+(r+1)%(n+1)-1);
				return 0;
			}
		}
	}
	return 0;
}
