#include<bits/stdc++.h>
using namespace std;
short a[20000000];
int main(){
	//cout<<int('0');//48
	//cout<<int('9');//57
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[j]=s[i]-48;
			j++;
		}
	} 
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
		//cout<<i;
	}
	return 0;
} 
