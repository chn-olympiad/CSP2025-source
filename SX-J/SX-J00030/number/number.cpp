#include<bits/stdc++.h>
using namespace std;

string x;
int a[1000010];
long long z;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	long long x1=x.size();
	for(long long i=0;i<x1;i++){
		if(x[i]>='0'&&x[i]<='9') a[z++]=x[i]-'0';
	}
	sort(a,a+z,cmp);
	for(long long i=0;i<z;i++){
		cout<<a[i];
	}
	return 0;
}