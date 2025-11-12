
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0;
	while(ch>'9'||ch<'0')ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}inline void write(int x){
	if(!x)return putchar('0'),void();
	char ch[40];int cnt=0;
	while(x)ch[++cnt]=x%10^48,x/=10;
	while(cnt)putchar(ch[cnt--]);
}
struct side{
	int x,y,z;
}a[2000005];
int c[15];
bool cmp(side a,side b){
	return a.z<b.z;
}
int f[10015],siz[10015];
int find(int x){return (x==f[x])?x:f[x]=find(f[x]);}
inline bool combine(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return 0;
	if(siz[x]>siz[y])swap(x,y);
	f[x]=y;
	siz[y]+=siz[x];
	return 1;
}
inline int lowbit(int x){return x&-x;}
inline int popcnt(int x){
	int cnt=0;
	while(x){
		cnt++;
		x-=lowbit(x);
	}return cnt;
}
bool useless[1000005];
int nxt[1000005];
vector<int>usful;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++){
		a[i].x=read(),a[i].y=read(),a[i].z=read();
	}for(int i=n+1; i<=n+k; i++){
		c[i-n]=read();
		for(int j=1; j<=n; j++){
			++m;
			a[m].x=i,a[m].y=j,a[m].z=read();
		}
	}sort(a+1,a+1+m,cmp);
	long long ans=1000000000000000000;
	for(int i=1; i<=n+k; i++)f[i]=i,siz[i]=1;
	for(int i=1; i<=m; i++){
		int x=a[i].x,y=a[i].y;
		if(x<=n){
			if(combine(x,y)){
				
			}else{
				useless[i]=1;
			}
		}
	}
	nxt[m+1]=m+1;
	for(int i=1; i<=m; i++){
		if(useless[i]){
			nxt[i]=nxt[i+1];
			if(k<=5){
				usful.push_back(i);
			}
		}else{
			nxt[i]=i;
			usful.push_back(i);
		}
	}
	for(int S=0; S<(1<<k); S++){
		for(int i=1; i<=n+k; i++)f[i]=i,siz[i]=1;
		int num=n+popcnt(S),now=0;
		long long res=0;
		int ct=0;
		for(int j=0; j<usful.size(); j++){
			int i=usful[j];
			int x=a[i].x,y=a[i].y;
			if(x<=n||((S>>(x-n-1))&1)){
				if(combine(x,y)){
					res+=a[i].z;
					now++;
					if(now==num-1||res>ans){
//						cerr<<j<<" "<<usful.size()<<endl;
						break;
					}
				}
			}
		}
		for(int i=1; i<=k; i++){
			if((S>>(i-1))&1)res+=c[i]; 
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}

