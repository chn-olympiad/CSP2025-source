#include<bits/stdc++.h>
using namespace std;

int a[500000];
int n,k;
int num;

int main(){
	freopen("xor.in",'r',stdin);
	freopen("xor.out",'w',stdout);
	
	cin>>n>>k;
	for(int i=0;i<k;i++){
		cin>>a[i];
		if(a[i]==0)sum++;
		if(a[i]==a[i-1]&&sum)sum++;
	}
	
	cout<<sum;
	
	return 0;
}
