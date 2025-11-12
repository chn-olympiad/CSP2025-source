#include<bits/stdc++.h>
using namespace std;
string s; 
int a[1000005],q;
int main(){
   freopen("number.in","r",stdin); 
   freopen("number.out","w",stdout);
   cin>>s;
   for(int i=0;i<s.size();i++){
   	if(s[i]-'0'>=0&&s[i]-'0'<=9){
   		a[i]=s[i];
   		q++;
	   }
   }
    sort(a,a+s.size(),greater<int>());
   for(int i=0;i<q;i++){
   	cout<<a[i]-'0';
   }
   return 0;
}
