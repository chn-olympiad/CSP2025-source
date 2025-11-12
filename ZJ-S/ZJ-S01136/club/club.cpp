#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N],b[N],c[N];
int aa,bb,cc;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	int n;
	long long ans = 0;
	int ai,bi,ci;
	cin>>_;
	while(_--){
		cin>>n;
		ans = 0;
		aa = 0,bb = 0,cc = 0;
		for(int i = 1;i<=n;i++){
			cin>>ai>>bi>>ci;
			ans+=max(ai,max(bi,ci));
			if(ai>=bi&&ai>=ci){
				aa++;
				a[aa] = ai-max(bi,ci);
				continue;
			}
			if(bi>=ai&&bi>=ci){
				bb++;
				b[bb] = bi-max(ai,ci);
				continue;
			}
			if(ci>=ai&&ci>=bi){
				cc++;
				c[cc] = ci-max(bi,ai);
			}
		}
		if(aa>n/2){
			sort(a+1,a+1+aa);
			for(int i = 1;i<=aa-n/2;i++){
				ans-=a[i];
			}
		}
		if(bb>n/2){
			sort(b+1,b+1+bb);
			for(int i = 1;i<=bb-n/2;i++){
				ans-=b[i];
			}
		}
		if(cc>n/2){
			sort(c+1,c+1+cc);
			for(int i = 1;i<=cc-n/2;i++){
				ans-=c[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

