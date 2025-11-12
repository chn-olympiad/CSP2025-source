#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,a[1010],xo[1010][1010],cnt,f[1000010][2],ma[1000010];
struct no{
	int l,r;
}b[1000010];
bool cmp(no t,no w){return t.r<w.r||t.r==w.r&&t.l<w.l;}
int check(int x,int w){
	int t,bao=0,mid;
	t=1;w--;
	while(t<=w){
		mid=(t+w)>>1;
		if(b[mid].r<x)bao=mid,t=mid+1;
		else w=mid-1;
	}
	return bao;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++){
			xo[i][j]=a[j]^xo[i][j-1];
			if(xo[i][j]==k){
				b[++cnt].l=i;
				b[cnt].r=j;
			}
		}
	sort(b+1,b+1+cnt,cmp);
	for(i=1;i<=cnt;i++){
		int a1=check(b[i].l,i);
		f[i][1]=ma[a1]+1;
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		ma[i]=max(f[i][1],ma[i-1]);
	}
	cout<<max(f[cnt][0],f[cnt][1]);
	return 0;
}