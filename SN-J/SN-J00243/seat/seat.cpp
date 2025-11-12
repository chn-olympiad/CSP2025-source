#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,j=1,x=1;
	cin>>n;
	int a[n*n];
	int b[n*n];
	for(int i=1;i<=n*n;i++){
		cin>>a[i];
	}
	
	while(a[j]==0){
		if(a[j]>a[j+1]){
			b[x]=a[j];
			j+=1;
			x+=1;
		}else{
			j+=1;
		}
	}
	return 0;
}
