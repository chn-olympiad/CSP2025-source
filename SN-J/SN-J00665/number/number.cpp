//SN-J00665  樊楷宁  西安市雁塔区第一学校 
#include<bits/stdc++.h>
using namespace std;
string s,t;
int a[15],sum=0;
int main(){
	freopon("number.in","r",stdin);
	freopon("number.out","w",stdout);
   cin>>s;
   int n=s.size();
   for(int i=0;i<n;i++){
   	if(s[i]>='1'&&s[i]<='9'){
   		a[s[i]-'0']++;
	   }
   }
   for(int i=9;i>=0;i--){
    	if(a[i]!=0){
   	        for(int j=0;j<a[i];j++){
   			t+=(char)i+'0';
	        }
	   }
   }
   cout<<t;
	return 0;
}
