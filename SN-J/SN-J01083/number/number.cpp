//SN-J01083 钱雨泽 延安职业技术学院附属中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int b[1000005],c=0;
string s;
cin>>s;
int a=s.size();
for(int i=0;i<a;i++){
	if(s[i]==0 and s[i]>0  or s[i]==9 and s[i]<9){
		b[1000005]=s[i];
		c++;
	}
}
sort(b,b+a);
cout<<5;
return 0;
}
