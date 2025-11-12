#include<bits/stdc++.h>
using namespace std;
struct a {
	int v1,v2,v3;
	int vm;
} s[100005];
int t,n,r[4][10005];
long long d[4],cnt=0;
bool cmp(a e,a f) {
	if(e.vm!=f.vm) {
		return e.vm>f.vm;
	} else if(e.v1!=f.v1) {
		return e.v1>f.v1;
	} else if(e.v2!=f.v2) {
		return e.v2>f.v2;
	} else if(e.v3!=f.v3) {
		return e.v3>f.v3;
	} else return true;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		if(n==2) {
			int b=-1;
			for(int i=1; i<=n; ++i) {
				cin>>r[1][i]>>r[2][i]>>r[3][i];
			}
			for(int i=1; i<=3; ++i) {
				for(int j=1; j<=3; ++j) {
					if(i==j) continue;
					b=max(b,r[i][1]+r[j][2]);
				}

			}
			cout<<b;
		} else {
			cnt=0;
			int y=n/2;
			d[1]=0;
			d[2]=0;
			d[3]=0;
			for(int i=1; i<=n; ++i) {
				cin>>s[i].v1>>s[i].v2>>s[i].v3;
				s[i].vm=max(max(s[i].v1,s[i].v3),s[i].v2);
			}
			//cout<<c[1]<<' '<<c[2]<<' '<<c[3];
			//cout<<endl;
			sort(s+1,s+1+n,cmp);
			//	for(int i=1; i<=n; ++i) {
			//		cout<<s[i].v1<<' '<<s[i].v2<<' '<<s[i].v3<<endl;
			//	}
			for(int i=1; i<=n; ++i) {
				if(s[i].v1==s[i].vm&&d[1]+1<=y) {
					cnt+=s[i].v1;
					d[1]++;
					//	cout<<'s'<<i<<' '<<1<<' ';
				} else if(s[i].v2==s[i].vm&&d[2]+1<=y) {
					cnt+=s[i].v2;
					d[2]++;
					//	cout<<'s'<<i<<' '<<2<<' ';
				} else if(s[i].v3==s[i].vm&&d[3]+1<=y) {
					cnt+=s[i].v3;
					d[3]++;
					//	cout<<'s'<<i<<' '<<3<<' ';
				}
			}
			//	cout<<n*1.0/2;
			cout<<cnt<<'\n';
			//cout<<d[3];
		}
	}
	return 0;
}