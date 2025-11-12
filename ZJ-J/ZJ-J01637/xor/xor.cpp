#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],cnt[N];
int ans;


int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	deque <int> q;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		cnt[a[i]]++;
		q.push_back(a[i]);
	}
	if(cnt[1]==n&&k==0) {
		cout<<n/2;
		return 0;
	} else if(cnt[1]+cnt[0]==n&&k>=0&&k<=1) {
		if(k==0) {
			while(!q.empty()) {
				int x=q.front();
				q.pop_front();
				if(!q.empty()) {
					int y=q.front();
					q.pop_front();
					if(x==1&&y==1) ans++;
					if(x==0&&y==1) ans++,q.push_front(1);
					if(x==1&&y==0) ans++;
					if(x==0&&y==0) ans+=2;
				} else {
					if(x==0)ans++;
				}
			}
			cout<<ans;
		}
		if(k==1) cout<<cnt[1];
		return 0;
	} else cout<<n;
	return 0;
}
//神兽保佑，代码无 bug !!!
//6 0
//1 1 0 1 1 0
