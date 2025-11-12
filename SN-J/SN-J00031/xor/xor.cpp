#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
struct num{
	int v,pos;
};
struct edge{
	int l,r;
}p[maxn];
int n,k,a[maxn];
num s[maxn];
bool cmp1(num aa,num bb){
	if(aa.v!=bb.v) return aa.v<bb.v;
	return aa.pos<bb.pos;
}
bool cmp2(edge aaa,edge bbb){
	if(aaa.r==bbb.r) return aaa.l>bbb.l;
	return aaa.r<bbb.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=true;
		} 
		a[i]^=k;		
	}
	if(!flag){
		cout<<n/2<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		s[i].v=s[i-1].v^a[i];
		s[i].pos=i;
	}
	sort(s+1,s+1+n,cmp1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i].v==s[i-1].v){
			p[++cnt].l=s[i-1].pos+1;
			p[cnt].r=s[i].pos; 
		}
		/*if(s[i].v==0){
			p[++cnt].l=1;
			p[cnt].r=s[i].pos;
		}*/
	}
	sort(p+1,p+1+cnt,cmp2);
	int nr=0,ans=0;
	for(int i=1;i<=cnt;i++){
		if(p[i].l<=nr) continue;
		ans++;
		nr=p[i].r;
	}
	cout<<ans<<endl;
	return 0;
}
