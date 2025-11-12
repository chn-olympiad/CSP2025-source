#include<bits/stdc++.h>
using namespace std;

const int maxn=111111;

struct Asta{
	int data,x;
};

int a[maxn][4];
Asta b[maxn][4];
Asta c[maxn][4];
int na[maxn];
int l[maxn];
int cnt[4];
int minc[4],mnum[4];
int ans=0;

bool cmp(int x,int y){
	return x>y;
}

void fc(int n){
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		na[i]=max(x,max(y,z));
	}
	sort(na+1,na+1+n,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=na[i];
	}
	cout<<ans<<"\n";
}

void work(){
	int n;
	cin>>n;
	if(n>=10){
		fc(n);
		return ;
	}
	for(int i=1;i<=n;i++){
		int ma=0,mi=0x3f3f3f3f;
		int xx,yy;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]>ma){
				ma=a[i][j];
				xx=j;
			}
			if(a[i][j]<mi){
				mi=a[i][j];
				yy=j;
			}
			
		}
		b[i][1].data=ma;
		b[i][1].x=xx;
		b[i][3].data=mi;
		b[i][3].x=yy;
		for(int j=1;j<=3;j++){
			if(j!=xx&&j!=yy){
				b[i][2].data=a[i][j];
				b[i][2].x=j;
			}
		}
		l[i]=b[i][1].data-b[i][2].data;
	}
//	for(int i=1;i<=n;i++)cout<<b[i][1].data<<" "<<b[i][2].data<<" "<<b[i][3].data<<"\n";cout<<"\n";
	for(int i=1;i<=n;i++){
		ans+=b[i][1].data;
		cnt[b[i][1].x]++;
		if(l[i]<minc[b[i][1].x]){
			minc[b[i][1].x]=l[i];
			mnum[b[i][1].x]=i;
		}
		
		if(cnt[b[i][1].x]>n/2){
//			cout<<minc[b[i][1].x]<<" "<<mnum[b[i][1].x]<<"======\n";
			ans-=minc[b[i][1].x];
			cnt[b[i][1].x]--;
			cnt[b[mnum[b[i][1].x]][2].x]++;
			l[mnum[b[i][1].x]]=0x3f3f3f3f;
			minc[b[i][1].x]=0x3f3f3f3f;
			for(int j=1;j<=i;j++){
				if(l[j]<minc[b[j][1].x]){
					minc[b[j][1].x]=l[j];
					mnum[b[j][1].x]=j;
				}
			}
		}
//		cout<<ans<<"---\n";
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(cnt,0,sizeof(cnt));
		memset(minc,0x3f,sizeof(minc));
		memset(mnum,0,sizeof(mnum));
		memset(na,0,sizeof(na));
		ans=0;
		work();
	}
	return 0;
}

