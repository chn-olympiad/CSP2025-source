#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull base=31;
int n,q;
struct node{
	int l=0,r,len;
	ull hs1,hs2;
}a[200005];
char s1[1000005],s2[1000005],t1[1000005],t2[1000005];
ull pw[1000005],sum[1000005];
ull CUT(int l,int r){
//	cout<<l<<" "<<r<<" "<<sum[r]<<endl;
	return sum[r]-sum[l-1]*pw[r-l+1];
}
void solve(){
	scanf("%s %s",t1+1,t2+1);
	int len=strlen(t1+1);
	if(len!=strlen(t2+1)){
		printf("0\n");
		return;
	}
	int l=0,r=0;
	ull hs1=0,hs2=0;
	for(int i=1;i<=len;i++){
		hs1=hs1*base+(ull)(t1[i]-'a'+1);
		sum[i]=hs1;
		hs2=hs2*base+(ull)(t2[i]-'a'+1);
		if(t1[i]!=t2[i]){
			if(l==0) l=i;
			r=i;
		}
	}
//	cout<<l<<" "<<r<<" "<<hs1<<" "<<hs2<<endl;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i].len>len) continue;
		if((a[i].r-a[i].l+1)!=(r-l+1)) continue;
		if(a[i].l>l||(l-a[i].l+a[i].len)>len) continue;
		ull tmp=CUT(l-a[i].l+1,l-a[i].l+a[i].len);
//		cout<<l-a[i].l+1<<" "<<l-a[i].l+a[i].len<<endl;
		if(tmp!=a[i].hs1) continue;
		ull res=hs1-tmp*pw[len-(l-a[i].l+a[i].len)]+a[i].hs2*pw[len-(l-a[i].l+a[i].len)];
		if(res!=hs2) continue;
		cnt++;
	}
	printf("%d\n",cnt);
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=1000000;i++){
		pw[i]=pw[i-1]*base;
	}
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s %s",s1+1,s2+1);
		int len=strlen(s1+1);
		ull hs1=0,hs2=0;
		for(int j=1;j<=len;j++){
			hs1=hs1*base+(ull)(s1[j]-'a'+1);
			hs2=hs2*base+(ull)(s2[j]-'a'+1);
			if(s1[j]!=s2[j]){
				a[i].r=j;
				if(a[i].l==0) a[i].l=j;
			}
		}
		a[i].hs1=hs1;
		a[i].hs2=hs2;
		a[i].len=len;
//		cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].len<<" "<<a[i].hs1<<" "<<a[i].hs2<<endl;
	}
	for(int i=1;i<=q;i++){
		solve();
	}
	return 0;
}

