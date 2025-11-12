#include <bits/stdc++.h>
using namespace std;
long long tt(int x){
	int sum=1;
	for(int i=1;i<=x;i++)sum*=i;
	return sum;
}
inline long long C(int n,int k){
	return tt(n)/tt(k)*tt(n-k);
}

int a[5000];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt=0;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i]+a[j]+a[k]>max( max(a[i],a[j]),a[k] )*2){
					//cout<<a[i]<<' '<<a[j]<<' '<<a[k]<<'\n'; 
					cnt++;
					for(int l=1;l<=k-3+1;l++){
						cnt+=C(k-3+1,l);
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}

