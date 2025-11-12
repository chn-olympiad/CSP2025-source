#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,ans[100005],sum;
struct Pe{
	int a;
	int b;
	int c;
}p[100005];
Pe p2[100005];
bool cmpa(Pe a,Pe b){
	return a.a-max(a.b,a.c)<=b.a-max(b.b,b.c);
}
bool cmpb(Pe a,Pe b){
	return a.b-max(a.a,a.c)<=b.b-max(b.a,b.c);
}
bool cmpc(Pe a,Pe b){
	return a.c-max(a.a,a.b)<=b.c-max(b.a,b.b);
}


signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cnta=0,cntb=0,cntc=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].a==max(p[i].a,max(p[i].b,p[i].c))) ans[i]=1,sum+=p[i].a,cnta++;
			else if(p[i].b==max(p[i].a,max(p[i].b,p[i].c))) ans[i]=2,sum+=p[i].b,cntb++;
			else ans[i]=3,sum+=p[i].c,cntc++;
		}
		
		int idxx=1;
		if(cnta>n/2){
			int k=cnta-n/2;
			for(int i=1;i<=n;i++){
				if(ans[i]==1) p2[idxx++]=p[i];
			}
			sort(p2+1,p2+idxx,cmpa);
			for(int i=1;i<=k;i++){
				sum-=p2[i].a;
				sum+=max(p2[i].b,p2[i].c);
			}
		}
		if(cntb>n/2){
			int k=cntb-n/2;
			for(int i=1;i<=n;i++){
				if(ans[i]==2) p2[idxx++]=p[i];
			}
			sort(p2+1,p2+idxx,cmpb);
			for(int i=1;i<=k;i++){
				sum-=p2[i].b;
				sum+=max(p2[i].a,p2[i].c);
			}
		} 
		if(cntc>n/2){
			int k=cntc-n/2;
			for(int i=1;i<=n;i++){
				if(ans[i]==3) p2[idxx++]=p[i];
			}
			sort(p2+1,p2+idxx,cmpc);
			for(int i=1;i<=k;i++){
				sum-=p2[i].c;
				sum+=max(p2[i].a,p2[i].b);
			}
		} 
		cout<<sum<<'\n';
		
		//reset
		for(int i=1;i<=n;i++){
			p[i].a=0,p[i].b=0,p[i].c=0;
			p2[i].a=0,p2[i].b=0,p2[i].c=0;
		}
		sum=0;
	}
	return 0;
}


