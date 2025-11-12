#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polyon.in","r",stdin);
	freopen("polyon.out","w",stdout);
	int n,a[5005],maxm=0,sum=0;
	cin>>n; 
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxm=max(a[i],maxm);
		sum+=a[i];
	}
	if(sum>maxm*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
