#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x,ans;
	cin>>n>>m;
	if((m<1||m>10)||(n<1||n>10))
		return 0;
	int a=n*m;
	int num[a];
	for(int i=0;i<a;i++){
		cin>>num[i];
	}
	for(int i=0;i<a;i++){
		for(int j=i+1;j<n;j++){
			if(num[i]==num[j])
				return 0;
		}
	}
	x=num[0];
	for(int i=0;i<a;i++){
		for(int j=i;j<a;j++){
			if(num[i]<num[j]){
				int m=num[i];
				num[i]=num[j];
				num[j]=m;
			}
		}
	}
	for(int i=0;i<a;i++){
		if(num[i]==x){
			ans=i+1;
		}
	}
	cout<<ans/m+(ans%m)<<" ";
	if((ans/m+1)%2==0)
		if(m-(ans%m)==m-1)
			cout<<m;
		else
			cout<<n-(ans%m);
	else{
			cout<<ans%m;
	}
		
	return 0;
} 
