#include<bits/stdc++.h>
using namespace std;
//int n,m,i,g[6000000],q[6000000],rt,dep,j,x,v,nxt[6000000],head[6000000],to[6000000],cnt,nu[6000000];
int n,m,i,j,t,w,k,f,l;
string a[6000000],b[6000000],s,s1;
/*int add(int u,int v){nxt[cnt]=head[u];head[u]=cnt;to[cnt]=v;}
int pd(int u,int x){
	if(u==-1)u=0;
	for(int i=head[u];i;i=nxt[i])
		if(to[i]==x)return i;
	return 0;
}
void build(int rt,string s){
	int n=s.size();
	for(int i=0;i<n;i++){
		int f=0;
		for(int j=head[rt];j;j=nxt[j]){
			int v=to[j];
			if(q[v]==s[i]-97){
				f=1;rt=j;break;
			}
		}
		if(!f){
			q[++cnt]=s[i]-97,add(rt,cnt);
//			int j=g[rt];
//			while(j!=-1&&!pd(j,s[i]-97)){
//				j=g[j];
//			}
//			int x=pd(j,s[i]-97);
//			if(x)g[cnt]=x;
			rt=cnt;
		}
		
	}
	nu[rt]++;
}
void bt(int rt){
	for(int i=head[rt];i;i=nxt[i]){
		int v=to[i];
		j=g[rt];
		while(j!=-1&&!pd(j,v))j=g[j];
		x=pd(j,v);
		if(x)g[i]=x;
		bt(i);
	}
}
void print(int rt){dep++;
	for(int i=head[rt];i;i=nxt[i]){
		v=to[i];
		printf("%d %d %d %d\n",dep,v,g[i],nu[i]);
		print(i);
	}
	dep--;
}*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
//	scanf("%d%d",&n,&m);
	cin>>n>>m;
//	memset(g,-1,sizeof(g));
	for(i=1;i<=n;i++){
		cin>>a[i]>>b[i];
//		build(rt,a[i]);
	}
//	bt(rt);
//	print(rt);
	for(i=1;i<=m;i++){
		cin>>s>>s1;
		if(s.size()!=s1.size()){
			cout<<0<<endl;continue;
		}
		int ans=0;
		for(j=1;j<=n;j++){
			for(t=0;t<(int)s.size();t++)
				if(s[t]!=s1[t])break;
			for(w=s.size()-1;w>=0;w--)
				if(s[w]!=s1[w])break;
//			printf("%d %d\n",t-1,w-(int)a[j].size()+1);
			for(k=max(0,w-(int)a[j].size()+1);k<=(int)s.size()-(int)a[j].size()&&k<=t;k++){
				int f=1;
//				printf("%d ",k);
				for(l=0;l<(int)a[j].size();l++)
					if(a[j][l]!=s[k+l]||b[j][l]!=s1[k+l]){
						f=0;break;
					}
				ans+=f;	
			}
		}
		cout<<ans<<endl;
//		printf("%d\n",ans);
	}
	return 0;
}
