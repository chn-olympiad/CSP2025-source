#include<bits/stdc++.h>
using namespace std;

long long n,c,c1,c3,flag,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			c3++;
		}
		if(a[i]!=1){
			flag=1;
		}
		if(a[i]!=1 &&a[i]!=0){
			c1=1;
		}
	}
	if(flag==0){
		cout<<n/2;
		return 0;
	}
	if(c1==0){
		cout<<c3/2;
		return 0;
	}
	
	return 0;
}



