#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N][4],t,n,ans;
int clubs[N],cnt[4];
int lessa[N],len;

void adjust(int k){
	memset(lessa,0x7f,sizeof(lessa));
	len=0;
	for(int i=1;i<=n;++i){
		if(clubs[i]!=k)continue;
		for(int j=1;j<=3;++j){
			if(j==k)continue;
			lessa[len]=min(lessa[len],a[i][k]-a[i][j]);
		}
		len++;
	}
	sort(lessa,lessa+len);
	for(int i=0;i<cnt[k]-n/2;++i)ans-=lessa[i];
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		memset(clubs,0,sizeof(clubs));
		memset(cnt,0,sizeof(cnt));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			int favour=0,maxn;
			for(int j=1;j<=3;++j){
				scanf("%d",&a[i][j]);
				if(favour==0||a[i][j]>a[i][favour]){
					favour=j;
					maxn=a[i][j];
				}
			}
			ans+=maxn;
			clubs[i]=favour;
			cnt[favour]++;
		}
			
		if(cnt[1]>n/2)adjust(1);
		if(cnt[2]>n/2)adjust(2);
		if(cnt[3]>n/2)adjust(3);
		printf("%d\n",ans);
	}

	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
