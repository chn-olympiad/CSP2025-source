#include <bits/stdc++.h>
using namespace std;
int n,k,i,l,t,w,j,ans,bao,cnt,c[1000010],d[1000010],a[1010][1010];
struct node{
	int x,y;
}b[1000010];
bool cmp(node a,node b){
	return a.y<b.y||(a.y==b.y&&a.x<b.x);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i][i];
	for(l=2;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			t=i;w=i+l-1;
			a[t][w]=(a[t][w-1]^a[w][w]);
		}
	}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			if(a[i][j]==k){
				cnt++;
				b[cnt].x=i;
				b[cnt].y=j;
			}
	if(cnt==0){
		cout<<0;
		return 0;
	}
	sort(b+1,b+1+cnt,cmp);
	ans=1;bao=b[1].y;
	for(i=2;i<=cnt;i++)
		if(b[i].x>bao) bao=b[i].y,ans++;
	cout<<ans;
	return 0;
}
