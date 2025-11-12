#include <bits/stdc++.h>
using namespace std;
int n,T;
struct no {
	int l1,r1,l2,r2;
}a[200010];
string t1,t2,s1[200010],s2[200010];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
		long long w;
		w=s1[i].find("b");
		if(w!=string::npos) a[i].l1=w,a[i].r1=s1[i].size()-w-1;
		else a[i].l1=a[i].r1=-1;
		w=s2[i].find("b");
		if(w!=string::npos) a[i].l2=w,a[i].r2=s2[i].size()-w-1;
		else a[i].l2=a[i].r2=-1;
	}
	if(n>1000&&T>1000) {
		while(T--) {
			int ans=0;
			cin>>t1>>t2;
			int l1,r1,l2,r2;
			long long w;
			w=t1.find("b");
			if(w!=string::npos) l1=w,r1=t1.size()-w-1;
			else l1=r1=-1;
			w=t2.find("b");
			if(w!=string::npos) l2=w,r2=t2.size()-w-1;
			else l2=r2=-1;
			for(int i=1;i<=n;i++) {
				if(a[i].l1<=l1&&a[i].r1<=r1) {
					if(l2==(l1-a[i].l1+a[i].l2)) {
						if(r2==(r1-a[i].r1+a[i].r2))
							ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	while(T--) {
		cin>>t1>>t2;
		string h1=t1;
		int l1=t1.size(),l2=t2.size();
		int ans=0;
		for(int i=1;i<=n;i++) {
			t1=h1;
			int l3=s1[i].size(),l4=s2[i].size();
			for(int w=0;w<=l1-l3;w++) {
				if(t1.substr(w,l3)!=s1[i]) continue ;
				string tmp1=t1.substr(0,w);
				string tmp2=t1.substr(w+l3,l1-w-l3);
				string tmp3=tmp1+s2[i]+tmp2;
				if(tmp3==t2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
50 pts
3.05 MiB
*/

