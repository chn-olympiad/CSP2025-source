#include<bits/stdc++.h>
using namespace std;
int a[1000000];

int b[1000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n*m;i++){
		b[i]=a[i];
	}
	int q=n*m;
	while(q--){
		for(int i=1;i<=q;i++){
			if(b[i]<b[i+1]){
				int j=0;
				j=b[i];
				b[i]=b[i+1];
				b[i+1]=j;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((100-a[1])<m){
				cout<<1<<" "<<(100-a[1]);
				return 0;
			}else if((100-a[1])>=m&&(100-a[1])<2*m){
				cout<<2<<" "<<(100-a[1])/m;
				return 0;
			}else if((100-a[1])>=2*m&&(100-a[1])<3*m){
				cout<<3<<" ";
				if((100-a[1])%m==0){
					cout<<1;
				}else cout<<(100-a[1])%m;
				return 0;
			}else if((100-a[1])>=3*m&&(100-a[1])<4*m){
				cout<<4<<" "<<(100-a[1])/m;
				return 0;
			}
		}
	}
	
	return 0;
}
