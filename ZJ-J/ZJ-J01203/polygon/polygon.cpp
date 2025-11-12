#include <bits/stdc++.h>
using namespace std;
int n,m=0;
int arr[5010]={};
int summ(int a,int b){
	int q=0;
	for(int i=a;i<=b;i++){
		q+=i;
	}
	return q;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			int sum=summ(i,j);
			if(sum>arr[j]*2){
				m++;
			}
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
