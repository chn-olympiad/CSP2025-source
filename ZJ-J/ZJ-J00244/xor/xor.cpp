#include<bits/stdc++.h>
using namespace std;
//const int N=1E3+4;
//int a[N][N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0,min1=0,num_one=0; 
	cin>>n>>k;
	bool is_special=(k==1);
	int j[n],qz[n],qzz[n]; // j[n]记录值 qz[n]记录异或值 qzz[n]记录qz[n]与k异或的结果 
	for(int i=0;i<n;i++){
		cin>>j[i];
		if(j[i]!=0 && j[i]!=1){
			is_special=0;
		}if(j[i]==1){
			num_one++;
		}
	}
	if(is_special){
		cout<<num_one;
		return 0;
	}
	qz[0]=j[0];
	if(qz[0]==k){
		s++;
	}
	qzz[0]=qz[0]^k;
	for(int i=1;i<n;i++){
		qz[i]=qz[i-1]^j[i];
		qzz[i]=qz[i]^k;
	}
	for(int i=0;i<n;i++){
		for(int j=min1;j<i;j++){
			if(qzz[j]==qz[i]){
				s++;
				min1=i;
				break;
			}
		}
	}
	cout<<s;
	
	
	
	
	
	return 0;
}
