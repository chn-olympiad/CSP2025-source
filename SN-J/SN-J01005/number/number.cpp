#include<bits/stdc++.h>
using namespace std;
string a;
int s[10000001],j=0; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
	s[j]=a[i]-'0';
	j++;	
	}
	}
	sort(s,s+j);
	for(int i=j-1;i>=0;i--)cout<<s[i];
	return 0;
}
