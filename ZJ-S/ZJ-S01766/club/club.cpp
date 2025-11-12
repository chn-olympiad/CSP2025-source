#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}
void write(long long x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int t,n,a[100010][4],cnt[4];
long long ans;
vector<int> f[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		cnt[1]=cnt[2]=cnt[3]=0;
		f[1].clear();
		f[2].clear();
		f[3].clear();
		ans=0;
		read(n);
		for(int i=1;i<=n;i++){
			int mx1,mx2;
			for(int j=1;j<=3;j++)
				read(a[i][j]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				mx1=1;
				if(a[i][2]>=a[i][3]) mx2=2;
				else mx2=3;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				mx1=2;
				if(a[i][1]>=a[i][3]) mx2=1;
				else mx2=3;
			}else{
				mx1=3;
				if(a[i][1]>=a[i][2]) mx2=1;
				else mx2=2;
			}
			cnt[mx1]++;
			ans+=a[i][mx1];
			f[mx1].push_back(a[i][mx1]-a[i][mx2]);
			//printf("%d %d\n",mx1,mx2);
		}
		int mx=1;
		for(int i=1;i<=3;i++)
			if(cnt[i]>cnt[mx])
				mx=i;
//		for(int i=1;i<=3;i++){
//			printf("f[%d]: ",i);
//			for(int j=0;j<f[i].size();j++)
//				printf("%d ",f[i][j]);
//			printf("\n");
//		}
		sort(f[mx].begin(),f[mx].end());
		for(int i=0;i<cnt[mx]-n/2;i++)
			ans-=f[mx][i];
		write(ans);
		putchar('\n');
	}
	return 0;
}
