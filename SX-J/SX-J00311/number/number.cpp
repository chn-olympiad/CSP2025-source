#include<bits/stdc++.h>
using namespace std;
int b[1000000];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
int c=0;
cin>>a;
int l=a.size();
for(int i=0;i<l;i++){
	if(a[i]>='0'&&a[i]<='9'){
    b[i]=a[i]-48;
     c++;
	}
}
for(int i=0;i<l;i++){
	for(int j=0;j<i;j++){
	if(b[i]>b[j]){
	swap(b[i],b[j]);
}
	}
	}
for(int i=0;i<c;i++){
	cout<<b[i];
}
fclose(stdin);
fclose(stdout);
return 0;
}
