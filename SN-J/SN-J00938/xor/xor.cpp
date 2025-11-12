#include<bits/stdc++.h>
//#define int long long 
#define O1145 ios::sync_with_stdio(false);
#define O1919 cin.tie(0),cout.tie(0);
#define mid ((l+r)>>1)
using namespace std;
const int N=5e5+5;
int n,k,a[N],v[N];
int nxt[N],q[N];
struct node{
	int val,pos;
} x[N];
bool cmp(node a,node b){
	if(a.val!=b.val)return a.val<b.val;
	return a.pos<b.pos;
}
int o[N],p[N],tot,fr[N];
void init(){
	int now=0;
	for(int i=1;i<=n;i++){
		now^=a[i];v[i]=now;
		x[i].val=now^k,x[i].pos=i;
//		cout<<v[i]<<"  ";
	}
//	cout<<endl;
	sort(x+1,x+n+1,cmp);x[n+1].val=1000000000;
	++tot;o[tot]=1;fr[1]=tot;
	for(int i=1;i<=n;i++)
	{
		fr[i]=tot;
		if(x[i].val!=x[i+1].val){
			p[tot]=i;++tot;o[tot]=i+1;
		}
	}
	--tot;
	
	for(int i=1;i<=n;i++){
		int l=1,r=n;
		while(l<=r){
			if(x[mid].val<=v[i-1])l=mid+1;
			else r=mid-1;
		}
		l--;
		if(x[l].val!=v[i-1]||l==0){nxt[i]=1145140;continue;}
//		cout<<v[i-1]<<" "<<x[l].val<<endl;
		int posss=l;
		l=o[fr[posss]],r=p[fr[posss]];
//		cout<<i<<": "<<posss<<"   "<<fr[posss]<<" "<<l<<" "<<r<<endl;
		while(l<=r){
			if(x[mid].pos<i)l=mid+1;
			else r=mid-1;
		}
		++r;
		if(r>p[fr[posss]]||x[r].pos<i)nxt[i]=1145140;
		else nxt[i]=x[r].pos;
//		cout<<i<<"   "<<nxt[i]<<endl;
	}
}
void check(){
	q[n+1]=1145140;
	for(int i=n;i>=1;i--)q[i]=min(q[i+1],nxt[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		int minn=1145140,pos=1145140;
		for(int j=i;j<=n;j++){
			if(nxt[j]<=q[j+1]){pos=nxt[j];break;}
		}
		if(pos==1145140)break;
		++ans;
		i=pos;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	init();
	check();
	return 0;
}
