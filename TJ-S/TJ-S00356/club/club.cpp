#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],c[100005];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		long long n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
		}
		long long ans=0;
		if(n==2) {
			long long s[10];
			s[1]=a[1]+b[2];
			s[2]=a[1]+c[2];
			s[3]=b[1]+a[2];
			s[4]=b[1]+c[2];
			s[5]=c[1]+a[2];
			s[6]=c[1]+b[2];
			sort(s+1,s+7,cmp);
			cout<<s[1]<<endl;
		} else {
			sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			sort(c+1,c+n+1,cmp);
			int kg1=1,kg2=1,kg3=1;
			while(n>1) {
				n-=n/2;
				vector<int>v;
				int aa=0,bb=0,cc=0;
				for(int i=1; i<=n; i++) {
					if(kg1==1) {
						aa+=a[i];
					}
					if(kg2==1) {
						bb+=b[i];
					}
					if(kg3==1) {
						cc+=c[i];
					}
				}
				v.push_back(aa);
				v.push_back(bb);
				v.push_back(cc);
				sort(v.begin(),v.end(),cmp);
				ans+=v[0];
				if(v[0]==aa) {
					kg1=0;
				} else if(v[0]==bb) {
					kg2=0;
				} else {
					kg3=0;
				}
				if(n==1) {
					ans+=v[1];
				}
				v.clear();
			}
			cout<<ans<<endl;

		}

	}
	return 0;
}

