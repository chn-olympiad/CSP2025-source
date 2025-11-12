#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	char b;
	cin>>s;
	int j=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[j]=s[i];
			j++;
		}
	}
	for(int i=0;i<j;i++){
		for(int m=0;m<j;m++){
			if(a[m]<a[m+1]){
				b=a[m];
				a[m]=a[m+1];
				a[m+1]=b;
			}
		}
	}
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
