#include<bits/stdc++.h>
using namespace std;

int main(){
   char s[100050];
   cin>>s;
   int n=0,sz[1050]={},f=1;
   n=strlen(s);
   for(int i=0;i<n;i++){
   	if(s[i]-'0'<=9&&s[i]-'0'>=0){
   		sz[f]=s[i]-'0';
   		f++;
	   }
   }
   sort(sz+1,sz+f);
   for(int i=f-1;i>0;i--){
   	cout<<sz[i];
   }
   return 0;
} 
