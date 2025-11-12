#include<bits/stdc++.h>
using namespace std;
long long a[5001],i,j,k,l,ans,num,maxx,n;
void bfs(int num,int longs,int shu){
	if(num==n+1){
		return;
	}
	if(shu+1>2 && a[num]<longs){
		ans++;
		ans%=998244353;
	}bfs(num+1,longs+a[num],shu+1);
	 bfs(num+1,longs,shu);

}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}sort(a+1,a+n+1);
	bfs(0,0,0);
	cout<<ans/2;
	return 0;
}


