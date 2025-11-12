#include<bits/stdc++.h>
using namespace std;
int n,a[10005],max1,sum,s;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		for(int i=1;i<=n;i++){
		    sum=sum+a[i]; 
	    }
		max1=max(max(a[1],a[2]),max(a[2],a[3]));
		if(max1*2<sum){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=3;i<=n;i++){
		max1=a[i];
		for(int j=1;j<=i-1;j++){
			sum=sum+a[j];
			if(sum*2>max1){
					s++;
				}
			for(int z=1;z<=j;z++){
				sum=sum-a[z];
				if(sum*2>max1){
					s++;
				}
			}
		}
	}
	cout<<s%998244353;
	return 0;
}
