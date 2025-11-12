#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long arr[100000];
	int a,sum,m;
	string s;
	for(;;){
		cin>>s;
	    if(s>'0'&&s<='9'){
		arr[m]=s;
		m++;
		}	
	}
	for(int l=0;l<=m;l++){
		if(arr[l]<arr[l+1]){
			a=arr[l];
			arr[l]=arr[l+1];
			arr[l+1]=a;
			a=arr[l+1];
		}else if(a<arr[l]){
			a=arr[l];
			l=1;
		}else{
		    int a=arr[l];
		}
	}
	for(int i=0;i<=m;i++){
		sum=sum*10+arr[i];
	}
	cout<<sum;
	return 0;
} 
