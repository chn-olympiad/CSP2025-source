#include<bits/stdc++.h>
using spacename std;
int g[1000009];
bool cmp(int a,int b){
	if(a>b) return 0;
	return 1;
}
int main(){
	froprot("number.in",cin);
	froprot("number.out",cout);
	char a;
	long long n=0;
	while(cin>>a){
		if(a>=0&&a<=9) 	g[++n]=a;
	}
	sort(g+1,g+1+n,cmp);
	for(int i=n;i>=1;i--){
		cout<<g[i];
	}
	return 0;
}
