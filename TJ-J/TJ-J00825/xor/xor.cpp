#include<bits/stdc++.h>
using namespace std;
int n,k,num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int m=a[i];
		for(int j=i+1;j<n;j++){
			m+=m^a[j];
			if(m==k){
				num++;
				break;
			}
		}
	}
	cout<<num;
	return 0;
} 
