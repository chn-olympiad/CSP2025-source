#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	
	int n,sum=1;
	cin>>n;
	int a={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-2;i<=1;i--){
		sum+=i
	}
	if(n>=5){
		sum+=(4+(n-5))
	}
	cout<<sum;
	
	fclose(in);
	fclose(out);
	return 0;
}
