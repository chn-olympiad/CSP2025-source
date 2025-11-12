#include<bits/stdc++.h>

using namespace std;
int a[5009];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	int sum=0;
	for(int i=1;i<n-1;i++){
		for(int j=i+2;j<=n;j++){
			int cnt=0;
			int maxn=0;
			for(int q=i;q<=j;q++){
				cnt+=a[q];
				maxn=max(maxn,a[q]);
			}
			
			if(cnt>2*maxn){
				sum++;
			}
		}
	}
	sum=sum%998%244%353;
	cout<<sum;
	 
	return 0;
}
