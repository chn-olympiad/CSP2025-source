#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn],len=0;
bool cmp(int X,int Y){
	return Y<X;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char x;
	while(cin>>x) if(isdigit(x)) a[++len]=x-'0';
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++) printf("%d",a[i]);
	return 0;
}