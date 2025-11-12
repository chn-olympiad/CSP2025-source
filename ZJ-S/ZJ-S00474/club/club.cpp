#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+5;

int n,sum;
int a[N],b[N],c[N],maxn[N],flt1[N],flt2[N],flt3[N],fl[N];
bool cmp1(int x,int y) {
	return a[x]>a[y];
}
bool cmp2(int x,int y) {
	return b[x]>b[y];
}
bool cmp3(int x,int y) {
	return c[x]>c[y];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		sum=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(flt1,0,sizeof(flt1));
		memset(flt2,0,sizeof(flt2));
		memset(flt3,0,sizeof(flt3));
		memset(fl,0,sizeof(fl));
		memset(maxn,0,sizeof(maxn));
		cin >> n;
		int t1=0,t2=0,t3=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i]>>b[i]>>c[i];
			maxn[i]=max(a[i],max(b[i],c[i]));
			if(maxn[i]==a[i])
				fl[1]++,flt1[++t1]=i;
			else if(maxn[i]==b[i])
				fl[2]++,flt2[++t2]=i;
			else
				fl[3]++,flt3[++t3]=i;
			sum+=maxn[i];
		}
		sort(flt1+1,flt1+t+1,cmp1);
		sort(flt2+1,flt2+t+1,cmp2);
		sort(flt3+1,flt3+t+1,cmp3);
		if(fl[1]>n/2) {
			int t=fl[1]-n/2;
			int tu1[n],tu2[n];
			memset(tu1,0,sizeof(tu1));
			memset(tu2,0,sizeof(tu2));
			for(int i=1;i<=t1;i++) {
				tu1[i]=b[flt1[i]];
				tu2[i]=c[flt1[i]];
			}
			int ztu1=1,ztu2=1;
			for(int i=1;i<=t;i++) {
				if(tu1[ztu1]>tu2[ztu2])
					sum-=a[i]-tu1[ztu1],ztu1++;
				else
					sum-=a[i]-tu2[ztu2],ztu2++;
			}
			cout<<sum<<'\n';
		}
		else if(fl[2]>n/2) {
			int t=fl[2]-n/2;
			int tu1[n],tu2[n];
			memset(tu1,0,sizeof(tu1));
			memset(tu2,0,sizeof(tu2));
			for(int i=1;i<=t2;i++) {
				tu1[i]=a[flt2[i]];
				tu2[i]=c[flt2[i]];
			}
			int ztu1=1,ztu2=1;
			for(int i=1;i<=t;i++) {
				if(tu1[ztu1]>tu2[ztu2])
					sum-=b[i]-tu1[ztu1++];
				else
					sum-=b[i]-tu2[ztu2++];
			}
			cout<<sum<<'\n';
		}
		else if(fl[3]>n/2) {
			int t=fl[3]-n/2;
			int tu1[n],tu2[n];
			memset(tu1,0,sizeof(tu1));
			memset(tu2,0,sizeof(tu2));
			for(int i=1;i<=t3;i++) {
				tu1[i]=a[flt3[i]];
				tu2[i]=b[flt3[i]];
			}
			int ztu1=1,ztu2=1;
			for(int i=1;i<=t;i++) {
				if(tu1[ztu1]>tu2[ztu2])
					sum-=c[i]-tu1[ztu1++];
				else
					sum-=c[i]-tu2[ztu2++];
			}
			cout<<sum<<'\n';
		}
		else
			cout<<sum<<'\n';
	}
	return 0;
}
