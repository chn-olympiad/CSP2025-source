#include<bits/stdc++.h>
using namespace std;
int c(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000000];
	cin>>a;
	int b=strlen(a);//记录数组长度 
	char d[1000000];//新数组 
	int e=0;
	for(int i=0;i<b;i++){
		if(a[i]>=48&&a[i]<=57){
			e++;
			d[e]=a[i];
		}
	}
	sort(d+1,d+e+1,c);
	for(int i=1;i<=e;i++){
		cout<<d[i];
	}
	return 0;
}
