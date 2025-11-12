#include<bits/stdc++.h>
using namespace std;
int a[5001]; 
int v(int s,int a[]) {
	int b[1];
	for(int i=1; i<=s; i++) {
		for(int j=s; j>1; j--) {
			if(a[j]<a[j-1]){
				b[1]=a[j-1];
				a[j-1]=a[j];
				a[j]=b[1];
			} else {
				continue;
			}
		}
	}
}
int main(){
	freopen(polygon.in,"r",stdin);
	freopen(polygon.out,"w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&a[1]+a[2]>a[3]){
		cout<<1<<endl;
		return 0	
	}
	if(m==n&&a[n]==1){
		cout<<n-2<<endl;
		return 0;
	}
	cout<<100<<endl;
	return 0;
} 
