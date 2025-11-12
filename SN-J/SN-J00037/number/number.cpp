#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long j=0,sum=0;
	int n[999999];
	cin>>a;
	for (int i=0;i<a.length();i++){
		if (a[i]<='9' && a[i]>='0'){
			n[j]=a[i]-48;
			j++;
		}
	}	
	sort(n,n+j);
	for (int i=j-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
}
