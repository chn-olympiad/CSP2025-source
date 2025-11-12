#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
	if(a>b){
		return true;
	}
	else{
		return false;
	}
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
   string s;
   cin>>s;
   int c=0;
   int t=0;
   for(int i=0;i<s.size();i++){
   	if(s[i]=='0'){
   		t++;
	   }
   	if(s[i]>='0'&&s[i]<='9'){
   		a[i]=s[i]-'0';
   		c++;
	   }
   }
   if(t==c){
   	cout<<0;
   	return 0;
   }
  sort(a,a+s.size(),cmp);
  for(int i=0;i<c;i++){
  	cout<<a[i];
  }

	return 0;
}