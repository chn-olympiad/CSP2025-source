#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+100;
struct Segment{LL Begin,End;}seg[N];
bool cmp(Segment i,Segment j){return i.End<j.End;}
LL n,k,a[N],sum[N],ans,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
    for(int i=0;i<=n;i++){
		LL t=k^sum[i],j=i+1;
		while(j<=n&&sum[j]!=t) j++;
		if(j!=n+1) cnt++,seg[cnt].Begin=i+1,seg[cnt].End=j;
	}
	sort(seg+1,seg+cnt+1,cmp);
	LL Last=seg[1].End;ans=1;
	for(int i=2;i<=cnt;i++){
		if(Last<seg[i].Begin) ans++,Last=seg[i].End;
	}
	cout<<ans;
	return 0;
}