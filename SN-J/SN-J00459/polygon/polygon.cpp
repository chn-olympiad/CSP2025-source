#include <bits/stdc++.h>
using namespace std;
int n,num=0,maxn=0;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=3;j<=n;j++){
			int m=j;
			while(m--){
				sum+=a[m];	
			}
		}
		if(sum>maxn*2){
			num++;
		}
	}
	cout<<num%998%244%353;
	return 0;
	
}
