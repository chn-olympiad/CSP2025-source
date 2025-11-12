#include<bits/stdc++.h>
using namespace std;
int xooor[500005],a[500005];
int g(int a){
	string s;
	int k=1;
	while(a>0){
		s[k]=(!(a%2))+'0';
		a/=2;
		k++;
	}
	int j=1,sum=0;
	for(int i=k-1;i>=1;i--){
		sum+=(s[i]-'0')*j;
		j*=2;
	}
	return sum;
}
int xoor(int a,int b){
	return g((a&b)|(g(a)&g(b)));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum1=0,sum2=0;
	cin>>n>>k;
	bool flag1=1,flag0=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag1=0;
		}
		else{
			sum1++;
		}
		if(a[i]!=0&&a[i]!=1){
			flag0=0;
		}
		if(a[i]==0){
			sum2++;
		}
		if(a[i]==1&&a[i-1]==1){
			sum2++;
			a[i]=0;
		}
		xooor[i]=xoor(xooor[i-1],a[i]);
	}
	if(flag1){
		cout<<n/2;
		return 0;
	}
	else if(flag0&&k){
		cout<<sum1;
		return 0;
	}
	else if(flag0&&(!k)){
		cout<<sum2;
		return 0;
	}
	return 0;
}
