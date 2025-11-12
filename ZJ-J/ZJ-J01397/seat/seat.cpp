#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int k=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	int x=1,y=1,f=1;
	for(int i=0;i<n*m;i++){
		if(a[i]==k){
			cout<<x<<' '<<y;
		}
		else{
			if(f==1){
				y++;
				if(y>n){
					y=n;
					x++;
					f=0;
				}
			}
			else{
				y--;
				if(y<1){
					y=1;
					x++;
					f=1;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
