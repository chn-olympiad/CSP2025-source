#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fre(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
int n,t,ans,morea,moreb,morec,x[100010],cnt;
struct node{
	int a,b,c,ma,dj;
}s[100010];
bool cmp(node a,node b){
	return a.ma>b.ma;
}
int main(){
	fre();
	cin>>t;
	while(t--){
		ans=0,cnt=0,morea=0,moreb=0,morec=0;
		cin>>n;
		for(register int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			s[i].ma=max(s[i].a,max(s[i].b,s[i].c));
			s[i].dj=s[i].ma-(s[i].a+s[i].b+s[i].c-s[i].ma-min(s[i].a,min(s[i].b,s[i].c)));
		}
		sort(s+1,s+n+1,cmp);
		for(register int i=1;i<=n;i++){
		//	cout<<i<<" "<<s[i].ma<<" "<<s[i].dj<<endl;
			ans+=s[i].ma;
			if(s[i].a==s[i].ma&&s[i].b!=s[i].ma&&s[i].c!=s[i].ma)morea++;
			if(s[i].b==s[i].ma&&s[i].a!=s[i].ma&&s[i].c!=s[i].ma)moreb++;
			if(s[i].c==s[i].ma&&s[i].b!=s[i].ma&&s[i].a!=s[i].ma)morec++;
		}
		//cout<<ans<<endl<<morea<<" "<<moreb<<" "<<morec<<endl;
		if(morea>n/2){
		//	cout<<"morea"<<endl;
			for(register int i=1;i<=n;i++)
				if(s[i].a==s[i].ma&&s[i].b!=s[i].ma&&s[i].c!=s[i].ma)
					x[++cnt]=s[i].dj;
			sort(x+1,x+cnt+1);
			for(int i=1;i<=morea-n/2;i++)ans-=x[i];
		}
		if(moreb>n/2){
		//	cout<<"moreb"<<endl;
			for(register int i=1;i<=n;i++)
				if(s[i].b==s[i].ma&&s[i].a!=s[i].ma&&s[i].c!=s[i].ma)
					x[++cnt]=s[i].dj;
			sort(x+1,x+cnt+1);
			for(register int i=1;i<=moreb-n/2;i++)ans-=x[i];
		}
		if(morec>n/2){
		//	cout<<"morec"<<endl;
			for(register int i=1;i<=n;i++)
				if(s[i].c==s[i].ma&&s[i].b!=s[i].ma&&s[i].a!=s[i].ma)
					x[++cnt]=s[i].dj;
			sort(x+1,x+cnt+1);
			for(register int i=1;i<=morec-n/2;i++)ans-=x[i];
		}
		cout<<ans<<endl;
	}	
	return 0;
}
