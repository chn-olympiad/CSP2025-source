#include<bits/stdc++.h>
using namespace std;
int n,m;

int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	int k=a[1];
	sort(a,a+n*m,cmp);
		int ai;
		for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			ai=i+1;
		}
		
}	
 int x=(ai+n-1)/n;
cout<<x<<' ';
if(x%2==1){
	cout<<ai-(x-1)*n;
}
if(x%2==0){
	cout<<(n+1)-(ai-(x-1)*n);
}

	
	
	return 0;
	
}
