#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("polygon.in","z",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100005],maxx=-1e9,minn=1e9,t[100005],m,z[100005],num=0;
	cin>>n;
	cout<<n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[maxx]<a[i]){
			maxx=i;
		}
		
	}
	for(int j=0;j<n;j++){
		
		num+=a[j];
		
	}
	if(num>maxx*2){
		cout<<1;
	}
	
		
	
	return 0;
}
