#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+10;
ll T,n,a[N][5],sumn[N],d,ans,o[N],bl,cl,dl,p[N];
ll read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
ll cmp(ll xx,ll yy){
	return xx>yy;
}
void dfs(ll pos,ll sum){
	if(pos==n+1){
		ans=max(ans,sum);
		return ;
	}
	//if(pos==n-1&&sum+max(max(a[pos][1],a[pos][2]),a[pos][3])<ans)
	//	return ;
	for(ll i=1;i<=3;i++){
		if(i==1){
			if(bl>=n/2)
				continue;
			else{
				bl++;
				dfs(pos+1,sum+a[pos][i]);
				bl--;
			}
		}
		if(i==2){
			if(cl>=n/2)
				continue;
			else{
				cl++;
				dfs(pos+1,sum+a[pos][i]);
				cl--;
			}
		}
		if(i==3){
			if(dl>=n/2)
				continue;
			else{
				dl++;
				dfs(pos+1,sum+a[pos][i]);
				dl--;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		memset(o,0,sizeof(o));
		memset(p,0,sizeof(p));
		n=read();
		bool flag=false;
		ll gh=0;
		ans=0;
		for(ll i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
		}
		for(ll i=1;i<=n;i++){
			if(a[i][3]!=0){
				flag=true;
				break;
			}
		}
		if(flag==false)
			gh=1;
		flag=false;
		for(ll i=1;i<=n;i++){
			if(a[i][2]!=0||a[i][3]!=0){
				flag=true;
				break;
			}
		}
		if(flag==false)
			gh=2;
		if(gh==2){
			for(ll i=1;i<=n;i++){
				o[i]=a[i][1];
			}
			sort(o+1,o+1+n,cmp);
			for(ll i=1;i<=n/2;i++){
				ans+=o[i];
			}
		}
		else if(gh==1){
			for(ll i=1;i<=n;i++){
				o[i]=a[i][1];
			}
			for(ll i=1;i<=n;i++){
				p[i]=a[i][2];
			}
			sort(o+1,o+1+n,cmp);
			sort(p+1,p+1+n,cmp);
			for(ll i=1;i<=n/2;i++){
				ans+=(o[i]+p[i]);
			}
		}
		else{
			dfs(1,0);
		}
		sumn[++d]=ans;
	}
	for(ll i=1;i<=d;i++){
		cout<<sumn[i]<<"\n";
	}
	return 0;
}
