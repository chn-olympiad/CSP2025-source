#include<bits/stdc++.h>
using namespace std;
const int maxn=(1e4)*2+10;
struct st{
	int m,f;
	int mm,ff;
	int mmm,fff;
}a[maxn];

int c[10];
int cntc[10];

int cmp1(st x,st y){
	return x.m>y.m;
}

int cmp2(st x,st y){
	return x.mm>y.mm;
}

int cmp3(st x,st y){
	return x.mmm>y.mmm;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int cnt=0;
		int ans=0,lim=n>>1;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(cntc,0,sizeof(cntc));
		for(int i=1;i<=n;i++){
			int aa,b,c;
			cin>>aa>>b>>c;
			if(aa>b && aa>c){
				a[i].m=aa;a[i].f=1;
				if(b>c){
					a[i].mm=b;a[i].ff=2;
					a[i].mmm=c;a[i].fff=3;
				}else{
					a[i].mmm=b;a[i].fff=2;
					a[i].mm=c;a[i].ff=3;
				}
			}else if(b>aa && b>c){
				a[i].m=b;a[i].f=2;
				if(aa>c){
					a[i].mm=aa;a[i].ff=1;
					a[i].mmm=c;a[i].fff=3;
				}else{
					a[i].mmm=aa;a[i].fff=1;
					a[i].mm=c;a[i].ff=3;
				}
			}else if(c>b && c>aa){
				a[i].m=c;a[i].f=3;
				if(b>aa){
					a[i].mm=b;a[i].ff=2;
					a[i].mmm=aa;a[i].fff=1;
				}else{
					a[i].mmm=b;a[i].fff=2;
					a[i].mm=aa;a[i].ff=1;
				}
			}
		}
		//aaa
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(a[i].f==1 && cntc[1]<lim){cntc[1]++;c[1]+=a[i].m;cnt++;a[i].mm=-1;a[i].mmm=-1;}
			else if(a[i].f==2 && cntc[2]<lim){cntc[2]++;c[2]+=a[i].m;cnt++;a[i].mm=-1;a[i].mmm=-1;}
			else if(a[i].f==3 && cntc[3]<lim){cntc[3]++;c[3]+=a[i].m;cnt++;a[i].mm=-1;a[i].mmm=-1;}
		}ans=c[1]+c[2]+c[3];
		if(cnt==n){
			cout<<ans<<'\n';
			continue;
		}
		//aaa
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(a[i].mm==-1)continue;
			if(a[i].ff==1 && cntc[1]<lim){cntc[1]++;c[1]+=a[i].mm;cnt++;a[i].mmm=-1;}
			else if(a[i].ff==2 && cntc[2]<lim){cntc[2]++;c[2]+=a[i].mm;cnt++;a[i].mmm=-1;}
			else if(a[i].ff==3 && cntc[3]<lim){cntc[3]++;c[3]+=a[i].mm;cnt++;a[i].mmm=-1;}
		}ans=c[1]+c[2]+c[3];
		if(cnt==n){
			cout<<ans<<'\n';
			continue;
		}
		//aaa
		sort(a+1,a+1+n,cmp3);
		for(int i=1;i<=n;i++){
			if(a[i].mmm==-1)continue;
			if(a[i].fff==1 && cntc[1]<lim){cntc[1]++;c[1]+=a[i].mmm;cnt++;}
			else if(a[i].fff==2 && cntc[2]<lim){cntc[2]++;c[2]+=a[i].mmm;cnt++;}
			else if(a[i].fff==3 && cntc[3]<lim){cntc[3]++;c[3]+=a[i].mmm;cnt++;}
		}ans=c[1]+c[2]+c[3];
		if(cnt==n){
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
