#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=100010;
struct node{
	int x,y,z,mn,mx;
	bool operator<(const node b){
		if(mn!=b.mn)return mn>b.mn;
		return mx>b.mx;
	}
}a[N];
signed main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,cnt1=0,cnt2=0,cnt3=0,res=0;cin>>n;
		for(int i=1;i<=n;i++){
			a[i].mn=1e18;
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].mx=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x!=a[i].mx)a[i].mn=min(a[i].mn,abs(a[i].mx-a[i].x));
			if(a[i].y!=a[i].mx)a[i].mn=min(a[i].mn,abs(a[i].mx-a[i].y));
			if(a[i].z!=a[i].mx)a[i].mn=min(a[i].mn,abs(a[i].mx-a[i].z));
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i].x==a[i].mx){
				if(cnt1!=n/2)cnt1++,res+=a[i].x;
				else if(a[i].y>=a[i].z) cnt2++,res+=a[i].y;
				else  cnt3++,res+=a[i].z;
			}else if(a[i].y==a[i].mx){
				if(cnt2!=n/2)cnt2++,res+=a[i].y;
				else if(a[i].x>=a[i].z) cnt1++,res+=a[i].x;
				else  cnt3++,res+=a[i].z;
			}else{
				if(cnt3!=n/2)cnt3++,res+=a[i].z;
				else if(a[i].y>=a[i].x) cnt2++,res+=a[i].y;
				else  cnt1++,res+=a[i].x;
			}
			
		}
		cout<<res<<endl;
	}
	return 0;
} 
