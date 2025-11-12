#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,count=0;
	cin>>n;
	int s[n];
	for(int q=0;q<n;q++){
		cin>>s[q];
	}
	for(int q=n-2;q>0;q--){
		count=count+q;
	}	
	cout<<count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
