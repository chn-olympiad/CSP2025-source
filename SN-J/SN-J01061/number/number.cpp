#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n[a.length()];
	for(int i=0;i<a.length();i++){
		n[i]=-1;
	}
	for(int i=0;i<a.length();i++){
		if('0'<=a[i] && a[i]<='9'){
			n[i]=a[i]-'0';
		}
	}sort(n,n+a.length());
	for(int i=a.length()-1;i>=0;i--){
		if(n[i]!=-1){cout<<n[i];}
	}return 0;
}
