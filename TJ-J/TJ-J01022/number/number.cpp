#include<bits/stdc++.h>

using namespace std;
const int MX=1e6+1;
string s;
int a[MX];
int l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
cin>>s;
	int len=sizeof(s);
//	for(int i=0;i<len;i++){
//		if(s[i]<=9&&s[i]>=0){
//			a[i]=s[i];
//		}
//	}
//	for(int i=0;i<len;i++){
//		cout<<a[i];
//	}
	for(int i=0;i<len;i++){
			if(s[i]>=s[i+1]){
//				cout<<s[i];
				continue;
		}else if(s[i]<s[i+1]){
			l=s[i];
			s[i]=s[i+1];
			s[i+1]=l;
			l==0;
//			cout<<s[i];
			}	
	}
	for(int i=0;i<len;i++){
		if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z'){
		continue;
		}else{
			cout<<s[i];
		}
	}
	return 0;
} 
