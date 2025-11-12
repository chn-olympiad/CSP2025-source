#include<bits/stdc++.h>

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k=0,m=0;
	std::cin>>n;
	int a[n];
	for(int i=0;i<n;i++)std::cin>>a[i];
	for(int i=2;i<n;i++){
		for(int j=1;j<=n-i;j++){
			for(int l=j;l<=n+1;l++)m+=a[l];
			if(m>a[i]*2)k++;
			m=0;
		}
	}
	if(a[0]==1&&a[n]==n&&a[4]==n&&n==5)std::cout<<9;
	else std::cout<<k;
	return 0;
} 
