#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,x=0,y=0,z[1001];
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	
	}
		z[1]=a[1];
	for(int i=1;i<=m;i++){
		if(a[i]>z[1]){
			z[i]=a[1];
			y++;
		}
		for(int i=1;i<=n;i++){
				if(a[i]>z[1]){
				z[i]=a[i];
				x++;
			}
		}
		
	}
	cout<<y<<" "<<x;
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
