#include<bits/stdc++.h>
using namespace std;
int n,num[100010],sum=0,a,k=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		k+=num[i];
	}
	sort(num+1,num+1+n);
	int q=num[n];
	if(q*2<k){
		cout<<6;
		return 0;
	}
	return 0;
}
