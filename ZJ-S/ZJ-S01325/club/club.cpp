#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[3];
long long a[100005][3];
long long g[3][100005];
long long getint(){
	char ch=getchar();
	long long res=0;
	while(!(ch>='0'&&ch<='9')) ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	return res;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		cnt[0]=cnt[1]=cnt[2]=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			a[i][0]=getint();
			a[i][1]=getint();
			a[i][2]=getint();
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				ans+=a[i][0];
				cnt[0]++;
				g[0][cnt[0]]=a[i][0]-max(a[i][1],a[i][2]);
			}
			else{
				if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
					ans+=a[i][1];
					cnt[1]++;
					g[1][cnt[1]]=a[i][1]-max(a[i][0],a[i][2]);
				}
				else{
					ans+=a[i][2];
					cnt[2]++;
					g[2][cnt[2]]=a[i][2]-max(a[i][0],a[i][1]);
				}
			}
		}
		int cg=-1;
		for(int i=0;i<3;i++){
			if(cnt[i]>n/2){
				cg=i;
				break;
			}
		}
		if(cg!=-1){
			sort(g[cg]+1,g[cg]+cnt[cg]+1);
			for(int i=1;i<=cnt[cg]-n/2;i++){
				ans-=g[cg][i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
