#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]<a[i+1]){
			a[1]=a[i];
			a[i]=a[1];
		}
		if(a[i]<b[i]){
			a[1]=b[i];
			b[i]=a[1];
		}
		int c=a[i],d=b[i];
		cout<<c<<d<<endl;
	}
	
	return 0;
} 
