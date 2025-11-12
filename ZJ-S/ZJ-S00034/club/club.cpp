#include<bits/stdc++.h>
#define int long long
using namespace std;
int aa[100001],bb[100001],cc[100001];
int n,ans=0,ka=0,kb=0,kc=0;
struct hjm{
	int a,b,c,ss,used;
}d[100001];
bool cmp1(int x,int y){
	return d[x].ss>d[y].ss||(d[x].ss>d[y].ss&&(d[x].b>d[x].c&&d[x].b<d[y].b||d[x].b<=d[x].c&&d[x].c<d[y].c));
}
bool cmp2(int x,int y){
	return d[x].ss>d[y].ss||(d[x].ss>d[y].ss&&(d[x].a>d[x].c&&d[x].a<d[y].a||d[x].a<=d[x].c&&d[x].c<d[y].c));
}
bool cmp3(int x,int y){
	return d[x].ss>d[y].ss||(d[x].ss>d[y].ss&&(d[x].b>d[x].a&&d[x].b<d[y].b||d[x].b<=d[x].a&&d[x].a<d[y].a));
}
void solve(){
	ans=0,ka=0,kb=0,kc=0;
	for(int i=1;i<=n;i++){
		int kkk=max(d[i].a,max(d[i].b,d[i].c));
		if(d[i].a==kkk) aa[++ka]=i,d[i].ss=d[i].a-max(d[i].b,d[i].c);
		else if(d[i].b==kkk) bb[++kb]=i,d[i].ss=d[i].b-max(d[i].a,d[i].c);
		else cc[++kc]=i,d[i].ss=d[i].c-max(d[i].a,d[i].b);
	}
	if(ka<=n/2&&kb<=n/2&&kc<=n/2){
		for(int i=1;i<=n;i++)
			ans+=max(d[i].a,max(d[i].b,d[i].c));
	}
	else if(ka>n/2){
		sort(aa+1,aa+ka+1,cmp1);
		for(int i=1;i<=n/2;i++) ans+=d[aa[i]].a;
		for(int i=n/2+1;i<=ka;i++)
			if(d[aa[i]].b>d[aa[i]].c) bb[++kb]=aa[i];
			else cc[++kc]=aa[i];
		for(int i=1;i<=kb;i++) ans+=d[bb[i]].b;
		for(int i=1;i<=kc;i++) ans+=d[cc[i]].c;
	//	cout<<"a";
	}
	else if(kb>n/2){
		sort(bb+1,bb+kb+1,cmp2);
		for(int i=1;i<=n/2;i++) ans+=d[bb[i]].b;
		for(int i=n/2+1;i<=kb;i++)
			if(d[bb[i]].a>d[bb[i]].c) aa[++ka]=bb[i];
			else cc[++kc]=bb[i];
		for(int i=1;i<=ka;i++) ans+=d[aa[i]].a;
		for(int i=1;i<=kc;i++) ans+=d[cc[i]].c;
	//	cout<<"b";
	}
	else{
		sort(cc+1,cc+kc+1,cmp3);
		for(int i=1;i<=n/2;i++) ans+=d[cc[i]].c;
		for(int i=n/2+1;i<=kc;i++)
			if(d[cc[i]].a>d[cc[i]].b) aa[++ka]=cc[i];
			else bb[++kb]=cc[i];
		for(int i=1;i<=ka;i++) ans+=d[aa[i]].a;
		for(int i=1;i<=kb;i++) ans+=d[bb[i]].b;
	//	cout<<"c";
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		scanf("%lld",&n);
	//	int start=clock();
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&d[i].a,&d[i].b,&d[i].c);
		//	cin>>d[i].a>>d[i].b>>d[i].c;
		//	if(d[i].a==d[i].b||d[i].b==d[i].c||d[i].a==d[i].c) cout<<"dsb";
		}
	//	int end=clock();
	//	cout<<end-start<<"\n";
		solve();
	}
	return 0;
}
