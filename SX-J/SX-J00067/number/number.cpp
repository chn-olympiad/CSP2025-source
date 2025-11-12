#include<bits/stdc++.h>
using namespace std;
char a[1000002];
int b[1000001];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
int len=strlen(a),j=0;
for(int i=0;i<=len-1;i++){
if(a[i]>='0'&&a[i]<='9'){
j++;
b[j]=a[i]-'0';
}
}
int m=j;
while(m--){
int max=-1,maxl=0;
for(int i=1;i<=j;i++){
if(b[i]>max){
max=b[i];
maxl=i;
}
}
cout<<max;
b[maxl]=-1;
}
}