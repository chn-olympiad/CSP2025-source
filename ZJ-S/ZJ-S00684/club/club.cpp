#include<bits/stdc++.h>
using namespace std;
//通用区
int n,a[5][100005],ans;
//暴力区
int path[25][5],cnt[5];
int check() {
	int tool1=(n>>1),tool2=0;
	if(tool1<cnt[1] || tool1<cnt[2] || tool1<cnt[3]) return -1;
	for(int i=1; i<=3; i++) for(int j=1; j<=cnt[i]; j++) tool2+=a[i][path[j][i]];
	return tool2;
}
void dfs(int pos) {
	if(pos>n) {
		ans=max(ans,check());
		return ;
	}
	for(int i=1; i<=3; i++) {
		path[++cnt[i]][i]=pos;
		dfs(pos+1);
		cnt[i]--;
	}
}
//dp
int f[205][105][105];
//特殊性质区
bool Test(char ch) {
	if(ch=='A') for(int i=1; i<=n; i++) if(a[2][i]!=0 || a[3][i]!=0) return false;
	if(ch=='B') for(int i=1; i<=n; i++) if(a[3][i]!=0) return false;
	return true;
}
struct node {
	int val,pos;
	bool operator<(const node &QAQ)const{
		return val>QAQ.val;
	}
}a1[100005],a2[100005],a3[100005];
bool vis[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++) cin>>a[1][i]>>a[2][i]>>a[3][i];
		if(n<=1) dfs(1);
		else if(n<=200) {
			for(int i=1; i<=n; i++) for(int j=0; j<=n/2; j++) for(int k=0; k<=n/2; k++) {
						if(i-j-k>n/2) continue;
						if(j+k<n && i-1>=j+k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[1][i]);
						if(j>0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[2][i]);
						if(k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[3][i]);
					}
			for(int j=0; j<=n/2; j++) for(int k=0; k<=n/2; k++) ans=max(f[n][j][k],ans);
			for(int i=1; i<=n; i++) for(int j=0; j<=n/2; j++) for(int k=0; k<=n/2; k++) f[i][j][k]=0;
		} else if(Test('A')) {
			sort(&a[1][1],&a[1][n+1]);
			for(int i=n; i>n/2; i--) ans+=a[1][i];
		} else if(Test('B')) {
			for(int j=1;j<=n;j++){
				a1[j].val=a[1][j];
				a2[j].val=a[2][j];
				a3[j].val=a[3][j];
				a1[j].pos=a2[j].pos=a3[j].pos=j;
			}
			sort(a1+1,a1+n+1);
			sort(a2+1,a2+n+1);
			sort(a3+1,a3+n+1);
			int cnt1=0,cnt2=0,cnt3=0;
			for(int i=1;i<=n;i++){
				if(a1[cnt[1]].val>a2[cnt[2]].val && a1[cnt[1]].val>a3[cnt3].val){
					cnt[1]++;cnt1++;
					ans+=a1[cnt[1]-1].val;
					vis[a1[cnt[1]-1].pos]=true;
					while(vis[a1[cnt[1]]]) cnt[1]++;
					if(cnt1>=n/2) a1[cnt[1]].val=0;
				}
				if(a2[cnt[2]].val>a1[cnt[1]].val && a2[cnt[2]].val>a3[cnt[3]].val){
					cnt[2]++;cnt2++;
					ans+=a2[cnt[2]-1].val;
					vis[a2[cnt[2]-1].pos]=true;
					while(vis[a1[cnt[2]]]) cnt[2]++;
					if(cnt2>=n/2) a1[cnt[2]].val=0;
				}
				if(a3[cnt[3]].val>a2[cnt[2]].val && a3[cnt[3]].val>a1[cnt[1]].val){
					cnt[3]++;cnt3++;
					ans+=a3[cnt[3]-1].val;
					vis[a3[cnt[3]-1].pos]=true;
					while(vis[a3[cnt[3]]]) cnt[3]++;
					if(cnt3>=n/2) a1[cnt[3]].val=0;
				}
			}
		}
		cout<<ans<<"\n";
		//清理
		ans=0;
	}

	return 0;
}

