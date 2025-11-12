#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long int n=a.size();
	long long int z[n+5]={},c=0;
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			z[c]=a[i]-48;
			c++;
		}
	}
	sort(z,z+c);
	for(int i=c-1;i>=0;i--){
		cout<<z[i];
	}
	return 0; 
} 
