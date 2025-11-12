#include<bits/stdc++.h>
using namespace std;
int maxxs;
int sum;
int cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+10];
	for(int i=0;i<n+10;i++){
		a[i]=0;
//		maxxs+=a[i];
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
//		maxxs+=a[i];
	}
	for(int i=0;i<n;i++){
		maxxs+=a[i];
	}
	for(int i=0;i<n-3;i++){
		for(int j=0;j<3+i;j++){
		sum=a[j];
			if(sum<a[j+1]){
			sum=a[j+1];
			}
//			maxxs+=a[j];
			if(maxxs>sum*2){
				cnt++;
			}
		}
	}
//	for(int j=0;j<3+i;j++){
//		sum=a[j];
//		if(sum<a[j+1]){
//			sum=a[j+1];
//		}
//	}
//	for(int i=2;i<n;i++){
//		for(int j=0;j<n;j++){
//			if()
//		}
//	}
	cout<<cnt;

	fclose(stdin);
	fclose(stdout);
return 0;
}
