#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	char s[1000];
	int max=0;
	cin>>s;
	for(int i=0;i<=10;i++){
		if(s[i]<s[i+1]){
			max=s[i+1];
			s[i+1]=s[i];
		}
	}
	cout<<s;
	return 0;
} 
