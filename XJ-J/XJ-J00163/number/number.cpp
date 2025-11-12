#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[15]={0};
	cin>>s;
	for(int i=1;i<=a[s.size()];i++){
		a[s.size()]='a'-'A';
		if(a[s.size()]==a[i]-'0'){
			if(a[i+1]>a[i]){
					cout<<a[i+1]<<a[i];
				} 
			else if(a[i+1]<=a[i]){
					cout<<a[i]<<a[i+1];
				} 
			}
	}
	cout<<s;	
	return 0;
} 
