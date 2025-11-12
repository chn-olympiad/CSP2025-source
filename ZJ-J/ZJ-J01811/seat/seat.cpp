#include<bits/stdc++.h>
using namespace std;
int a,cnt=1,x,y,n,m,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1)
				cin>>a;
			else{
				cin>>b;
				if(b>a)
					cnt++;
			}
				
		}
	}
	int k=0;
	for(int i=1;i<=n;i+=2){
		for(int j=1;j<=m;j++){
			k++;
			if(k==cnt){
				x=i,y=j;
			}
		}
		for(int j=m;j>0;j--){
			k++;
			if(k==cnt)
				x=i+1,y=j;
		}
	}
	cout<<x<<" "<<y;
	return 0;	
}
