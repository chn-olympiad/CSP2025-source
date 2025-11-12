#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][3],b[100005][3],t[3],s[3][100005],x,y,p,q,ans;
struct vt{int a,i;}c[3];
bool cp(vt a,vt b){return a.a>b.a;}
bool cmp(int i,int j){return a[i][b[i][0]]-a[i][b[i][1]]>a[j][b[j][0]]-a[j][b[j][1]];}
bool cm(int i,int j){return a[i][p]-a[i][q]>a[j][p]-a[j][q];}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(s,0,sizeof s);
		memset(t,0,sizeof t);
		n=x=y=p=q=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)c[j].a=a[i][j],c[j].i=j;
			sort(c,c+3,cp);
			for(int j=0;j<3;j++)b[i][j]=c[j].i;
			p=b[i][0],s[p][++t[p]]=i;
		}
		x=max(t[0],max(t[1],t[2]));
		if(x>n/2){
			for(int j=0;j<3;j++)if(x==t[j])y=j;
			sort(s[y]+1,s[y]+x+1,cmp);
			for(int i=n/2+1;i<=x;i++)p=b[s[y][i]][1],s[p][++t[p]]=s[y][i],s[y][i]=0;
			for(int j=0;j<3;j++)if(j!=y)q=j;
			p=3-y-q;
			if(t[p]<t[q])swap(p,q);
			if(t[p]>n/2){
				sort(s[p]+1,s[p]+t[p]+1,cm);
				for(int i=n/2+1;i<=x;i++)s[q][++t[q]]=s[p][i],s[p][i]=0;
			}
		}
		for(int i=0;i<3;i++)for(int j=1;j<=t[i];j++)ans+=a[s[i][j]][i];
		cout<<ans<<"\n";
	}
}
