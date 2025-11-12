#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int x=1,y=1,m,n,a[1005],a1;
	cin>>n>>m>>a[1];
	a1=a[1];
	for(int i=2;i<=m*n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int k=1;
	while(1){
		if(a[k]==a1){
			break;
		} 
		k++;
	}
	for(int i=1;i<=k-1;i++){
		if(x%2){
			y++;
			if(y==n){
				i++;
				if(i<=k-1){
					x++;
				}
				
			}
		}else{
			y--;
			if(y==1){
				i++;
				if(i<=k-1){
					x++;
				}
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
