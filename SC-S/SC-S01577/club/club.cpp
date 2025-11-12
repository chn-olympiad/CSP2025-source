/*先把每个人分到自己满意度最高的组
这个时候如果人数最多的那个组的人不到一半就这样
否则 把人数最多的那一组的人 他们的满意度的最大值和中值做差排序
把其中最小的多出的人数的人分去其他组
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200002;
int a1[N],a2[N],a3[N];
int p[N],ty[N];
bool cmp(int x,int y){
	int v1[3]={a1[x],a2[x],a3[x]};
	int v2[3]={a1[y],a2[y],a3[y]};
	sort(v1,v1+3);sort(v2,v2+3);
	return v1[2]-v1[1]<v2[2]-v2[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		memset(ty,0,sizeof(ty));
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			p[i]=i;
		}
		sort(p+1,p+n+1,cmp);
		int c1,c2,c3,ans;
		c1=c2=c3=ans=0;
		for(int i=1;i<=n;i++){
			int ma=max(max(a1[i],a2[i]),a3[i]);
			//int mi=min(min(a1[i],a2[i]),a3[i]);
			if(a1[i]==ma){
				ty[i]=1;
				c1++;
			}else if(a2[i]==ma){
				ty[i]=2;
				c2++;
			}else{
				ty[i]=3;
				c3++;
			}
			ans+=ma;
		}
		if(c1*2>n){
			for(int i=1;i<=n;i++){
				if(c1*2<=n)break;
				if(ty[p[i]]==1){
					int v[3]={a1[p[i]],a2[p[i]],a3[p[i]]};
					sort(v,v+3);
					ans-=(v[2]-v[1]);
					c1--;
				}
			}		
		}
		if(c2*2>n){
			for(int i=1;i<=n;i++){
				if(c2*2<=n)break;
				if(ty[p[i]]==2){
					int v[3]={a1[p[i]],a2[p[i]],a3[p[i]]};
					sort(v,v+3);
					ans-=(v[2]-v[1]);
					c2--;
				}
			}		
		}
		if(c3*2>n){
			for(int i=1;i<=n;i++){
				if(c3*2<=n)break;
				if(ty[p[i]]==3){
					int v[3]={a1[p[i]],a2[p[i]],a3[p[i]]};
					sort(v,v+3);
					ans-=(v[2]-v[1]);
					c3--;
				}
			}		
		}
		cout<<ans<<endl;
	}
	return 0;
}
 