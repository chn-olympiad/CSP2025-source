#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	int s[10000];
	cin>>a;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0' && a[i]<='9'){
			s[n]=a[i];
			n++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i]>s[j]){
				int f=s[j];
				s[j]=s[i];
				s[i]=f;
			}
		} 
	} 
	for(int i=0;i<n;i++){
		cout<<char(s[i]);
	} 
	return 0;
}
