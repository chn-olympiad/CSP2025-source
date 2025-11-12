#include <bitset>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#ifdef LOCALDEBUG
#define fex(a, b)
#else
#define fex(a, b) freopen(a, "r", stdin);freopen(b, "w", stdout)
#endif
using namespace std;

long long read() {
	long long res=0, f=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')f=-f;
	while(isdigit(c)) res=res*10+c-'0', c=getchar();
	return res*f;
}

long long n;
long long q;
pair<string, string> a[200005];
string x, y;
bitset<200005> b;

long long search(string s, long long l) {
	string tmp=s;
//	printf("%s %lld\n", s.c_str(), l);
	long long ans=0;
	if(s==y)ans++;
	for(int i = 1; i <= n; i++) {
		if(b[i])continue;
		for(int j = l; j <= (int)(s.size()-a[i].second.size()); j++) {
			if(s[j]!=a[i].first[0])continue;
			if(s.substr(j, a[i].first.size())==a[i].first) {
				b[i]=1;
				ans+=search(s.replace(j, a[i].second.size(), a[i].second), j+a[i].first.size());
				s=tmp;
				b[i]=0;
			}
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	fex("replace.in", "replace.out");
	n=read();q=read();
	for(int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for(int i = 1; i <= q; i++) {
		cin >> x >> y;
		printf("%lld\n", search(x, 0));
	}
	
	return 0;
}
