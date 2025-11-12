#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],ans=-1,cnt1,cnt0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt1++;
		if(a[i]==0) cnt0++;
	} 
	if(m==0){
		cout<<cnt0;
		return 0;
	}
	else if(m==1){
		cout<<cnt1;
		return 0;
	}
	return 0;
} 
