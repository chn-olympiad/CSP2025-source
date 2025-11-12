#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int o,p;
	cin>>n>>m;
	cin>>o;
	int y[n*m-1]={0};
	int a[n][m];
	int temp;
	for(int i=0;i<n*m-1;i++){
		cin>>y[i];
		int k=i;
		while(y[k]>=y[k-1]){
			if(k==0){
				break;
			}
			temp=y[k];
			y[k]=y[k]-1;
			y[k-1]=temp;
			k--;
		}
	}
	if(o==0){
		p=n*m;
		goto q;
	}
	for(int i=0;i<n*m-1;i++){
		if(o>y[i]){
			p=i;
			break;
		}
	}
	q:
	if((p/n+1)%2==0){
		cout<<p/n+1<<' '<<n-p%n;
	}
	else{
		cout<<p/n+1<<' '<<p%n+1;
	}
	return 0;
} 
