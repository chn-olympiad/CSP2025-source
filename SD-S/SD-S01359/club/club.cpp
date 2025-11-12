#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int biaom[300003],wei[300001],on=1;
ll baon[4],zu,n;
ll a[300003];
bool zhuang[4],biaon[300003];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&zu);
	for(int p=1;p<=zu;p++){
		ll zou=0;
		scanf("%lld",&n);
		ll zui=n/1;
		for(int i=1;i<=3*n;i++){
			ll a1,a2,a3;
			scanf("%lld%lld%lld",&a1,&a2,&a3);
			a[i]=a1,biaom[i]=on,wei[i]=1;
			a[i+1]=a2,biaom[i+1]=on,wei[i+1]=2;
			a[i+2]=a3,biaom[i+2]=on,wei[i+2]=3;
			on++;
			i=i+2; 
		}
		for(int i=1;i<=3*n;i++){
			for(int o=1;o<=3*n;o++){
				if(a[i]>a[o]){
					swap(a[i],a[o]);
					swap(biaom[i],biaom[o]);
					swap(wei[i],wei[o]);
				}
			}
		}
		for(int i=300003;i>=1;i--){
			if(a[i]==0){
				continue;
			}
			int biao=biaom[i];
			int bu=wei[i];
			if(zhuang[bu]||biaon[biao]){
				continue;
			}
			else{
				zou+=a[i];
				baon[bu]++;
				biaon[i]=true;
				if(baon[bu]==zui){
					zhuang[bu]=true;
				}
			}
		}
		printf("%lld\n",zou);
	}
	return 0;
}
