#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-1;j++){
			if(a[j+1]>=a[j]){
				int t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	int g=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			g=i;
		}
	}
	cout<<g/n+1<<" ";
	if((g/n)%2==0){
		cout<<g%n;
	}
	else{
		cout<<n-g%n+1;
	}
	return 0;
}
