#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
int n=0,b[101]={},o=0,c=0,g;
getline(cin,a);
n=a.size();

for(int i=0;i<n;i++){
	if(a[i]>='0'&&a[i]<='9'){

	if(a[i]=='2'){
	b[o]=2;o++;}
	else if(a[i]=='1'){
	b[o]=1;o++;}
	else if(a[i]=='3'){
	b[o]=3;o++;}
	else if(a[i]=='4'){
	b[o]=4;o++;}
	else if(a[i]=='5'){
	b[o]=5;o++;}
	else if(a[i]=='6'){
	b[o]=6;o++;}
	else if(a[i]=='7'){
	b[o]=7;o++;}
	else if(a[i]=='8'){
	b[o]=8;o++;}
	else if(a[i]=='9'){
	b[o]=9;o++;}
	else if(a[i]=='0'){
	b[o]=0;
	o++;}

}}
int num=0;
for(int i=0;i<o;i++){
for(int j=0;j<o;j++){
if(b[j]>=c){
c=b[j];
g=j;
}
}
cout<<c;
c=0;
b[g]=-1;

fclose(stdin);
fclose(stdout);
}
return 0;
}