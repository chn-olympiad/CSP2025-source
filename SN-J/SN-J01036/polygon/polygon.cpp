#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	int sum;int m;int count=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[j]>a[i]){
				m=a[i];
				a[i]=a[j];
				a[j]=m;
			}
		}
	}
	for(int i=n-1;i>1;i--){
		sum=a[i];
		for(int j=i-1;j>=0;j--){
			if(sum+a[j]>=a[i]*2){
				count++;
			}
		}
	}
	cout<<count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
