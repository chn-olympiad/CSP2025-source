#include<bits/stdc++.h>
using namespace std;
int a[10005],num[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,me;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		me=a[1];
		num[a[i]]++;
	}
	int k=1;
	for(int i=100;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			a[k]=i;
			k++;
		}
	}
	int y=0,x=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]!=me){
			if(x%2==0){
				y--;
				if(y<1){
					x++;
					y=1;
				}
			} 
			else if(x%2!=0){
				y++;
				if(y>m){
					x++;
					y=m;
				}
			}
		}
		else if(a[i]==me){
			if(x%2==0){
				y--;
				if(y<1){
					x++;
					y=1;
				}
			}
			else if(x%2!=0){
				y++;
				if(y>m){
					x++;
					y=m;
				}
			}
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
} 
