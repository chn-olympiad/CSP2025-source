#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s=0,k=0;
    if(n==1&&m==1){
    	cout<<1<<" "<<1;
		return 0; 
	}
	int a[15];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		}
	   for(int i=1;i<=n;i++){
	   	for(int j=2;j<=m;j++){
	   		if(a[i]<a[j]){
	   			swap(a[i],a[i+1]);
		}
}
}
	   
	   for(int i=1;i<=n;i++){
	   	for(int j=1;j<=m;j++){
	   		if(a[1]>a[i]){
	   			s+=i;
	   			k+=j;
	   			break;
			   }
		   }
	   }
	   cout<<s<<" "<<k;
    return 0;
}

