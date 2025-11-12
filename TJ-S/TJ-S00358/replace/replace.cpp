#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n,q;
int ans;
struct Node {
	string si1,si2;
	int len;
};
Node a[N];
bool cmp(string a,string b) {
	return a<b;
}

int tri[N*50][30], cnt;
vector<int> sc[N*30];
int c[N*50];
void trip(string s,int x) {
	int p=0;
	for(int i=0; i<s.size(); i++) {
		int t=s[i]-'a';
		if(!tri[p][t]) {
			tri[p][t]=++cnt;
		}
		p=tri[p][t];
	}
	sc[p].push_back(x);
	c[p]++;
}

void find(string s,int x,int y,string s2,int t1,int t2) {
	int p=0;
	for(int i=x; i<=y; i++) {
		int t=s[i]-'a';
		if(!tri[p][t]) {
			return ;
		}
		p=tri[p][t];
		if(c[p]) {
			for(int T=0;T<sc[p].size();T++){
				int tmp=sc[p][T],f=1;
				int len=a[tmp].len;
				if(len+x<t2) {
					f=0;
					continue;
				}
				for(int j=x; j<=x+len; j++) {
					if(a[tmp].si2[j-x]!=s2[j]) {
						f=0;
						break;
					
					}
				}
				if(f) ans++;
			}
		}
	}
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cin>>n>>q;
	int mx=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i].si1>>a[i].si2;
		int len= a[i].si1.size();
		a[i].len=len-1;
		mx=max(mx,len);
		trip(a[i].si1,i);
	}
	while(q--) {
		string s1,s2;
		cin>>s1>>s2;
		ans=0;
		if(s1.size()!=s2.size()) {
			cout<<0<<endl;
			continue;
		}
		int t1=1e9,t2=0;
		for(int i=0; i<s1.size(); i++) {
			if(s1[i]!=s2[i]) {
				t1=min(t1,i);
				t2=max(t2,i);
			}
		}
		if(t2-t1>mx) {
			cout<<0<<endl;
			continue;
		}
		int s1_len=s1.size();
		for(int i=max(0,t2-mx); i<=t1; i++) {
			find(s1,i,min(s1_len,i+mx),s2,t1,t2);
		}
		cout<<ans<<endl;
	}
	return 0;
}
