#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,cnt1,cnt2,cnt3,v[100005],len1,len2,len3,cnt;
struct aaaa{
	int a,i;
}a[100005],b[100005],c[100005];
struct aaa{
	int a,i1,ma,mi,i2;	
}d[100005];
bool cmp(aaaa a,aaaa b){
	return a.a>b.a;
}
bool cmp1(aaa a,aaa b){
	return a.a>b.a;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		len1=0;
		len2=0;
		len3=0;
		ans=0;
		cnt1=1;
		cnt2=1;
		cnt3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>b[i].a>>c[i].a;
			cnt=min(a[i].a,min(b[i].a,c[i].a));
			ans+=cnt;
			a[i].i=i;
			b[i].i=i;
			c[i].i=i;
			a[i].a-=cnt;
			b[i].a-=cnt;
			c[i].a-=cnt;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++){
			d[i].a=max(a[i].a,max(b[i].a,c[i].a))-min(a[i].a==0?1e9:a[i].a,min(b[i].a==0?1e9:b[i].a,c[i].a==0?1e9:c[i].a)),d[i].ma=max(a[i].a,max(b[i].a,c[i].a)),d[i].mi=min(a[i].a==0?1e9:a[i].a,min(b[i].a==0?1e9:b[i].a,c[i].a==0?1e9:c[i].a));
			if(d[i].ma==a[i].a)d[i].i1=a[i].i;
			if(d[i].ma==b[i].a)d[i].i1=b[i].i;
			if(d[i].ma==c[i].a)d[i].i1=c[i].i;
			if(d[i].mi==a[i].a)d[i].i2=a[i].i;
			if(d[i].mi==b[i].a)d[i].i2=b[i].i;
			if(d[i].mi==c[i].a)d[i].i2=c[i].i;
		}
		sort(d+1,d+1+n,cmp1);
		for(int i=1;i<=n;i++)v[i]=0;
		for(int i=1;i<=n;i++){
			while(v[a[cnt1].i]==1&&cnt1<=n)cnt1++;
			while(v[b[cnt2].i]==1&&cnt2<=n)cnt2++;
			while(v[c[cnt3].i]==1&&cnt3<=n)cnt3++;
			if(len1==n/2)
				a[cnt1].a=0;
			if(len2==n/2)
				b[cnt2].a=0;
			if(len3==n/2)
				c[cnt3].a=0;
			int cnt=max(a[cnt1].a,max(b[cnt2].a,c[cnt3].a));
			ans+=cnt;
			if(cnt==a[cnt1].a)
				len1++,v[a[cnt1].i]=1;
			else if(cnt==b[cnt2].a)
				len2++,v[b[cnt2].i]=1;
			else if(cnt==c[cnt3].a)
				len3++,v[c[cnt3].i]=1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1  
10 
5491 4476 6362 
9805 9130 15480 
9090 9901 10480 
6326 6516 1985 
9119 2924 6420 
9826 12689 7592 
7293 16544 12901  
11905 18183 18712 
9015 3463 13025 
1792 2433 17042 
*/ 