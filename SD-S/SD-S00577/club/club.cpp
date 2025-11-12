#include<bits/stdc++.h>
using namespace std;
int t;
int n,maxa,maxb,maxc,ans,anns;
vector<int>xx[4][4];
int cda,cdb,cdc;
struct node {
	int my,bh;
} a[100005],b[100005],c[100005];
struct nn {
	int aa,bb,cc,maxn,maxh,cd,ch,minn,minh;
	int cha;
} tx[100005];
int jz[100005];
int cnt[4];
//bool cmp(node x,node y) {
//	return x.my>y.my;
//}
bool cmp1(nn x,nn y) {
	return x.cha>y.cha;
}
int ch(){
	int tot=0; 
	for(int i=1;i<=n;i++){
		if(jz[i]==1)tot+=tx[i].aa;
		else if(jz[i]==2)tot+=tx[i].bb;
		else if(jz[i]==3)tot+=tx[i].cc;
	}
	return tot;
} 
void dfs(int x,int z){
	if(cnt[z]>n/2)return;
	if(x==n+1){
//		for(int i=1;i<=n;i++){
//			cout<<jz[i]<<" ";
//		}
		
		ans=max(ans,ch());
		//cout<<"\n"<<ans<<"\n"; 
		return;
	}
	jz[x]=1;
	cnt[1]++;
	dfs(x+1,1);
	cnt[1]--;
	jz[x]=2;
	cnt[2]++;
	dfs(x+1,2);
	cnt[2]--;
	jz[x]=3;
	cnt[3]++;
	dfs(x+1,3);
	cnt[3]--;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(cnt,0,sizeof(cnt));
		//memset(jz,0,sizeof(jz));
		cin>>n;
		ans=0,anns=0;
		
		for(int i=1; i<=n; i++) {
			cin>>a[i].my>>b[i].my>>c[i].my;
			tx[i].aa=a[i].my;
			tx[i].bb=b[i].my;
			tx[i].cc=c[i].my;
			
		}
		if(n<=10){
			dfs(1,1);
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(tx[i].aa>max(tx[i].bb,tx[i].cc)) {
				tx[i].maxn=tx[i].aa;
				xx[1][1].push_back(i);
				tx[i].maxh=1;
				if(tx[i].bb>tx[i].cc) {
					tx[i].cd=tx[i].bb;
					tx[i].ch=2;
					xx[2][2].push_back(i);
					tx[i].minn=tx[i].cc;
					tx[i].minh=3;
					xx[3][3].push_back(i);
				} else {
					tx[i].cd=tx[i].cc;
					xx[3][2].push_back(i);
					tx[i].ch=3;
					tx[i].minn=tx[i].bb;
					tx[i].minh=2;
					xx[2][3].push_back(i);
				}
			} else if(tx[i].bb>tx[i].cc) {
				tx[i].maxn=tx[i].bb;
				tx[i].maxh=2;
				xx[2][1].push_back(i);
				if(tx[i].aa<tx[i].cc) {
					tx[i].minn=tx[i].aa;
					tx[i].minh=1;
					xx[1][3].push_back(i);
					tx[i].cd=tx[i].cc;
					tx[i].ch=3;
					xx[3][2].push_back(i);
				}
				else{
					tx[i].minn=tx[i].cc;
					tx[i].minh=3;
					xx[3][3].push_back(i);
					tx[i].cd=tx[i].aa;
					tx[i].ch=1;
					xx[1][2].push_back(i);
				}
			} else {
				tx[i].maxn=tx[i].cc;
				tx[i].maxh=3;
				xx[3][1].push_back(i);
				if(tx[i].aa<tx[i].bb) {
					tx[i].minn=tx[i].aa;
					tx[i].minh=1;
					xx[1][3].push_back(i);
					tx[i].cd=tx[i].bb;
					tx[i].ch=2;
					xx[2][2].push_back(i);
				}
				else{
					tx[i].minn=tx[i].bb;
					tx[i].minh=2;
					xx[2][3].push_back(i);
					tx[i].cd=tx[i].aa;
					tx[i].ch=1;
					xx[1][2].push_back(i);
				}
			}
//			maxa[1]=max(maxa,a[i].my);
//			maxb[1]=max(maxb,b[i].my);
//			maxc[1]=max(maxc,c[i].my);
			a[i].bh=i;
			b[i].bh=c[i].bh=i;
		}
		for(int i=1;i<=n;i++)tx[i].cha=tx[i].maxn-tx[i].minn;
		sort(tx+1,tx+n+1,cmp1);
		//ans=maxa+maxb+maxc;
//		sort(a+1,a+n+1,cmd);
//		sort(b+1,b+n+1,cmd);
//		sort(c+1,c+n+1,cmd);
		sort(tx+1,tx+n+1,cmp1);
//		for(int i=0;i<xx[1][1].size();i++)maxa=max(maxa,tx[xx[1][1][i]].aa);
//		for(int i=0;i<xx[2][1].size();i++)maxb=max(maxb,tx[xx[2][1][i]].bb);
//		for(int i=0;i<xx[3][1].size();i++)maxc=max(maxc,tx[xx[3][1][i]].cc);
		for(int i=1;i<=n;i++) {
			if(cnt[tx[i].maxh]<n/2) {
				ans+=tx[i].maxn;
				cnt[tx[i].maxh]++;
			} else if(cnt[tx[i].ch]<n/2) {
				ans+=tx[i].cd;
				cnt[tx[i].ch]++;
			} else {
				ans+=tx[i].minn;
				cnt[tx[i].minh]++;
			}
		}
//		anns=ans;
//
//		ans=0;
//		for(int i=n; i>=1; i--) {
//			if(cnt[tx[i].maxh]<n/2) {
//				ans+=tx[i].maxn;
//				cnt[tx[i].maxh]++;
//			} else if(cnt[tx[i].ch]<n/2) {
//				ans+=tx[i].cd;
//				cnt[tx[i].ch]++;
//			} else {
//				ans+=tx[i].minn;
//				cnt[tx[i].minh]++;
//			}
//		}
		cout<<ans<<"\n";
	}
	return 0;
}
