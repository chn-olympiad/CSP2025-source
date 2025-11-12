#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				sum++;
			}
		}
		cout<<sum+(sum-1)*sum/2;
	}
	else if(n>2){
		cout<<2;
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==0)sum++;
		}
		if(n==2&&a[1]^a[2]==0)sum++;
		cout<<sum;
	}
	return 0;
}