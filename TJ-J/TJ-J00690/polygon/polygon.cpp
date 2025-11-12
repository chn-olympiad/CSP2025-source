#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
	cin>>n;
	int a[5010];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i]+a[j]+a[k]>a[k]*2){
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
return 0;


}
