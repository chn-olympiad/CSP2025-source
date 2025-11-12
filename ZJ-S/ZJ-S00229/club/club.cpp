#include<bits/stdc++.h>
#define balaX balax
#define balaY balay
#define balaZ balaz
using namespace std;

inline int read(){
	int s=0;char c=getchar();bool f=0;
	while(c<'0'||c>'9'){f=(f||(c=='-'));c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<1)+(s<<3)+(c^48);c=getchar();}
	if(f) s=-s;
	return s;
}


int n;
struct node{
	int id,x,t;
}a[300005],bu[100005];
bool vis[100005];
int num[15];
bool cmp(node a,node b){
	if(a.t==10&&b.t==5) return false;
	if(b.t==10&&a.t==5) return true;
	if(a.x==b.x) return a.id<b.id;
	return a.x>b.x;
}
int m=0;
int ans=0;
int balaX[100005];
int balaY[100005];
int balaZ[100005];
int www[100005];
priority_queue<int,vector<int>,greater<int> >qx;
priority_queue<int,vector<int>,greater<int> >qy;
priority_queue<int,vector<int>,greater<int> >qz;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		int nn=n/2;
		m=0;
		ans=0;
		int sumx=0,sumy=0,sumz=0;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			int x,y,z;
			x=read();y=read();z=read();
			int pl=min(x,min(y,z));
			ans+=pl;
			x-=pl,y-=pl,z-=pl;
			a[++m]={i,x,1};
			a[++m]={i,y,2};
			a[++m]={i,z,3};
			balaX[i]=x;balaY[i]=y;balaZ[i]=z;
			sumx+=x,sumy+=y,sumz+=z;
		}
		int cnt=0;
		while(qx.size()) qx.pop();
		while(qy.size()) qy.pop();
		while(qz.size()) qz.pop();
		sort(a+1,a+m+1,cmp);
		int X=0,Y=0,Z=0;
		for(int i=1;i<=m;i++){
			if(vis[a[i].id]) continue;
//			cout<<a[i].id<<' '<<a[i].t<<' '<<a[i].x<<endl;
			if(i<=n-2&&a[i].id==a[i+1].id&&a[i].id==a[i+2].id&&a[i].x==a[i+2].x){
				bu[++cnt]={a[i].id,a[i].x,10};
				continue;
			}
			else if(i<=n-1&&a[i].id==a[i+1].id&&a[i+1].x==a[i].x){
				bu[++cnt]={a[i].id,a[i].x,5};
				vis[a[i].id]=1;
				continue;
			}
			else{
				if(a[i].t==1&&X<nn) X++,qx.push(a[i].x);
				else if(a[i].t==2&&Y<nn) Y++,qy.push(a[i].x);
				else if(a[i].t==3&&Z<nn) Z++,qz.push(a[i].x);
				else continue;
				ans+=a[i].x;
			}
			vis[a[i].id]=1;
		}
		sort(bu+1,bu+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			if(bu[i].t==10){
				int v=bu[i].x;
				if(X<nn) X++,ans+=v;
				else if(Y<nn) Y++,ans+=v;
				else if(Z<nn) Z++,ans+=v;
				else{
					if(qx.top()<qy.top()&&qx.top()<qz.top()){
						ans=ans-qx.top()+v;
						qx.pop();
						qx.push(v);
					}
					else if(qy.top()<qz.top()){
						ans=ans-qy.top()+v;
						qy.pop();
						qy.push(v);
					
					}
					else{
						ans=ans-qz.top()+v;
						qz.pop();
						qz.push(v);
					
					}
				}
			}
			else{
				if(balaX[bu[i].id]==balaY[bu[i].id]){
					int v=bu[i].x;
					if(X<nn) X++,ans+=v;
					else if(Y<nn) Y++,ans+=v;
					else{
						int changeZ=0;
						if(Z<nn) changeZ=balaZ[bu[i].id];
						else changeZ=balaZ[bu[i].id]-qz.top();
						if(changeZ>=max(-qx.top()+v,-qy.top()+v)){
							if(Z<nn)
							Z++;
							else{
								qz.pop();
								qz.push(balaZ[bu[i].id]);
							}ans+=changeZ;
							
						}
						else if(qx.top()<qy.top()){
							ans=ans-qx.top()+v;
							qx.pop();
							qx.push(v);
						}
						else{
							ans=ans-qy.top()+v;
							qy.pop();
							qy.push(v);
						
						}
					}
				}
				else if(balax[bu[i].id]==balaz[bu[i].id]){
					int v=bu[i].x;
					if(X<nn) X++,ans+=v;
					else if(Z<nn) Z++,ans+=v;
					else{
						int changeZ=0;
						if(Y<nn) changeZ=balaY[bu[i].id];
						else changeZ=balaY[bu[i].id]-qy.top();
						if(changeZ>=max(-qx.top()+v,-qz.top()+v)){
							if(Y<nn)
							Y++;
							else{
								qy.pop();
								qy.push(balaY[bu[i].id]);
							}ans+=changeZ;
							
						}
						else if(qx.top()<qz.top()){
							ans=ans-qx.top()+v;
							qx.pop();
							qx.push(v);
						}
						else{
							ans=ans-qz.top()+v;
							qz.pop();
							qz.push(v);
						
						}
					}
				}
				else{
					int v=bu[i].x;
					if(Y<nn) Y++,ans+=v;
					else if(Z<nn) Z++,ans+=v;
					else{
						int changeZ=0;
						if(X<nn) changeZ=balaX[bu[i].id];
						else changeZ=balaX[bu[i].id]-qx.top();
						if(changeZ>=max(-qy.top()+v,-qz.top()+v)){
							if(X<nn)
							X++;
							else{
								qx.pop();
								qx.push(balaX[bu[i].id]);
							}ans+=changeZ;
							
						}
						else if(qy.top()<qz.top()){
							ans=ans-qy.top()+v;
							qy.pop();
							qy.push(v);
						}
						else{
							ans=ans-qz.top()+v;
							qz.pop();
							qz.push(v);
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
