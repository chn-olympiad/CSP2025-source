#include<bits/stdc++.h>
using namespace std;
int arr[1000000+5];
string s,n;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s); 
	int len=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			arr[len]=s[i]-48;
			len++;
		}
	}
	for(int i=0; i<len; i++) {
		int maxx=-1,maxn=0;
		for(int j=0; j<len; j++) {
			if(arr[j]>maxx){
				maxx=arr[j];
				maxn=j;
			}
		}
		arr[maxn]=-1;
		n+=char(maxx+48);
	}
	cout<<n;
	return 0;
}
