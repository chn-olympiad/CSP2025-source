#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	scanf("%d%d",&n,&k);
	int a[N]={0};
	int ans=0;
	
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		a[i]=(a[i-1] xor x);
		int y=(a[i] xor k);
		for(int j=i;j>=1;--j){
			if(vis[j])break;
			if(a[j-1]==y){
				vis[j]=1;
				vis[i]=1;
				ans++;
				break;
			}
		}
	}printf("%d",ans);
	return 0;
}
