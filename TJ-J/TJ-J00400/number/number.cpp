#include<bits/stdc++.h>
using namespace std;
long long  n[1000000],m,k;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			n[m]=a[i]-48;
			m++;
		}
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<m;i++){
		if(n[i]<n[i+1]){
			swap(n[i],n[i+1]);
		}
	}
	}
	
	for(int i=0;i<m;i++){
		cout<<n[i];
	}
	return 0;
}

