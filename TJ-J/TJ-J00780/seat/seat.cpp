#include<iostream>
using namespace std;
int a[1000005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	for(int i=1;i<=n*m;i++){
		int k=i,maxn=-1e9;
		for(int j=i;j<=m*n;j++){
			if(maxn<a[j]){
				maxn=a[j];
				k=j;
			}
		}
		int g=a[i];
		a[i]=a[k];
		a[k]=g;
	}
	int s=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==f) s=i;
	}
	int y=s/n+1,x=s%m;
	if(y>n) y=n;
	if(x==0) x=m;
	if(y%2==0) x=m-x+1;
	cout<<y<<" "<<x;
	return 0;
}

