#include<iostream>
using namespace std;

int l;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m,sum,a[120];
	cin>>n>>m;
	sum=n*m;
	
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	
	int c[10];
	c[0]=a[1];
	
	a[0];
	for(int j=1;j<=sum;j++){
		for(int i=1;i<=sum;i++){
			if(a[i]<a[i+1]){
				a[0]=a[i+1];
				a[i+1]=a[i];
				a[i]=a[0];
			}
		}
	}//排序 (大到小) 

	int l=0;
	for(int i=1;i<=sum;i++){
		if(a[i]==c[0]){
			l=i;
		}
	}//找总排名顺序 
	cout<<1<<" "<<l;

	return 0;
}
