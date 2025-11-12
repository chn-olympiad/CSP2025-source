#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,M=2e4+5;
int T,n;
int a1[N],a2[N],a3[N];
bool vis1[N],vis2[N],vis3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int sum1=0,sum2=0,sum3=0;
		int js1=0,js2=0,js3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		}
		if(n>=1e5){
			sort(a1+1,a1+1+n);
			sort(a2+1,a2+1+n);
			int p=n;
			for(int i=1;i<=n;i++){
				int maxx=a1[p];
				if(a1[i]+a2[p]>=maxx&&js1<=n/2&&js2<=n/2&&!vis1[a1[i]]&&!vis2[a2[p]]){
					sum1+=a1[i],sum2+=a2[p];
					js1++,js2++;
					vis1[a1[i]]=1,vis2[a2[p]]=1;
					p--;
				}
			}
			printf("%d\n",sum1+sum2+sum3);
		}else if(n<=1e5){
			int maxx=-1;
			for(int i=1;i<=n/2;i++){
				for(int j=i+1;j<=i+n/2;j++){
					for(int k=j+1;k<=j+n/2;k++){
						maxx=max(a1[i]+a2[j]+a3[k],maxx);
					}
				}
			}
			cout<<maxx<<endl;
		}
	}
	return 0;
}

