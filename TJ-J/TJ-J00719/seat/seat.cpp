#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[1000];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int a1=a[0],a1w;
	sort(a,a+n*m);
	int q=0;
	for(int i=m*n-1;i>=0;i--){
		q++;
		if(a[i]==a1){
			a1w=q;
			break;
		}
	}
	if(m%2==0){
		int x=0;
		for(int i=0;i<m/2;){
			for(int j=0;j<n;j++){
				x++;
				if(x==a1w){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}i++;
			for(int j=n-1;j>=0;j--){
				x++;
				if(x==a1w){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}i++;
		}
	}else{
		int x=0;
		for(int i=0;i<m/2;){
			for(int j=0;j<n;j++){
				x++;
				if(x==a1w){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}i++;
			for(int j=n-1;j>=0;j--){
				x++;
				if(x==a1w){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}i++;
		}
		for(int j=0;j<n;j++){
			x++;
			if(x==a1w){
				cout<<m<<" "<<j+1;
				return 0;
			}
		}	
	}
	return 0;
} 
