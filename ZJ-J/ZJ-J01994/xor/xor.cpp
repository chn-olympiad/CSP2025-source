#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x0 XA_0
#define y0 YA_0
#define x1 XA_1
#define y1 YA_1
int n,k,ans,cnt1,maxx=-1;
bool f=1;
const int N=5e5+10;
int a[N];
bool vis[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
		maxx=max(maxx,a[i]);
		cnt1+=(a[i]==1);
	}
	if(f){
		if(n%2==1){
			cout<<1;
		}else{
			cout<<n/2;
		}
	}else if(maxx<=1){
		cout<<cnt1;
	}else{
		int x=a[1];
		for(int i=1;i<=n;i++){		
//			x=work(x,a[i]);
			int t=a[i];
			if(t==k){
				ans++;
				vis[i]=1;
				continue;
			}
			for(int j=i-1;j>=1;j--){
				if(vis[j]==1){
					break;
				}else{
					if(t==k){
						ans++;
//						cout<<i<<endl;
						vis[i]=1;
						break;
					}else{
						t^=a[j];
						if(t==k){
							ans++;
//							cout<<i<<endl;
							vis[i]=1;
							break;
						}
//						cout<<i<<' '<<t<<endl;
					}
				}
			}
		}
//		if(x==k)ans++;
		cout<<ans;
	}
	return 0;
}

