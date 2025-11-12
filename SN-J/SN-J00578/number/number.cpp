#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	int m[1000005],n=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>="0"&&a[i]<="9"){
			a[i]=m[n];
			n++;
		}
	}	
	sort(m[0],m[0]+n);
	for(int i=0;i<n;i++){
		cout<<m[i];
	}
	return 0;
}
