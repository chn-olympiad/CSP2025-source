#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int ly1,ly2,ly3,ly4;
}e[100010];
bool cmp(node a,node b) {
	return a.ly4>b.ly4;
}
bool cmp1(int a,int b) {
	return a>b;
}
int a[10];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while (T--) {
		int n;
		scanf("%lld",&n);
		for (int i=1;i<=n;i++) {
			scanf("%lld%lld%lld",&e[i].ly1,&e[i].ly2,&e[i].ly3);
			a[1]=e[i].ly1,a[2]=e[i].ly2,a[3]=e[i].ly3;
			sort(a+1,a+1+3,cmp1);
			e[i].ly4=a[1]-a[2];
			//cout<<e[i].ly4<<" ";
		}
		sort(e+1,e+1+n,cmp);
		int ans=0;
		int yu1=0,yu2=0,yu3=0;
		for (int i=1;i<=n;i++) {
			if (yu1*2==n) {
				e[i].ly1=0;
			}
			if (yu2*2==n) {
				e[i].ly2=0;
			}
			if (yu3*2==n) {
				e[i].ly3=0;
			}
			ans+=max(e[i].ly1,max(e[i].ly2,e[i].ly3));
			if (max(e[i].ly1,max(e[i].ly2,e[i].ly3))==e[i].ly1) yu1++;
			if (max(e[i].ly1,max(e[i].ly2,e[i].ly3))==e[i].ly2) yu2++;
			if (max(e[i].ly1,max(e[i].ly2,e[i].ly3))==e[i].ly3) yu3++;
			//cout<<e[i].ly1<<" "<<e[i].ly2<<" "<<e[i].ly3<<endl;
		}
		cout<<ans<<endl;
		//cout<<endl;
		//printf("%lld\n",max(max(ans1,ans2),ans3));
	}
	return 0;
}
