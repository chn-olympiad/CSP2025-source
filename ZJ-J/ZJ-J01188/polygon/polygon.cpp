#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
const int M=998244353;
void f(int i,int l,int s){
	if(i>n)
		return;
	if(s>a[i]&&l>=2)
		ans++;
	ans%=M;
	f(i+1,l,s);
	f(i+1,l+1,s+a[i]);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	f(1,0,0);
	ans%=M;
	printf("%d\n",ans);
	return 0;
}

