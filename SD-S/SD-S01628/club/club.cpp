#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<deque>
#include<vector>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],flag[N],b[N];
int ans,cnt1,cnt2,cnt3,need,tot;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=cnt1=cnt2=cnt3=need=tot=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]); 
			int maxx=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxx==a[i][3]){
				flag[i]=3;
				cnt3++;
				ans+=a[i][flag[i]];
				continue;
			}
			if(maxx==a[i][2]){
				flag[i]=2;
				cnt2++;
				ans+=a[i][flag[i]];
				continue;
			}
			if(maxx==a[i][1]){
				flag[i]=1;
				cnt1++;
				ans+=a[i][flag[i]];
				continue;
			}
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			printf("%d\n",ans);
		}else{
			if(cnt1>n/2){
				need=cnt1-n/2;
				for(int i=1;i<=n;i++){
					if(flag[i]==1){
						b[++tot]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
					}
				}
			}
			if(cnt2>n/2){
				need=cnt2-n/2;
				for(int i=1;i<=n;i++){
					if(flag[i]==2){
						b[++tot]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
					}
				}
			}
			if(cnt3>n/2){
				need=cnt3-n/2;
				for(int i=1;i<=n;i++){
					if(flag[i]==3){
						b[++tot]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
					}
				}
			}
			sort(b+1,b+1+tot);
			for(int i=1;i<=need;i++){
				ans-=b[i];
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} /*
3
4
4 2 1
3


*/
