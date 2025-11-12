#include<bits/stdc++.h>
#define pii pair<int,int>
#define fst first 
#define snd second
using namespace std;
typedef long long ll;
ll R(){
	ll f=1,w=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-f;c=getchar();} 
	while(c>='0'&&c<='9'){w=w*10-'0'+c;c=getchar();}
	return w*f;
}
void W(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) W(x/10);
	putchar(x%10+'0');
}
int const N=2e5+10;
int a[N],b[N],c[N],cnt[5],frm[N],d[N];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=R();
	while(T--){
		int n=R(),m=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++) a[i]=R(),b[i]=R(),c[i]=R();
		ll sum=0;
		for(int i=1;i<=n;i++){
			int mx=max(max(a[i],b[i]),c[i]);
			if(a[i]==mx) cnt[1]++,frm[i]=1;
			else if(b[i]==mx) cnt[2]++,frm[i]=2;
			else cnt[3]++,frm[i]=3;
			sum+=mx;
		} 
		if(cnt[2]>n/2){
			for(int i=1;i<=n;i++){
				swap(a[i],b[i]);
				if(frm[i]==1||frm[i]==2) frm[i]=3-frm[i];
			}
			swap(cnt[2],cnt[1]);
		}
		if(cnt[3]>n/2){
			for(int i=1;i<=n;i++){
				swap(a[i],c[i]);
				if(frm[i]==1||frm[i]==3) frm[i]=4-frm[i];
			}
			swap(cnt[3],cnt[1]);
		}
		if(cnt[1]>n/2){
//			cout<<sum<<endl;
			for(int i=1;i<=n;i++){
				if(frm[i]==1){
					d[++m]=max(c[i]-a[i],b[i]-a[i]);
//					printf("i=%d d=%d\n",i,d[i]);
				}
			}
			sort(d+1,d+m+1,cmp);
			int lst=cnt[1]-n/2;
			for(int i=1;i<=lst;i++){
				sum+=d[i];
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
