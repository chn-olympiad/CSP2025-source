#include<bits/stdc++.h>
using namespace std;
int a[1000001];
char in[1000001],p;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=1;
	while(in[k++]=getchar()) if(in[k-1]==(char)10) break;
	int len=k-2,n=1,d=0;
	for(int i=1;i<=len;i++) if(in[i]<=57&&in[i]!=10){
		a[n++]=in[i];
		d++; 
	}           
	sort(a+1,a+1+d,cmp);
	for(int i=1;i<=d;i++) cout<<a[i]-48;
	return 0;
}