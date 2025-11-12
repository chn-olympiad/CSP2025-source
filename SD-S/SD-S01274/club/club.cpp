#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
	long long a,b,c;
	long long wa,wb,wc,id;
}a[N];
long long ans,n,vis[N];
bool cmp1(node aaa,node bbb){
	return aaa.wa>bbb.wa;
}
bool cmp2(node aaa,node bbb){
	return aaa.wb>bbb.wb;
}
bool cmp3(node aaa,node bbb){
	return aaa.wc>bbb.wc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) vis[i]=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].id=i;
			a[i].wa=a[i].a-max(a[i].b,a[i].c);
			a[i].wb=a[i].b-max(a[i].a,a[i].c);
			a[i].wc=a[i].c-max(a[i].a,a[i].b);
		} 
		int ca=0,cb=0,cc=0;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(ca<n/2&&a[i].wa>=0&&vis[a[i].id]==0){
				ca++;
				vis[a[i].id]=1; 
				ans+=a[i].a;
			}
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(cb<n/2&&a[i].wb>=0&&vis[a[i].id]==0){
				cb++;
				vis[a[i].id]=1;
				ans+=a[i].b;
			}
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(cc<n/2&&a[i].wc>=0&&vis[a[i].id]==0){
				cc++;
				vis[a[i].id]=1;
				ans+=a[i].c;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[a[i].id]==0){
				if(ca==n/2) ans+=max(a[i].b,a[i].c);
				if(cb==n/2) ans+=max(a[i].a,a[i].c);
				if(cc==n/2) ans+=max(a[i].a,a[i].b);
			}  
		}
		cout<<ans<<endl;
	}
	return 0;
}
