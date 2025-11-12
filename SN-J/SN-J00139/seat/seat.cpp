#include<bits/stdc++.h>
using namespace std;
int a[100005]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[0];
	int z=a[0];
	for(int i=1;i<n*m;i++){
			cin>>a[i];
	}
		for(int i=0;i<n*m;i++){
			for(int j=i+1;j<n*m;j++){
				if(a[i]<a[j]){
					int t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
		
	for(int i=0;i<n*m;i++){
		if(a[i]==z){
			int x=i/n+1;
		 int y=n-(n*2)%i;
		 cout<<x<<" "<<y;
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
