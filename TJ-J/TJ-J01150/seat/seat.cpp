#include <bits/stdc++.h>
using namespace std;
const int MAX=0x7fffffff;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	int n,m,c,r;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	int temp=0;
	for(int j=1;j<=n*m;j++){
		for(int i=1;i<=n*m;i++){
			if(a[j]>a[i]){
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	for(int i=1;i<=n*m;++i){
		if(a[i]==b){
			b=i;
			
			break;
		}
	}
	c=b/n;
	if(b%n==0){
		if(c%2==0){
			cout<<c<<" "<<1;
		}else{
			cout<<c<<" "<<n;
		}
		
	}else{
		c++;
		if(c%2==0){
			r=b%n;
			r--;
			cout<<c<<" "<<n-r;
		}else{
			cout<<c<<" "<<b%n;
		}
	}
	
	return 0;
}

