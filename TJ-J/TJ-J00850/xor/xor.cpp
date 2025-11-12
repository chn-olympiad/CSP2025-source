#include<bits/stdc++.h> 
using namespace std;
int n,a[500003],k,cnt,sum,an;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)cnt=1;
		if(a[i]!=0&&a[i]!=1)sum=1;
		if(a[i]==1)an++;
	}
	if(cnt==0)cout<<n/2;//A部分分
	else if(sum==0){//B部分分 
		if(k==1)cout<<an;
	}
	return 0;
}
