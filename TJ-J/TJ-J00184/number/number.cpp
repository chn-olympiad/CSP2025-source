#include<bits/stdc++.h>
using namespace std;//服了，8点半才开始12点整收卷，30分钟被吃了 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string zf;
	cin>>zf;
	int js=0,n=zf.length();
	int a[n+5];
	memset(a,99,sizeof(a));
	for(int i=0;i<n;i++){
		if(zf[i]>'9'||zf[i]<'0')continue;
		a[i]=zf[i]-'0';
		js++;
	}
	sort(a,a+n+5);
	for(int i=js-1;i>=0;i--)cout<<a[i];
	return 0;
}
