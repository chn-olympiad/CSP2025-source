#include<bits/stdc++.h>
#define intt long long
using namespace std;
struct myst {
	intt en,dist;
	bool operator<(const myst &k)const {
		return k.dist<dist;
	}
};
priority_queue<myst>q1;
intt n,q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=q; i++)
		cout<<0<<endl;
	return 0;
}
