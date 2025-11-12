#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,cnt[3],ans;
struct node{
	int val[3],d,maxid,secid;
}a[N];
bool cmp(node a,node b){
	return a.d>b.d;
}
void doit(){
	memset(cnt,0,sizeof(cnt));
	ans=0;
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++){
		int maxn=0,maxsec=0,maxid=0,secid=0;
		for(int j=0;j<3;j++){
			cin>>a[i].val[j];
			if(a[i].val[j]>=maxn)maxsec=maxn,maxn=a[i].val[j],secid=maxid,maxid=j;
			else if(a[i].val[j]>maxsec)maxsec=a[i].val[j],secid=j;
		}
		a[i].d=maxn-maxsec;
		a[i].maxid=maxid;
		a[i].secid=secid;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(cnt[a[i].maxid]<n/2){
			ans+=a[i].val[a[i].maxid];
			cnt[a[i].maxid]++;
		}
		else ans+=a[i].val[a[i].secid];
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)doit();
	return 0;
}
