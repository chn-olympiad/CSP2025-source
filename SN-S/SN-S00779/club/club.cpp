#include <bits/stdc++.h>
using namespace std;
int T,n;
const int MAXN=1e5+5;
struct Node {
	int a,b,c;
	int e;
	int id,x;
};
Node p[MAXN];
int cnt[4],ans=0;
bool cmp(Node x,Node y) {
	if(x.e==y.e) {
		return x.x>y.x;
	}
	return x.e<y.e;
}
void Dealp(void) {
	sort(p+1,p+n+1,cmp);
	int i=1;
	while((cnt[1]<n/2)&&(cnt[2]<n/2)&&(cnt[3]<n/2)&&(cnt[1]+cnt[2]+cnt[3]<n)) {
		ans+=p[i].x;
		cnt[p[i].id]++;
		i++;
	}
	if(i==n+1) {
		return;
	}
	int tmp=i;
	while(i<=n+1) {
		if(cnt[1]==n/2) {
			p[i].e=min(p[i].b,p[i].c);
			if(p[i].b>p[i].c) {
				p[i].id=2;
				p[i].x=p[i].b;
				p[i].e=p[i].c;
			}else{
				p[i].id=3;
				p[i].x=p[i].c;
				p[i].e=p[i].b;
			}
		}
		if(cnt[2]==n/2) {
			p[i].e=min(p[i].a,p[i].c);
			if(p[i].a>p[i].c) {
				p[i].id=1;
				p[i].x=p[i].a;
				p[i].e=p[i].c;
			}else{
				p[i].id=3;
				p[i].x=p[i].c;
				p[i].e=p[i].a;
			}
		}
		if(cnt[3]==n/2) {
			p[i].e=min(p[i].a,p[i].b);
			if(p[i].a>p[i].b) {
				p[i].id=1;
				p[i].x=p[i].a;
				p[i].e=p[i].b;
			}else{
				p[i].id=2;
				p[i].x=p[i].b;
				p[i].e=p[i].a;
			}
		}
		i++;
	}
	sort(p+tmp+1,p+n+1,cmp);
	while(tmp<n+1) {
		ans+=p[tmp].x;
		cnt[p[tmp].id]++;
		tmp++;
	}
}
int main(void) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		ans=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(int i=1;i<=n;i++) {
			cin>>p[i].a>>p[i].b>>p[i].c;
			p[i].e=(p[i].a+p[i].b+p[i].c-max(p[i].a,max(p[i].b,p[i].c)));
			if(p[i].a>=p[i].b&&p[i].a>=p[i].c) p[i].id=1,p[i].x=p[i].a;
			if(p[i].b>=p[i].c&&p[i].b>=p[i].a) p[i].id=2,p[i].x=p[i].b;
			if(p[i].c>=p[i].a&&p[i].c>=p[i].b) p[i].id=3,p[i].x=p[i].c;
		}
		Dealp();
		cout<<ans<<endl;
	}
	
	return 0;
}
