#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long t,n;
struct PP{
	long long a,b,c,id;
	long long maxabc;
}p[N],p1[N];
bool vis[N];
bool cmp(PP x,PP y){
	if(x.maxabc!=y.maxabc)return x.maxabc>y.maxabc;
	else return x.id>y.id;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			long long tempx=0,tempy=0,tempz=0;
			cin>>tempx>>tempy>>tempz;
			long long midtemp=0;
			if((tempx>=tempy&&tempy>=tempz)||(tempz>=tempy&&tempy>=tempx)){
				midtemp=tempy;
			}else if((tempz>=tempx&&tempx>=tempy)||(tempy>=tempx&&tempx>=tempz)){
				midtemp=tempx;
			}else if((tempx>=tempz&&tempz>=tempy)||(tempy>=tempz&&tempz>=tempx)){
				midtemp=tempz;
			}
			ans+=midtemp;
			tempx-=midtemp;tempy-=midtemp;tempz-=midtemp;
			p[i].a=tempx;p[i].b=tempy;p[i].c=tempz;
			p[i].maxabc=max({tempx,tempy,tempz});p[i].id=i;
			//cout<<p[i].a<<p[i].b<<p[i].c<<endl;
		}
		sort(p+1,p+1+n,cmp);
		long long cnta=0,cntb=0,cntc=0; 
		for(int i=1;i<=n;i++){
			if(cnta>=n/2||cntb>=n/2||cntc>=n/2)break;
			ans+=p[i].maxabc;
			vis[i]=true;
			if(p[i].a==p[i].maxabc){
				cnta++;
			}else if(p[i].b==p[i].maxabc){
				cntb++;
			}else if(p[i].c==p[i].maxabc){
				cntc++;
			}
		}
		if(cnta!=n/2&&cntb!=n/2&&cntc!=n/2){
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			
			long long tempx=0,tempy=0;
			if(cnta==n/2){
				tempx=p[i].b,tempy=p[i].c;
			}else if(cntb==n/2){
				tempx=p[i].a,tempy=p[i].c;
			}else if(cntc==n/2){
				tempx=p[i].a,tempy=p[i].b;
			}
			long long mintemp=min(tempx,tempy);
			ans+=mintemp;
			tempx-=mintemp;tempy-=mintemp;
			p1[i].a=tempx;p1[i].b=tempy;
			p1[i].maxabc=max(tempx,tempy);p1[i].id=i;
		}
		sort(p1+1,p1+1+n,cmp);
		for(int i=1;i<=n;i++){
			ans+=p1[i].maxabc;
			vis[i]=true;
		}
		cout<<ans<<endl;
		for(int i=0;i<=n;i++){
			vis[i]=0;
			p1[i].a=0;p1[i].b=0;p1[i].c=0;p1[i].id=0;p1[i].maxabc=0;
			p[i].a=0;p[i].b=0;p[i].c=0;p[i].id=0;p[i].maxabc=0;
			ans=0;cnta=0;cntb=0;cntc=0;
		}
		n=0;
	}
	return 0;
}

