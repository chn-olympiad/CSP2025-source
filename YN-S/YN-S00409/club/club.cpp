#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

struct node {
	ll a,b,c;
	ll aa,bb,cc;
};

ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9') {
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}

void solve() {
	ll n=read();
	ll ans1=0,ans2=0,ans3=0,ans4=0,cnt1=0,cnt2=0,cnt3=0;
	bool speA=true;
	bool speB=true;
	vector<node> s(n+1);
	
	for (int i=1;i<=n;i++) {
		s[i].a=read();
		s[i].b=read();
		s[i].c=read();
		s[i].aa=s[i].a-max(s[i].b,s[i].c);
		s[i].bb=s[i].b-max(s[i].a,s[i].c);
		s[i].cc=s[i].c-max(s[i].a,s[i].b);
		if (s[i].b!=0 || s[i].c!=0) speA=false;
		if (s[i].c!=0) speB=false;
	}
	
	if (speA) {
		ll ansA=0;
		sort(s.begin()+1,s.end(),[&](const node&A,const node&B){
			return A.a > B.a;
		});
		for (int i=1;i<=n/2;i++) {
			ansA+=s[i].a;
		}
		cout<<ansA<<endl;
		return ;
	}
	
	sort(s.begin()+1,s.end(),[&](const node&A,const node&B){
		return A.aa>B.aa;
	});
	for (int i=1;i<=n/2;i++) {
		ans1+=s[i].a;
	}
	for (int i=n/2+1;i<=n;i++) {
		ans1+=max(s[i].b,s[i].c);
	}
	
	
	sort(s.begin()+1,s.end(),[&](const node&A,const node&B){
		return A.bb>B.bb;
	});
	for (int i=1;i<=n/2;i++) {
		ans2+=s[i].b;
	}
	for (int i=n/2+1;i<=n;i++) {
		ans2+=max(s[i].a,s[i].c);
	}
	
	
	sort(s.begin()+1,s.end(),[&](const node&A,const node&B){
		return A.cc>B.cc;
	});
	for (int i=1;i<=n/2;i++) {
		ans3+=s[i].c;
	}
	for (int i=n/2+1;i<=n;i++) {
		ans3+=max(s[i].b,s[i].a);
	}
	for (int i=1;i<=n;i++) {
		if ( s[i].a>=max(s[i].b,s[i].c) ) {
			if (cnt1<n/2) {
				ans4+=s[i].a;
				cnt1++;
			}else {
				if (s[i].b>=s[i].c && cnt2<n/2) {
					ans4+=s[i].b;
					cnt2++;
				}else {
					ans4+=s[i].c;
					cnt3++;
				}
			}
		}
		else if ( s[i].b>=max(s[i].a,s[i].c) ) {
			if (cnt2<n/2) {
				ans4+=s[i].b;
				cnt2++;
			}else {
				if (s[i].a>=s[i].c && cnt1<n/2) {
					ans4+=s[i].a;
					cnt1++;
				}else {
					ans4+=s[i].c;
					cnt3++;
				}
			}
		}
		else if ( s[i].c>=max(s[i].a,s[i].b) ) {
			if (cnt3<n/2) {
				ans4+=s[i].c;
				cnt3++;
			}else {
				if (s[i].b>=s[i].a && cnt2<n/2) {
					ans4+=s[i].b;
					cnt2++;
				}else {
					ans4+=s[i].a;
					cnt1++;
				}
			}
		}
	}
	cout<<max({ans1,ans2,ans3,ans4})<<endl;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while (T--) solve();
	return 0;
}