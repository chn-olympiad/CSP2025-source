#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int m,n;
	int num=0;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		num=a[1];
	}
		for(int i=1;i<=m*n;i++){
		for(int j=i+1;j<=m*n;j++){
			if(a[j]>a[i]){
				int temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
     	}	
    }
    for(int i=1;i<=m*n;i++){
    	if(num==a[i]){
    		num=i;
		}
	}
//	cout<<num;
    for(int i=1;i<=m;i++){
    	if(i%2==1){
    		for(int j=1;j<=n;j++){
    		num--;
    		if(num==0){
    			cout<<i<<j;
			    }
		    }
		}else{
			for(int j=n;j>0;j--){
				num--;
				if(num==0){
					cout<<i<<j;
				}
			}
		}
	}
	return 0;
}
