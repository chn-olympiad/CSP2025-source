#include <bits/stdc++.h>
using namespace std;

struct node{
	int val,u;
	friend bool operator< (node a,node b){
		return a.val<b.val;
	}
};
int a[100005][4];
int s[4];
int cnt;
node l[200010];
int used[100005];
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		memset(used,0,sizeof(used));
		memset(l,0,sizeof(l));
		cnt=0;
		
		int n;cin>>n;
		int ans=0;
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int maxx=max(max(a[i][1],a[i][2]),a[i][3]);
			if (maxx==a[i][1]) s[1]++,ans+=a[i][1];
			else if (maxx==a[i][2]) s[2]++,ans+=a[i][2];
			else s[3]++,ans+=a[i][3];
		}
		if (s[1]<=n/2 && s[2]<=n/2 && s[3]<=n/2) {cout<<ans<<endl;continue;}
		int out=max(max(s[1],s[2]),s[3]);
		if (out==s[1]) out=1;
		else if (out==s[2]) out=2;
		else out=3;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				if (j==out) continue;
				if (a[i][out]==max(max(a[i][1],a[i][2]),a[i][3]))
					l[++cnt]=(node){a[i][out]-a[i][j],i};
			}
		}
		sort(l+1,l+cnt+1);
		int changed=0;
		for (int i=1;i<=cnt;i++){
			if (used[l[i].u]) continue;
			ans-=l[i].val;
			used[l[i].u]=1;
			changed++;
			if (changed>=s[out]-n/2) break;
		}
		cout<<ans<<endl;
	}
}
