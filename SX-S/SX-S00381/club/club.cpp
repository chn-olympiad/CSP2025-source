#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N],b[N],c[N],t[4];
long long ans=0;
void dfs(int l,long long now){
	if(l==n+1){
		ans=max(ans,now);
		return;
	}
	if(t[1]+1<=n/2) t[1]++,dfs(l+1,now+a[l]),t[1]--;
	if(t[2]+1<=n/2) t[2]++,dfs(l+1,now+b[l]),t[2]--;
	if(t[3]+1<=n/2) t[3]++,dfs(l+1,now+c[l]),t[3]--;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
    	t[1]=t[2]=t[3]=ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        dfs(1,0);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
    int num,id;
}q[4][N];
int T,n,l[3][4],t[4];
bool fl[N];
bool cmp(node x,node y){
    return x.num>y.num;
}
int main()
{
    scanf("%d",&T);
    while(T--){
        t[1]=t[2]=t[3]=0,l[1][1]=l[1][2]=l[1][3]=1,l[2][1]=l[2][2]=l[2][3]=2;
        memset(fl,0,sizeof fl);
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%d%d%d",&q[1][i].num,&q[2][i].num,&q[3][i].num);
            q[1][i].id=q[2][i].id=q[3][i].id=i;
        }
        sort(q[1]+1,q[1]+n+1,cmp);
        sort(q[2]+1,q[2]+n+1,cmp);
        sort(q[3]+1,q[3]+n+1,cmp);
        int n_2=n/2;
        long long ans=0;
        while((t[1]<n_2||t[2]<n_2||t[3]<n_2)&&(l[1][1]<=n&&l[1][2]<=n&&l[1][3]<=n&&l[2][1]<=n&&l[2][2]<=n&&l[2][3]<=n)){
        	for(int i=1;i<=2;i++){
        		for(int j=1;j<=3;j++){
        			if(i==2&&l[2][j]==l[1][j]) l[2][j]++;
		            while(l[i][j]<=n&&fl[q[j][l[i][j]].id]){
		            	l[i][j]++;
					}
				}
			}
			if(!(l[1][1]<=n&&l[1][2]<=n&&l[1][3]<=n&&l[2][1]<=n&&l[2][2]<=n&&l[2][3]<=n)) break;
            int maxn=-1,I1=0,J1=0,I2=0,J2=0;
            for(int i1=1;i1<=2;i1++){
            	for(int j1=1;j1<=3;j1++){
            		for(int i2=1;i2<=2;i2++){
            			for(int j2=1;j2<=3;j2++){
            				if(i1==i2&&j1==j2) continue;
		            		if(t[j1]>=n_2||t[j2]>=n_2) continue;
		            		if(i1!=i2&&j1==j2&&t[j1]+1>=n_2) continue;
		            		node u=q[j1][l[i1][j1]],v=q[j2][l[i2][j2]];
		            		if(fl[u.id]||fl[v.id]||u.id==v.id) continue;
		            		if(u.num+v.num>maxn) maxn=u.num+v.num,I1=i1,J1=j1,I2=i2,J2=j2;
						}
					}
				}
			}
			fl[q[J1][l[I1][J1]].id]=fl[q[J2][l[I2][J2]].id]=1;
			t[J1]++,t[J2]++;
			l[I1][J1]++,l[I2][J2]++;
			ans+=maxn;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//1
//10
//2020 14533 18961
//2423 15344 16322
//1910 6224 16178
//2038 9963 19722
//8375 10557 5444
//3518 14615 17976
//6188 13424 16615
//8769 509 4394
//958 3195 9953
//16441 5313 10926
//
//out:147325
*/