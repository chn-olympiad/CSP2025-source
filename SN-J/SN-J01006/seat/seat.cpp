#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	int a[1010]={};
	int g[110][110]={};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s=a[1];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=i;j>=1;j--){
		if(a[j]<a[j+1])	{
			swap(a[j],a[j+1]);
		}
	}
 }
 	int i=1,j=1,l=1;
	while(true){
		if(i-1==n||i==0) {
			j++;
			if(j%2==1) i=1;
			if(j%2==0) i=n;
		}
		
		if(j%2==0){
		g[i][j]=a[l];
		if(a[l]==s){
			cout<<j<<" "<<i;
			break;
		}
		i--;
		l++;
	}
	
		if(j%2==1){
		g[i][j]=a[l];
		if(a[l]==s){
			cout<<j<<" "<<i;
			break;
		}
		i++;
		l++;
	  }
	}
	return 0;
}
