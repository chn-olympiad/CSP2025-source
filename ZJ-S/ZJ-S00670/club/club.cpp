#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
int t,n,tot1,tot2,tot3;
ll a[N][4];
struct node{
	int id;
	ll val;
	bool operator<(const node&p) const{
		return val<p.val;
	}
}b1[N],b2[N],b3[N];
vector<int>c;
int read() {
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
//file long long memory
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--) {
		cin>>n;
		long long ans=0;
		for (int i=1;i<=n;i++) {
			a[i][1]=read(),
			a[i][2]=read(),
			a[i][3]=read();
			if (a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
				b1[++tot1]={i,a[i][1]};
				ans+=a[i][1];
			}
			else if (a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
				b2[++tot2]={i,a[i][2]};
				ans+=a[i][2];
			}
			else {
				b3[++tot3]={i,a[i][3]};
				ans+=a[i][3];
			}  
		}
		sort(b1+1,b1+1+tot1);
		sort(b2+1,b2+1+tot2);
		sort(b3+1,b3+1+tot3);
		if (tot1*2>n) {
			for (int i=1;i<=tot1;i++) {
				int u=b1[i].id;
				c.push_back(max(a[u][2],a[u][3])-a[u][1]);
			}
			sort(c.begin(),c.end(),greater<int>());
			for (int i=0;i<tot1-n/2;i++) ans+=c[i];
		}
		if (tot2*2>n) {
			for (int i=1;i<=tot2;i++) {
				int u=b2[i].id;
				c.push_back(max(a[u][1],a[u][3])-a[u][2]);
			}
			sort(c.begin(),c.end(),greater<int>());
			for (int i=0;i<tot2-n/2;i++) ans+=c[i];
		}
		if (tot3*2>n) {
			for (int i=1;i<=tot3;i++) {
				int u=b3[i].id;
				c.push_back(max(a[u][2],a[u][1])-a[u][3]);
			}
			sort(c.begin(),c.end(),greater<int>());
			for (int i=0;i<tot3-n/2;i++) ans+=c[i];
		}
		cout<<ans<<endl;
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		memset(b3,0,sizeof(b3));
		tot1=tot2=tot3=0;
		c.clear();
	}
	return 0;
}
