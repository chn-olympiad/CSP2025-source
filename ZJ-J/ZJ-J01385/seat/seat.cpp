#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105],n,m,a1,ai;
	cin>>n>>m;
	int tol=n*m;
	for(int i=0;i<tol;i++){
		cin>>a[i];
	}
	a1=a[0];
	for(int i=0;i<tol;i++){
		for(int j=0;j<tol-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<tol;i++){
		if(a[i]==a1){
			ai=i;
		}
	}
	if((ai/n+1)%2==0){
		cout<<ai/n+1<<' '<<n-ai%n;
	}
	else{
		cout<<ai/n+1<<' '<<ai%n+1;
	}
	return 0;
}

