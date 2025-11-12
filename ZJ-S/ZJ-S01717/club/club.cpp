#include<bits/stdc++.h>
using namespace std;
long long n,t,ans,m,suma,sumb,sumc;
struct node{
	long long a;
	long long b;
	long long c;
	long long da;
	long long db;
	long long dc;
};
node hg[100005],hgg[100005];
bool cmp1(node x,node y){
	if(x.da>y.da)return 1;
	return 0;
}bool cmp2(node x,node y){
	if(x.db>y.db)return 1;
	return 0;
}bool cmp3(node x,node y){
	if(x.dc>y.dc)return 1;
	return 0;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		suma=0;
		sumb=0;
		sumc=0;
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++)cin>>hg[i].a>>hg[i].b>>hg[i].c;
		for(int i=1; i<=n; i++){
			if(hg[i].a>=hg[i].b&&hg[i].a>=hg[i].c) suma++;
			else if(hg[i].b>=hg[i].c&&hg[i].b>=hg[i].a) sumb++;
			else sumc++;
		}if(suma>=sumb&&suma>=sumc){
			if(suma>n/2)suma=n/2;
			for(int i=1; i<=n; i++)hg[i].da=hg[i].a-max(hg[i].b,hg[i].c);
			sort(hg+1,hg+1+n,cmp1);
			for(int i=1; i<=suma; i++){
				if(hg[i].da>=0)ans+=hg[i].a;
			}for(int i=suma+1; i<=n; i++){
				hgg[i-suma].b=hg[i].b;
				hgg[i-suma].c=hg[i].c;
				hgg[i-suma].db=hg[i].b-hg[i].c;
			}int m=n-suma;
			sort(hgg+1,hgg+1+m,cmp2);
			for(int i=1; i<=m; i++){
				if(hgg[i].db>=0)ans+=hgg[i].b;
				else ans+=hgg[i].c;
			}
		}else if(sumb>=suma&&sumb>=sumc){
			if(sumb>n/2)sumb=n/2;
			for(int i=1; i<=n; i++)hg[i].db=hg[i].b-max(hg[i].a,hg[i].c);
			sort(hg+1,hg+1+n,cmp2);
			for(int i=1; i<=sumb; i++){
				if(hg[i].db>=0)ans+=hg[i].b;
			}for(int i=sumb+1; i<=n; i++){
				hgg[i-sumb].a=hg[i].a;
				hgg[i-sumb].c=hg[i].c;
				hgg[i-sumb].da=hg[i].a-hg[i].c;
			}m=n-sumb;
			sort(hgg+1,hgg+1+m,cmp1);
			for(int i=1; i<=m; i++){
				if(hgg[i].da>=0)ans+=hgg[i].a;
				else ans+=hgg[i].c;
			}			
		}else{
			if(sumc>n/2)sumc=n/2;
			for(int i=1; i<=n; i++)hg[i].dc=hg[i].c-max(hg[i].a,hg[i].b);
			sort(hg+1,hg+1+n,cmp3);
			for(int i=1; i<=sumc; i++){
				if(hg[i].dc>=0)ans+=hg[i].c;
			}for(int i=sumc+1; i<=n; i++){
				hgg[i-sumc].a=hg[i].a;
				hgg[i-sumc].b=hg[i].b;
				hgg[i-sumc].da=hg[i].a-hg[i].b;
			}int m=n-sumc;
			sort(hgg+1,hgg+1+m,cmp1);
			for(int i=1; i<=m; i++){
				if(hgg[i].da>=0)ans+=hgg[i].a;
				else ans+=hgg[i].b;
			}
		}cout<<ans<<'\n';
	}return 0;
}