#include <bits/stdc++.h>
using namespace std;
int n,k,sum=0;
int arr[500010]={};
bool brr[500010]={0};
bool p(int a,int b){
	for(int i=a;i<=b;i++){
		if(brr[i]==1){
			return 0;
		}
	}
	return 1;
}
void q(int a,int b){
	for(int i=a;i<=b;i++){
		brr[i]=1;
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]==k){
			sum++;
			brr[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int num=arr[i];
			if(p(i,j)){
				int x=i+1;
				while(x<=j){
					num^=arr[x];
					x++;
				}
				if(num==k){
					sum++;
					q(i,j);
				}
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
