#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],f[500005],ans;
set <int> s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	}
	s.insert(0);
	for(int i=1;i<=n;i++) {
		if(s.find(f[i]^k) != s.end()){
			while(!s.empty()){
				s.erase(s.begin());
			}
			s.insert(f[i]);
			ans++;
		}
		else s.insert(f[i]);
	}
	cout<<ans;
	return 0;
}
