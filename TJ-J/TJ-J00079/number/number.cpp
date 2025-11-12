#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string a;
	cin>>a;
	int n=a.length();
	string z;
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9')z+=a[i];
	}
	sort(z.begin(),z.end());
	int m=z.length();
	for(int i=m-1;i>=0;i--){
		cout<<z[i];
	}
	return 0;
}
