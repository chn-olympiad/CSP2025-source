#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor5.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0,g;
	cin>>n>>k;
	int a[500001]={};
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	i=1;
	g=0;
	while(i<=n){
		if(a[i]==k){
			sum++;
			i++;
			g=0;
		}
		g^=a[i];
		if(g==k){
			sum++;
			g=0;
		}
		i++;
	}
	cout<<sum;
	return 0;
}
