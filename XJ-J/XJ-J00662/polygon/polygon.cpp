#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100],sum=0,max=INT_MIN,num=0;
	cin>>n;
	for(int i=2;i<n;i++){
		cin>>a[i];
		for(int j=2;j<n;j++){
				if(n>3){
					sum=sum+a[i]+a[i+1];
					if(max*2<sum){
						if(a[i]>max){
							max=a[i];
							num++;
							}
						
						
				}
				sum=+a[i-2];
				max=0;
		}
		}
	
	}
	
	cout<<num;
	return 0;
}
