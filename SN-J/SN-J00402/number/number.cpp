#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[1000005],n;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n;i++){
		a[i+1]=n;
	}
	for(int i=0;i<=n;i++){
		if(a[i]<a[i+1]){
			a[i]=a[i+1];
		}
		cout<<a[i];
	}
	return 0;
}
