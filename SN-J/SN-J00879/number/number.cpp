#include<bits/stdc++.h>
using namespace std;
freopen("number.in",'r',stdin);
freopen("number.out",'w',stdout);

int main(){
	string s,a;
	cin>>s;
	long long b;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a+=s[i];
		}
	}
	for(int j=1;j<a.size();j++){
		
		if(a[j]>=a[j-1]){
			b=a[j-1];
			a[j-1]=a[j];
			a[j]=b;
		}
	}
	cout<<a;
	return 0;
}
