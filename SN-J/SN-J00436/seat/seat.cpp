#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m,a[105],b[15][15],c,x=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	if(m==1&&n==1){
		cin>>c;
		cout<<m<<" "<<n;
		return 0;
	}else if(m==1){
		sort(a,a+n*m);
		for(int i=n*m;i>0;i--){
			if(a[i]==r){
				cout<<"1"<<" "<<i;
				return 0;
			}
		}
	}else if(n==1){
		sort(a,a+n*m);
		for(int i=n*m;i>0;i--){
			if(a[i]==r){
				cout<<i<<" "<<1;
				return 0;
			}
		}
	}
	
//    sort(a,a+n*m);
//    for(int i=0;i<m;i++){
//		for(int j=0;j<n;j++){
//			if(i%2!=0&&j<m){
//				b[i][j]=a[m*n-x];
//			}else if(i%2==0&&j<1){
//				
//			}
//		}
//	}
	return 0;
} 
