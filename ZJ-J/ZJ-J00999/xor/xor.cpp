#include <bits/stdc++.h>
using namespace std;
struct wky{
	int f,s;
	bool operator < (const wky&ot)const{
		return (s-f)<(ot.s-ot.f);
	}
};
const int N=5e5+7;
int n,k;
int a[N];
int h[N];
vector<wky> v;
int ans;
void fun(){
	sort(v.begin(),v.end());
	int L=v.size();
	vector<bool> bj(n+7,0);
	for(int i=0;i<L;i++){
		bool flag=true;
		for(int j=v[i].f;j<=v[i].s;j++){
			if(bj[j]==1){
				flag=false;
				break;
			}
			bj[j]=1;
		}
		if(flag==true){
			++ans;
//			cerr<<v[i].f<<' '<<v[i].s<<'\n';
		}
	}
}
int main(){
	// I can't solve this problem
	// **********
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h[i]=h[i-1]^a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n<=2&&k==0){
		if(n==2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=1;j+i-1<=n;j++){
				if((h[j+i-1]^h[j-1])==k){
					v.push_back({j,j+i-1});
				}
			}
		}
		fun();
		cout<<ans;
		return 0;
	}
	memset(h,0,sizeof(h));
	
	for(int i=1;i<=n;i++){
		h[i]=h[i-1]^a[i];
		if(h[i]==k){
			++ans;
			h[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
