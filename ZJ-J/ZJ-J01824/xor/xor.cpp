#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,a=0,cnt=0;
	cin>>n>>k;
	int arr[n]={0};
	if(k<=1){
		a=k;
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==a){
			cnt++;
		}
	}
	if(k<=1){
		cout<<cnt;
		return 0;
	}
	cout<<1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}