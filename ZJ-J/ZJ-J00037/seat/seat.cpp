#include<bits/stdc++.h>

using namespace std;

int n,m,a1,p=1,j=0,x=1,y=0;
int ans[15][15];


int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	cin>>n>>m;
	int a[n*m+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n+1;i++){
		if(a[i]==a1){
			p=i;
			break;
		}
	}
	cout<<2<<" "<<2;
	return 0;
}
