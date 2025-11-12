#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,m;
struct Node {
	int a;
	int b;
	int c;
};
Node node[N];
bool cmp(Node x,Node y) {
	if(x.a!=y.a) {
		return x.a>y.a;
	} else {
		return x.b>y.b;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		long long sum=0;
		int m=n/2,cnt1=0,cnt2=0,cnt3=0;
		for(int i=1; i<=n; i++) {
			cin>>node[i].a>>node[i].b>>node[i].c;
			if(node[i].b==0) {
				cnt2++;
			}
			if(node[i].c==0) {
				cnt3++;
			}
		}
		if(cnt2==n&&cnt3==n) {
			int ans=0;
			sort(node+1,node+1+n,cmp);
			for(int i=1; i<=n/2; i++) {
				ans+=node[i].a;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(cnt3==n) {
			sort(node+1,node+1+n,cmp);
			int num1=0,num2=0;
			for(int i=1; i<=n; i++) {
				if(node[i].a>node[i].b) {
					sum+=node[i].a;
					num1++;
				} else {
					sum+=node[i].b;
					num2++;
				}
				if(num1>m) {
					num1--;
					sum-=node[i].a;
					num2++;
					sum+=node[i].b;
				} else if(num2>m) {
					num2--;
					sum-=node[i].b;
					num1++;
					sum+=node[i].a;
				}
			}
			cout<<sum<<"\n";
			continue;
		}
		if(n==2) {
			int x=node[1].a+node[2].b;
			int y=node[1].a+node[2].c;
			int xx=node[1].b+node[2].a;
			int yy=node[1].b+node[2].c;
			int xxx=node[1].c+node[2].a;
			int yyy=node[1].c+node[2].b;
			cout<<max({x,y,xx,yy,xxx,yyy})<<"\n";
			continue;
		} else {
			int tot=0;
			for(int i=1; i<=n; i++) {
				tot+=max({node[i].a,node[i].b,node[i].c});
			}
			cout<<tot<<"\n";
			continue;
		}
	}
	return 0;
}