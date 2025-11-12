#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
