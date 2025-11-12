#include<bits/stdc++.h>
using namespace std;
int n,a[10050];
int main(){
	freopen("polygon.in","r",stdin); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int sum=1;
	for(int i=3;i<=n-1;i++){
		for(int j=1;j<=n-i+1;j++){
			for(int k=0;k<=n-1;k++){
				if(a[j]+a[j+k]+a[j+k+1])
			}
		}
	}
	freopen("polygon.out","w",stdout); 
	return 0;
}

