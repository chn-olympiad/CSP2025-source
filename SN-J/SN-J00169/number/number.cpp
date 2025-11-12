//原梓轩 SN-J00169 440514201308033019 陕西-西安-锦园中学 
#include<bits/stdc++.h>
using namespace std;
int a[1000005],j;
string s;
bool cmp(int a,int b){
	return a>b;
}
int  main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
