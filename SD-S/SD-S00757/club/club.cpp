#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=200+10;
struct node{int x,y,z;}a[N];
int f[N/2][N/2][N/2],n,T,b[N],idx[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0,fl=0;
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i].x>>a[i].y>>a[i].z,fl|=(a[i].z!=0);
		if(!fl){
			memset(b,0,sizeof b);
			for(int i=1;i<=n;i++) b[i]=a[i].y-a[i].x,idx[i]=i;
			sort(idx+1,idx+n+1,[](int a,int b)->bool{return ::b[a]>::b[b];});
			int cnt=0,ans=0;
			for(int id=1;id<=n;id++){
				int i=idx[id];
				if(n-cnt>n/2){
					ans+=a[i].x+b[i],++cnt; 
					continue;
				}
				if(a[i].x+b[i]>a[i].x&&cnt<n/2) ans+=a[i].x+b[i],++cnt;
				else ans+=a[i].x; 
			}
			cout<<ans<<endl;
			continue;
		}
		memset(f,0,sizeof f);
		for(int id=1;id<=n;++id){
			for(int i=n/2;i>=0;--i){
				for(int j=min(n/2,n-i);j>=0;--j){
					for(int k=min(n/2,n-i-j);k>=0;--k){
						if(i!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[id].x);
						if(j!=0) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[id].y);
						if(k!=0) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[id].z);
						if(id==n) ans=max(ans,f[i][j][k]);
					}
				}
			}	
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
/*
一个也不会awa 

*/
