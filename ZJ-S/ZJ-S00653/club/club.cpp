#include <bits/stdc++.h>
using namespace std;
int v1[100010],v2[100010],v3[100010];
int n,T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		int cnt1=0,cnt2=0,cnt3=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(x>=y&&x>=z){
				sum+=x;
				v1[++cnt1]=x-max(y,z);
			}else if(y>=z&&y>=x){
				sum+=y;
				v2[++cnt2]=y-max(x,z);
			}else{
				sum+=z;
				v3[++cnt3]=z-max(x,y);
			}
		}
		if(cnt1>n/2){
			sort(v1+1,v1+cnt1+1);
			int tmp=cnt1-n/2;
			long long s=0;
			for(int i=1;i<=tmp;i++) s+=v1[i];
			printf("%lld\n",sum-s);
		}else if(cnt2>n/2){
			sort(v2+1,v2+cnt2+1);
			int tmp=cnt2-n/2;
			long long s=0;
			for(int i=1;i<=tmp;i++) s+=v2[i];
			printf("%lld\n",sum-s);
		}else if(cnt3>n/2){
			sort(v3+1,v3+cnt3+1);
			int tmp=cnt3-n/2;
			long long s=0;
			for(int i=1;i<=tmp;i++) s+=v3[i];
			printf("%lld\n",sum-s);
		}else{
			printf("%lld\n",sum);
		}
	}
	return 0;
}
