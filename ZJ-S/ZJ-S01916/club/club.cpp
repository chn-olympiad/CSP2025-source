#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long
const int maxn=1<<17;
int Q,n,ans;
struct node {
	int a,b,c;
	int mx() {
		return max(max(a,b),c);
	}
	int mn() {
		return min(max(a,b),c);
	}
	int md() {
		if(c>=a&&a>=b)return a;
		if(b>=a&&a>=c)return a;
		if(a>=b&&b>=c)return b;
		if(c>=b&&b>=a)return b;
		if(b>=c&&c>=a)return c;
		if(a>=c&&c>=b)return c;
		return a;
	}
	bool operator<(node &n2) { //爱憎分明的
		return mx()-md()==n2.mx()-n2.md()?
			   md()-mn()>n2.md()-n2.mn()
			   :mx()-md()>n2.mx()-n2.md();
	}
} a[maxn];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>Q;
	while(Q--) {
		cin>>n;
		ans=0;
		int na=0,nb=0,nc=0;
		for(int i=1; i<=n; i++)
			cin>>a[i].a>>a[i].b>>a[i].c;
		sort(a+1,a+1+n);
		for(int i=1; i<=n; i++) {
			//mx可取
			if(a[i].mx()==a[i].a&&na<n/2)na++,ans+=a[i].a;
			else if(a[i].mx()==a[i].b&&nb<n/2)nb++,ans+=a[i].b;
			else if(a[i].mx()==a[i].c&&nc<n/2)nc++,ans+=a[i].c;
			//md可取
			else if(a[i].md()==a[i].a&&na<n/2)na++,ans+=a[i].a;
			else if(a[i].md()==a[i].b&&nb<n/2)nb++,ans+=a[i].b;
			else if(a[i].md()==a[i].c&&nc<n/2)nc++,ans+=a[i].c;
			//mn可取
			else if(a[i].mn()==a[i].a&&na<n/2)na++,ans+=a[i].a;
			else if(a[i].mn()==a[i].b&&nb<n/2)nb++,ans+=a[i].b;
			else if(a[i].mn()==a[i].c&&nc<n/2)nc++,ans+=a[i].c;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
