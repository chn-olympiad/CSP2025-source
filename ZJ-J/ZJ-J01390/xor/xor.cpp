#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
struct node{
	int l,r;
}li[N];
int s[N],n,k,cnt;
bool cmp(node a,node b){
	return (a.r==b.r?a.l<b.l:a.r<b.r);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		s[i]=s[i-1]^x;
	}
//	for(int i=1;i<=n;i++){
//		cout<<s[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=s[i-1]^s[j];
//			cout<<i<<" "<<j<<" "<<x<<endl;
			if(x==k){
				cnt++;
				li[cnt].l=i;
				li[cnt].r=j;
			}
		}
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<li[i].l<<" "<<li[i].r<<endl;
//	}
	sort(li+1,li+cnt+1,cmp);
	int l=0,ans=0;
	for(int i=1;i<=cnt;i++){
		if(li[i].l>l){
			ans++;
			l=li[i].r;
		}
	}
	cout<<ans;
	return 0;
}
