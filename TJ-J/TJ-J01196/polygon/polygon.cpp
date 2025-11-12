#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m=0,c=1;cin>>n;int a[n];
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	if(n>=3){
		for(int i=1;i<n;i++){
		c*=i;
	}
	}
	else{
		if(a[0]+a[1]+a[2]>max(a[0],max(a[1],a[2]))){
			c++;
		}
	}
	cout<<c<<endl;
	return 0;
}
