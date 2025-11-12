#include<bits/stdc++.h>
using namespace std;
const int Modnum=998244353;
typedef long long ll;
int n,a[5005],sm;
void f(ll s,int i,int w,string t,int p=0){
	if(i>w||a[w]<a[i])return;
	if(s>a[w]&&!p)sm++,sm%=Modnum;
	f(s,i+1,w,t,s>a[w]);
	f(s+a[i],i+1,w,t+char(i));
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)f(0,1,i,"");
	printf("%d",sm%Modnum);
	return 0;
}
