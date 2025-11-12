#include<bits/stdc++.h>
using namespace std;
string a;
int s=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	int b[n+1];
	for(int i=0;i<n;i++){
		if(a[i]>=48&&a[i]<=57){
			b[s]=a[i]-48;
			s++;
		}
	}
	sort(b,b+n);
	for(int i=s-1;i>=0;i--)
		cout<<b[i];
	return 0;
} 
