#include<iostream>
#include<algorithm>
using namespace std;
int n;
//int a[100010],b[100010],c[100010];
//int a1[100010],b1[100010],c1[100010];
struct stst{
	int a,b,c;
}st[100010];
bool cmp1(stst x,stst y){return x.a>y.a;}
bool cmp2(stst x,stst y){return x.b>y.b;}
bool cmp3(stst x,stst y){return x.c>y.c;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long cnt=0;
		int cnta=0,cntb=0,cntc=0,vis[100010]={0};
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>st[i].a>>st[i].b>>st[i].c;
		}
		/*for(int i=1;i<=n;i++){
			if(st[i].a<st[i].b&&st[i].a<st[i].c)st[i].a=0;
			else if(st[i].b<st[i].a&&st[i].b<st[i].c)st[i].b=0;
			else st[i].c=0;
		}*/
		sort(st+1,st+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(/*!vis[i]&&*/cnta<n/2){
				if(st[i].a>st[i].b&&st[i].a>st[i].c)vis[i]=1,cnta++,cnt+=st[i].a;
			}
			else if(st[i].b>st[i].c)vis[i]=1,cntb++,cnt+=st[i].b;
			else vis[i]=1,cntc++,cnt+=st[i].c;
		}
		/*sort(st+1,st+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(!vis[i]&&cntb<n/2){
				if(st[i].b>st[i].a&&st[i].b>st[i].c)vis[i]=1,cntb++,cnt+=st[i].b;
			}
		}
		sort(st+1,st+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(!vis[i]&&cntc<n/2){
				if(st[i].c>st[i].a&&st[i].c>st[i].b)vis[i]=1,cntc++,cnt+=st[i].c;
			}
		}*/
		cout<<cnt<<endl;
	}
		
	return 0;
}