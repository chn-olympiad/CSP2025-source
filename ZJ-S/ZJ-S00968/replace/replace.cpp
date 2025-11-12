#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+27;

int n,q;
int a[MAXN][3];
string s1,s2;
bool flag=true;

int main() {
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	cin>>n>>q;

	for(int i=1; i<=n; i++) {
		cin>>s1>>s2;
		int tempa,tempb;
		int len=s1.length();
		for(int i=0; i<len; i++) {
			if(s1[i]!='a'&&s1[i]!='b')
				flag=false;
			if(s1[i]=='b') tempa=i;
		}

		for(int i=0; i<len; i++) {
			if(s2[i]!='a'&&s2[i]!='b')
				flag=false;
			if(s2[i]=='b') tempb=i;
		}

		a[i][0]=tempb-tempa;
		a[i][1]=tempa;
		a[i][2]=len;

	}
	if(flag) {
		while(q--) {
			cin>>s1>>s2;
			long long ans=0;
			int tempa,tempb;
			int len=s1.length();
			for(int i=0; i<len; i++) {
				if(s1[i]!='a'&&s1[i]!='b')
					flag=false;
				if(s1[i]=='b') tempa=i;
			}
			for(int i=0; i<len; i++) {
				if(s2[i]!='a'&&s2[i]!='b')
					flag=false;
				if(s2[i]=='b') tempb=i;
			}

			for(int i=1; i<=n; i++) {
				if(a[i][0]==tempb-tempa&&a[i][1]<=tempa&&len-tempa>=a[i][2]-a[i][1])	
					ans++;
			}
			cout<<ans<<"\n";
		}

	} else {
		while(q--) cout<<0<<"\n";
	}

	return 0;
}