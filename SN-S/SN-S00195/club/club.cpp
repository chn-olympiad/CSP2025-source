#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T,n;
struct node{
	int x,id;
};
node a[maxn],b[maxn],c[maxn];
int ans;
int cnt[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<maxn;i++){
			a[i].x=b[i].x=c[i].x=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>b[i].x>>c[i].x;
			a[i].id=1;
			b[i].id=2;
			c[i].id=3;
			if(a[i].x<b[i].x){
				swap(a[i],b[i]);
			}
			if(b[i].x<c[i].x){
				swap(b[i],c[i]);
			}
			if(a[i].x<b[i].x){
				swap(a[i],b[i]);
			}
		}
		for(int i=1;i<=n;i++){
			if(cnt[a[i].id]+1<=(n/2)){
				cnt[a[i].id]++;
				ans+=a[i].x;
			}else{
				if(cnt[b[i].id]+1<=(n/2)){
					cnt[b[i].id]++;
					ans+=b[i].x;
				}else{
					cnt[c[i].id]++;
					ans+=c[i].x;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
