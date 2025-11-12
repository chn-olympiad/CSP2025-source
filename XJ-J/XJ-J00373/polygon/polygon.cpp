#include <bits/stdc++.h>
using namespace std;
int arr[5010];
int count=0;
void work(int n,bool a[],int max,int coun){
	coun=0;
	for(int i=0;i<n;i++){
		if(a[i]==true){
			coun+=arr[i];
			max=a[i];
		}
	}
	if(coun>2*max){
		count++;
	}
	for(int i=0;i<n;i++){
		if(a[i]==true&&a[i+1]==false){
			a[i+1]=true;
			a[i]=false;
			work(n,a,0,0);
			a[i+1]=false;
			a[i]=true;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,count=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	bool arr1[5010]={0};
	for(int i=3;i<n;i++){
		for(int j=0;j<5010;j++){
			arr1[j]=false;
		}
		for(int j=0;j<i;j++){
			arr1[j]=true;
		}
		work(n,arr1,0,0);
	}
	cout<<count%998244353;
	return 0;
}
