#include<bits/stdc++.h>
using namespace std;
int n,k,tot;
struct ZZH{
	int L,R;
	bool flg;
}vis[500005];
int pos[500005],p;
long long a[500005],sum[500005],ans;
long long read(){
	long long ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	sum[1]=a[1]=read();
	for(int i=2;i<=n;i++){
		a[i]=read(),sum[i]=sum[i-1]^a[i];
		if(sum[i]==k)pos[i]=i;
		else pos[i]=pos[i-1];
		if(a[i]>1)p=1;
	}
	if(p==0) {
		ans=0;
		for(int i=1;i<=n;i++)if(a[i]==k)ans++;
		cout<<ans;
		return 0;
	}
//	for(int i=1;i<=n;i++)cout<<sum[i]<<" ";
	for(int i=1;i<=n;i++){
		if(sum[i]==k)ans++,vis[++tot].L=i,vis[tot].R=i;
		else if(sum[i]==0&&pos[i])ans++,vis[++tot].L=pos[i],vis[tot].R=i;
	}
//	for(int i=1;i<=tot;i++)cout<<vis[i].L<<" "<<vis[i].R<<'\n';
//	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++){
		if((sum[j]^sum[i-1])==k&&i!=j)ans++,vis[++tot].L=i,vis[tot].R=j;
	}
//	cout<<ans<<'\n';
//	for(int i=1;i<=tot;i++)cout<<vis[i].L<<" "<<vis[i].R<<'\n';
	for(int i=1;i<=tot;i++)
	for(int j=i;j<=tot;j++){
		if(vis[j].flg||vis[i].flg||i==j)continue;
		if(vis[i].L<=vis[j].L&&vis[i].R>=vis[j].L)k=vis[i].R-vis[i].L>vis[j].R-vis[j].L?i:j,vis[k].flg=1,ans--;
		else if(vis[i].L<=vis[j].R&&vis[i].R>=vis[j].R)k=vis[i].R-vis[i].L>vis[j].R-vis[j].L?i:j,vis[k].flg=1,ans--;
		else if(vis[i].L<=vis[j].L&&vis[i].R>=vis[j].R)vis[i].flg=1,ans--;
	}
	cout<<ans<<'\n'; 
	return 0;
}
