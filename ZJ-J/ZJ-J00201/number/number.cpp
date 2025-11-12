#include<bits/stdc++.h>
using namespace std;
int i,t,b[1000010];
char a[1000010];
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a+1;
	for(i=1;i<=strlen(a+1);i++){
		if(a[i]>='0'&&a[i]<='9')b[++t]=(a[i]-48);
	}
	sort(b+1,b+1+t,cmp);
	for(i=1;i<=t;i++)cout<<b[i];
}
