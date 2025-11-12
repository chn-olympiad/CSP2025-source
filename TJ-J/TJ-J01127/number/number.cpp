#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[10000]={},cnt=0,b[10000]={};
	cin>>s;
	int l=s.length();
	if(l==1){
		cout<<s;
	}
	else{
		for(int i=0;i<l;i++){
			if(s[i]<='9' && '0'<=s[i]){
				a[i]=s[i];
				cnt++;
			}
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
//	290es1q0
	return 0;
} 
