#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,T;
struct PeO{
	int a,b,c;
}peo[101000];
bool cmpa(PeO x,PeO y){
	return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);
}bool cmpb(PeO x,PeO y){
	return x.b-max(x.a,x.c)>y.b-max(y.a,y.c);
}bool cmpc(PeO x,PeO y){
	return x.c-max(x.b,x.a)>y.c-max(y.b,y.a);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//system("fc club.out club5.ans");
	//cin>>T;
	scanf("%d",&T);
	while(T--){
		//cin>>n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			//cin>>peo[i].a>>peo[i].b>>peo[i].c;
			scanf("%d %d %d",&peo[i].a,&peo[i].b,&peo[i].c);
		}
		sort(peo+1,peo+n+1,cmpa);
		int ans=0,sum=0;
		for(int i=1;i<=n/2;i++){
			sum+=peo[i].a;
		}for(int i=n/2+1;i<=n;i++){
			sum+=max(peo[i].b,peo[i].c);
		}
		ans=max(ans,sum);
		///////////////
		sort(peo+1,peo+1+n,cmpb);
		sum=0;
		for(int i=1;i<=n/2;i++){
			sum+=peo[i].b;
		}for(int i=n/2+1;i<=n;i++){
			sum+=max(peo[i].a,peo[i].c);
		}
		ans=max(ans,sum);
		///////////////
		sort(peo+1,peo+1+n,cmpc);
		sum=0;
		for(int i=1;i<=n/2;i++){
			sum+=peo[i].c;
		}for(int i=n/2+1;i<=n;i++){
			sum+=max(peo[i].b,peo[i].a);
		}
		ans=max(ans,sum);
		////////////////
		int cnta=0,cntb=0,cntc=0;
		sum=0;
		for(int i=1;i<=n;i++){
			if(peo[i].a>peo[i].b&&peo[i].a>peo[i].c) cnta++;
			else if(peo[i].b>peo[i].a&&peo[i].b>peo[i].c) cntb++;
			else if(peo[i].c>peo[i].a&&peo[i].c>peo[i].b) cntc++;
		}
		if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2){
			for(int i=1;i<=n;i++){
				sum+=max(max(peo[i].a,peo[i].b),peo[i].c);
			}
			ans=max(ans,sum);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
