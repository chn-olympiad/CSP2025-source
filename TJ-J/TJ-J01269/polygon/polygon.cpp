#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=0,ans=0;
	cin>>n;
	if(n<3||n>500)
		return 0;
	int a[5001];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<1||a[i]>5000)
			return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i]<a[j]){
				int m=a[i];
				a[i]=a[j];
				a[j]=m;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int c=0;
			for(int k=j;k<n;k++){
				c+=a[k];
				if(c>a[i])
					ans+=1;
			}
		}
	}
	cout<<ans;
	return 0;
} 
