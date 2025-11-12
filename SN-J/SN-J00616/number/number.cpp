#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int x[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a+=s[i];
		}
	}
	for(int i=0;i<a.length();i++){
		if(a[i]=='9') x[9]++;
		else if(a[i]=='8') x[8]++;
		else if(a[i]=='7') x[7]++;
		else if(a[i]=='6') x[6]++;
		else if(a[i]=='5') x[5]++;
		else if(a[i]=='4') x[4]++;
		else if(a[i]=='3') x[3]++;
		else if(a[i]=='2') x[2]++;
		else if(a[i]=='1') x[1]++;
		else if(a[i]=='0') x[0]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=x[i];j>=1;j--){
		
		cout<<i;}
	}
	return 0;
}

