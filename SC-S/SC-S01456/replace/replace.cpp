#include<bits/stdc++.h>
using namespace std;

int n,q;
long long ans;

string t,tt,r,rr;

struct bbb{
	string s,ss;
	int len;
}a[200500];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for( int i=1; i<=n; ++i ){
		cin>>a[i].s>>a[i].ss;
		a[i].len=a[i].s.size();
	}
	while( q-- ){
		cin>>t>>tt;
		if( t.size()!=tt.size() ){
			cout<<"0\n";
			continue;
		}
		ans=0;
		int lt=t.size();
		for( int i=1; i<=n; ++i ){
			for( int j=0; j<=lt-a[i].len; ++j ){
				for( int k=0; k<=a[i].len; ++k ){
					if( k==a[i].len ){
						++ans;
						break;
					}
					if( t[j+k]!=a[i].s[k] or tt[j+k]!=a[i].ss[k] ){
						break;
					}
				}
			} 
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
lingan鼓励鼓励鼓励哇擦 ~
lingan菇 ~ lingan菇 ~ 
lingan鼓励鼓励鼓励哇擦 ~
lingan菇 ~ lingan菇 ~
*/