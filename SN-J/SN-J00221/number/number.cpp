#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a[1000100];
	int l=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='a' && s[i]<='z'){
			continue;
		}else{
			a[l]=s[i];
			l++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
