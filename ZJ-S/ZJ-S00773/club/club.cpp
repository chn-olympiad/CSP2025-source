#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,n,ans;
int a[N][4];
int z[N][4];
int cho[N],num[4];
void solve(int x){
	int mx=max(a[x][1],max(a[x][2],a[x][3]));
	int mn=min(a[x][1],min(a[x][2],a[x][3]));
	for(int i=1;i<=3;i++){
		if(a[x][i]==mx) z[x][1]=i;
		else if(a[x][i]==mn) z[x][3]=i;
		else z[x][2]=i;
	}
	cho[x]=z[x][1],num[z[x][1]]++;
}
void change(){
	for(int p=1;p<=3;p++){
		while(num[p]>n/2){
			int mn=0x3f3f3f3f,ch;
			for(int i=1;i<=n;i++){
				if(cho[i]==p){
					int w=a[i][z[i][1]]-a[i][z[i][2]];
					if(w<mn) mn=w,ch=i;
				}
			}
			cho[ch]=z[ch][2],num[p]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof a);
		memset(z,0,sizeof z);
		memset(cho,0,sizeof cho);
		memset(num,0,sizeof num);
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			solve(i);
		}
		change();
		for(int i=1;i<=n;i++) ans+=a[i][cho[i]];
		printf("%lld\n",ans);
	}
	return 0;
}
