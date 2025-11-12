#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
freopen("number.in",r,stdin);
freopen("number.out",w,stdout);
cin>>s;
int b=0;
int i=0;
int c=0;
while(s[c]){
	c++;
}
for(int j=0;j<c;j++){
	if(s[j]>=48&&s[j]<=57){
		a[i]=s[j]-48;
		i++;
	}
}
sort(a,a+i);
for(int j=i-1;j>=0;j--){
cout<<a[j];
}
return 0;
} 
