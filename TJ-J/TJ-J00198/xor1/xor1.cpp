#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	int c=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==m){
			c++;
		}
		for(int j=0;i<n;j++){
			if(j==i){
				break;
			}
			if((a[i]+a[j])==m){
				c++;
			}
		}
	}
cout<<c<<endl;
return 0;
}
