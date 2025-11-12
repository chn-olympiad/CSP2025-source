#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010],sum=0;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=3;j<=n;j++){
			if(j-i>n) continue;
			int s=0,m=-1;
			for(int k=i;k<=j;k++){
				s+=a[k];
				if(a[k]>m) m=a[k];
			}
			if(s>2*m) sum++;
		}
		
	}
	cout<<sum;
	return 0;
}
