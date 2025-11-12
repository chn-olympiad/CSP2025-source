#include<bits/stdc++.h>
#define int long long
#define lb(x) (x&-x)
using namespace std;
const int N=4e5+5,M=5e6+5,K=1e7+5;
int n,q,cnt,wz1,wz2;
string s[N][2],t[2];
struct node {
	int dlt,l,len,id;
};
vector<node> ve;

int sum[N<<1],lenn,tr[N];

int ans[N];
inline void add(int x) {
	if(x<=0) return;
	for(; x<=(N-5); x+=lb(x)) tr[x]++;
}

inline int query(int x) {
	if(x<=0) return 0;
	int ret=0;
	for(; x; x-=lb(x)) ret+=tr[x];
	return ret;
}
bool cmp(node x,node y) {
	if(x.dlt!=y.dlt) return x.dlt<y.dlt;
	if(x.l!=y.l) return x.l<y.l;
	if(x.len!=y.len) return x.len<y.len;
	return x.id<y.id;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool flag=1;
	for(int i=1; i<=n; i++) {
		cin>>s[i][0]>>s[i][1];
		cnt=0;
		for(int j=0; j<s[i][0].size(); j++) if(s[i][0][j]=='b') cnt++;
		if(cnt!=1) flag=0;
	}
	if(flag) {
		for(int i=1; i<=n; i++) {
			for(int j=0; j<s[i][0].size(); j++) {
				if(s[i][0][j]=='b') wz1=j;
				if(s[i][1][j]=='b') wz2=j;
			}
			int noww=wz1-wz2+M-5;
			ve.push_back({noww,wz1,s[i][0].size(),0});
		}
		for(int i=1; i<=q; i++) {
			cin>>t[0]>>t[1];
			for(int j=0; j<t[0].size(); j++) {
				if(t[0][j]=='b') wz1=j;
				if(t[1][j]=='b') wz2=j;
			}
			int noww=wz1-wz2+M-5;
			ve.push_back({noww,wz1,t[0].size(),i});
		}
		sort(ve.begin(),ve.end(),cmp);
		int lst=0;
		for(int i=1; i<ve.size(); i++) {
			if(ve[i].dlt!=ve[i-1].dlt) {
				if(i-lst>1) {
					sort(sum+1,sum+1+lenn);
					lenn=unique(sum+1,sum+1+lenn)-sum-1;
					for(int j=0; j<=lenn+1; j++) tr[j]=0;
					for(int j=lst; j<i; j++) ve[j].len=lower_bound(sum+1,sum+1+lenn,ve[j].len)-sum;
					for(int j=lst; j<i; j++) {
						if(ve[j].id==0) add(ve[j].len);
						else ans[ve[j].id]=query(ve[j].len);
					}
				}
				lenn=0;
				lst=i;
				sum[++lenn]=ve[i].len;
			} else sum[++lenn]=ve[i].len;
		}
		sort(sum+1,sum+1+lenn);
		lenn=unique(sum+1,sum+1+lenn)-sum-1;
		for(int j=0; j<=lenn+1; j++) tr[j]=0;
		for(int j=lst; j<ve.size(); j++) ve[j].len=lower_bound(sum+1,sum+1+lenn,ve[j].len)-sum;
		for(int j=lst; j<ve.size(); j++) {
			if(ve[j].id==0) add(ve[j].len);
			else ans[ve[j].id]=query(ve[j].len);
		}
		for(int i=1; i<=q; i++) {
			cout<<ans[i]<<"\n";
		}
		return 0;
	}
	while(q--) {
		cin>>t[0]>>t[1];
		int bgg=-1,ed=0;
		for(int i=0; i<t[0].size(); i++) {
			if(bgg==-1&&t[0][i]!=t[1][i]) bgg=i;
			if(t[0][i]!=t[1][i]) ed=i;
		}
		int sum=0;
		for(int i=1; i<=n; i++) {
			int len=s[i][0].size();
			if(len>t[0].size()||len<ed-bgg) continue;
			for(int bg=0; bg<=bgg&&bg+len<=t[0].size(); bg++) {
				if(bg+len-1>=ed&&t[0].substr(bg,len)==s[i][0]&&t[1].substr(bg,len)==s[i][1]) sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
3 2
ab ba
aab baa
baa aab
aaba baaa
ab ba
*/