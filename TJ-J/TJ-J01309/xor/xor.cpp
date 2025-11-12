#include<bits/stdc++.h>
using namespace std;
int arr[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		if(arr[i]==0){
			sum+=1;
		}
		
	}
	
	cout<<sum;
    fclose(stdin);
    fclose(stdout);
}
