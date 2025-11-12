#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c=0;
	cin>>n>>k;
	int num[n+1]={0},a[n+1]={0};
	cin>>num[1];a[1]=num[1];
	for(int i=2;i<=n;i++){
		cin>>num[i];a[i]=a[i-1]^num[i];
	}
	for(int i=n;i>0;i--){
		for(int j=i-1;j>=0;j--){
		if(k==(a[j]^a[i])){
				c++;
				i=j;
				break;
			}
		}
	}
	cout<<c<<endl;
	return 0;
} 
