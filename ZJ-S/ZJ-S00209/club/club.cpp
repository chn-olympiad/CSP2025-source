#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int cnt[4];
int l[100005];
int tot,num[100005];
int getint(){
	int res=0;
	char ch;
	while (!isdigit(ch))ch=getchar();
	while (isdigit(ch)){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n,ans;
	T=getint();
	while (T--){
		n=getint();
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				a[i][j]=getint();
			}
			if (a[i][1]>a[i][2]){
				if (a[i][1]>a[i][3]){
					cnt[1]++;
					l[i]=1;
					ans+=a[i][1];
				}
				else{
					cnt[3]++;
					l[i]=3;
					ans+=a[i][3];
				}
			}
			else{
				if (a[i][2]>a[i][3]){
					cnt[2]++;
					l[i]=2;
					ans+=a[i][2];
				}
				else{
					cnt[3]++;
					l[i]=3;
					ans+=a[i][3];
				}
			}
			sort(a[i]+1,a[i]+4);
		}
		int type=0;
		if (cnt[1]>n/2)type=1;
		if (cnt[2]>n/2)type=2;
		if (cnt[3]>n/2)type=3;
		if (type==0){
			printf("%d\n",ans);
			continue;
		}
		tot=0;
		for (int i=1;i<=n;i++){
			if (l[i]==type){
				num[++tot]=a[i][3]-a[i][2];
			}
		}
		sort(num+1,num+tot+1);
		int s=cnt[type]-n/2;
		for (int i=1;i<=s;i++)ans-=num[i];
		printf("%d\n",ans);
	}
	return 0;
}
