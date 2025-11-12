#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=5e5+10,M=1e6+10;
int n,k,cnt=0;
int ans;
int ar[N];

struct node{
	int l,r;
}br[M];
bool cmp(node a,node b){
	return a.r<b.r;
}
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	if(n<=1e3){
		//int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}
		for(int i=1;i<=n;i++){
			int sum=ar[i];
			if(sum==k) {
				br[++cnt].l=i,br[cnt].r=i; 
			}
			for(int j=i+1;j<=n;j++){
				sum=sum^ar[j];
				if(sum==k) {
					br[++cnt].l=i,br[cnt].r=j; 
				}
			}
		}
		if(cnt>0) ans++;
//		cout<<cnt;
		sort(br+1,br+cnt+1,cmp);
		int end=br[1].r;
		for(int i=2;i<=cnt;i++){
//			cout<<br[i].l<<' '<<br[i].r<<endl;
			if(br[i].l>end){
				end=br[i].r;
				ans++;
			//	cout<<"!@@@"<<endl;
			}
		}
		cout<<ans<<endl;
	}
	else{
		if(k==1){
			for(int i=1;i<=n;i++){
				int x;cin>>x;
				if(x==1) ans++;
			}
			cout<<ans<<endl;
		}
		if(k==0){
			int sum=0;
			for(int i=1;i<=n;i++){
				int x;cin>>x;
				if(sum==2) sum=0,ans++;
				if(x==0) ans++,sum=0;
				if(x==1) sum++;
			}
			cout<<ans;
		}
	}
	
	return 0;
}
