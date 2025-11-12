#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],sum=0,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]^a[i]==k||a[i]^a[i+1]==k){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
