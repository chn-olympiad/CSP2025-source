#include<bits/stdc++.h>
using namespace std;
int n1[5002];
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n,a=0;
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>n1[i];
	}
	for(int i = 1;i<=n;i++){
		if((n1[i]+n1[i+1]+n1[i+2])>(max(n1[i],max(n1[i+1],n1[i+2]))*2)){
			a+=1; 
		}
		if((n1[i]+n1[i+1]+n1[i+2]+n1[i+3])>(max(n1[i],max(n1[i+1],max(n1[i+2],n1[i+3])))*2)){
			a+=1;
		}
		if((n1[i]+n1[i+1]+n1[i+2]+n1[i+3]+n1[i+4])>(max(n1[i],max(n1[i+1],max(n1[i+2],max(n1[i+3],n1[i+4]))))*2)){
			a+=1;
		}
	}
	cout<<a;
	return 0;
}
