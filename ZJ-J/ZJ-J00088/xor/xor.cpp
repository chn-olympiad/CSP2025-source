#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,x,ans,a[N];
bool q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		x=x^a[i];
		if(x==k){
			x=0;
			ans++;
		}
	}
	if(x==k)ans++;
	printf("%d",ans);
	return 0;
}
