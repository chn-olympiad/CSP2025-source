#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long
int chose[4][100005]= {};
int len[4]= {};
int a[4][100005]= {};
struct Node {
	int x,y,z;	//x表示mid,y表示损失
};
Node b[100005]= {};
int mid(int x,int y,int z) {
	int s[3]= {x,y,z};
	sort(s,s+3);
	return s[1];
}
bool cmp(Node a,Node b) {
	return a.y>b.y;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		memset(chose,0,sizeof chose);
		memset(len,0,sizeof len);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		int n;
		cin>>n;
		for(int i=1; i<=3; i++) {
			len[i]=1;
		}
		for(int i=1; i<=n; i++) {
			int maxx=0;
			int maxwei=0;
			for(int j=1; j<=3; j++) {
				cin>>a[j][i];
				if(a[j][i]>maxx) {
					maxwei=j;
					maxx=a[j][i];
				}
			}
			chose[maxwei][len[maxwei]]=i;
			len[maxwei]++;
		}
		for(int i=1; i<=3; i++) {
			len[i]--;
//			cout<<len[i]<<"";
		}
//		cout<<endl;
		int ans=0;
		for(int i=1; i<=3; i++) {
			if(len[i]>n/2) {
				for(int j=1; j<=len[i]; j++) {
					b[j].x=mid(a[1][chose[i][j]],a[2][chose[i][j]],a[3][chose[i][j]]);
					b[j].y=max(a[1][chose[i][j]],max(a[2][chose[i][j]],a[3][chose[i][j]]))-b[j].x;
					b[j].z=a[i][chose[i][j]];
				}
				sort(b+1,b+len[i]+1,cmp);
				for(int j=len[i]; j>n/2; j--) {
					ans+=b[j].x;
				}
				for(int j=n/2; j>=1; j--) {
					ans+=b[j].z;
				}
			} else {
				for(int j=len[i]; j>=1; j--) {
					ans+=a[i][chose[i][j]];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
