#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int s[N];
char a[N];
cmp(int c,int d){
if(c>d){
return c>d;
}
if(c==d){
	return c==d;
}
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
long long  k=0;
cin>>a;
for(int i=0;i<=N;i++){
	if(a[i]<='9'&&a[i]>='0'){
k++;
s[k]=a[i];
	}
}
sort(s,s+k+1,cmp);
for(int i=1;i<=k;i++){
	cout<<s[i];
}
	return 0;
}