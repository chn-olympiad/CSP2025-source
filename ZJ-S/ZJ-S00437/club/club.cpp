//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
using namespace std;
const int N=205;
//struct node{
//	int x,y;
//	operator < (const node &a)const{
//		return a.y>y;
//	}
//};
//priority_queue<node>q1,q2,q3;
bool cmp(int x,int y){
	return x>y;
}
bool flag1,flag2;
int T,n,ans,sum,x[N],y[N],z[N],f[N][N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>T;
	while(T--){
		sum=ans=0;
		memset(f,-1,sizeof(f));
		f[0][0][0]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
			if(z[i])flag1=1;
			if(y[i])flag2=1;
			sum+=max(x[i],max(y[i],z[i]));
		}
		if(!flag1&&!flag2){
			sort(x+1,x+n+1,cmp);
			for(int i=1;i<=2/n;i++)ans+=x[i];
		}
//		else if(!flag1){
//			for(int i=1;i<=k;i++){
//				int tot=0,tot2=0;
//				scanf("%lld",&c[i]);
//				for(int i=1;i<=n;i++){
//					if(x[i]>y[i])ans+=x[i],used[1][++tot]=i;
//					else ans+=y[i],used[2][++tot2];
//				}
//				sort(used[1]+1,used[1]+tot+1,cmp1);
//				sort(used[2]+1,used[2]+tot2+1,cmp1);		
//				if(tot>n/2){
//					for(int i)
//				}
//			}
//		}
		else if(n<=1000){
			for(int i=1;i<=n;i++)
				for(int a=0;a<=n/2;a++)
					for(int b=0;b<=n/2;b++){
						if(a>0&&f[i-1][a-1][b]!=-1)f[i][a][b]=f[i-1][a-1][b]+x[i];
						if(b>0&&f[i-1][a][b-1]!=-1)f[i][a][b]=max(f[i][a][b],f[i-1][a][b-1]+y[i]);
						if(i-a-b<=n/2&&f[i-1][a][b]!=-1)f[i][a][b]=max(f[i][a][b],f[i-1][a][b]+z[i]);
					}
			for(int i=1;i<=n/2;i++)
				for(int j=n/2-i;j<=n/2;j++)ans=max(f[n][i][j],ans);	
		}
		else ans=sum;
		cout<<ans<<"\n";
	}
	return 0;
}
