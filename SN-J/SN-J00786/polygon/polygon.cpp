#include<bits/stdc++.h>
int n,sum,cnt;
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+2];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n-2;i++){
		cnt=a[i]+a[i+1];
		for(int j=i+2;j<n;j++){
			if(cnt>a[j]){
				sum++;
			}
			cnt+=a[j];
		}
	}
	cout<<sum;
	return 0;
}
