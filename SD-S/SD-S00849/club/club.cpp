#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f; 
} 

struct node{
	int l,v,id,cx;
}b[N*4];

struct nd{
	int id,v;
};

int t,sm,n,a[N][5],len,book[N],c[N],cc[N][4],xx[N][4],jl[N][4],ln[4],bk[N][4],bok[N],d[N];
//¶à²âÇå¿Õ 

bool cmp(node x,node y){
	return x.v>y.v;
}

bool cp(nd x,nd y){
	return x.v>y.v;
}

void dfs(int x,int cnt1,int cnt2,int cnt3,int sum){
	if(x==n+1){
		sm=max(sm,sum);
		return ;
	}
	if(cnt1<n/2){
		dfs(x+1,cnt1+1,cnt2,cnt3,sum+a[x][1]);
	}
	if(cnt2<n/2){
		dfs(x+1,cnt1,cnt2+1,cnt3,sum+a[x][2]);
	}
	if(cnt3<n/2){
		dfs(x+1,cnt1,cnt2,cnt3+1,sum+a[x][3]);
	}
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	t=read();
	
	while(t--){
		memset(c,0,sizeof c);
		memset(bk,0,sizeof bk);
		memset(ln,0,sizeof ln);
		memset(cc,0,sizeof cc);
		memset(xx,0,sizeof xx);
		memset(jl,0,sizeof jl);
		memset(bok,0,sizeof bok);
		n=read();
		len=0;
		for(int i=1;i<=n;i++){
			book[i]=0;
		}
		int f=0;
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			if(a[i][2]!=0||a[i][3]!=0)f=1;
			nd jb[4]={{0,0},{1,a[i][1]},{2,a[i][2]},{3,a[i][3]}};
			int mc[4]={0};
			sort(jb+1,jb+3+1,cp);
			for(int j=1;j<=3;j++){
				xx[i][j]=jb[j].id;
				mc[jb[j].id]=j;
			}
			b[++len]={1,a[i][1],i,mc[1]};
			b[++len]={2,a[i][2],i,mc[2]};
			b[++len]={3,a[i][3],i,mc[3]};
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<sm<<"\n";
			sm=0;
			continue;
		}
		sort(b+1,b+len+1,cmp);
		if(!f){
			int as=0;
			for(int i=1;i<=n/2;i++){
				as+=b[i].v;
			}
			cout<<as<<endl;
			as=0;
			continue;
		}
		
		int ans=0,cnt[4]={0};
		
		for(int i=1;i<=len;i++){
			if(cnt[b[i].l]<n/2&&!book[b[i].id]){
				jl[++ln[b[i].l]][b[i].l]=i; 
				book[b[i].id]=1;
//				cout<<b[i].id<<" "<<b[i].v<<" "<<cc[i][b[i].cx]<<" "<<b[i].cx<<endl;
				ans+=b[i].v;
				cnt[b[i].l]++;
			}else{
				if(cnt[b[i].l]>=n/2&&!book[b[i].id]){
					int mx=0;
					for(int j=1;j<=ln[b[i].l];j++){
						int x=jl[j][b[i].l];
						if(!bk[j][b[i].l]){
							mx=max(mx,b[i].v-a[b[i].id][xx[b[i].id][b[i].cx+1]]-(b[x].v-a[b[x].id][xx[b[x].id][b[x].cx+1]]));
						}
					}
					for(int j=1;j<=ln[b[i].l];j++){
						int x=jl[j][b[i].l];
						if(!bk[j][b[i].l]&&b[i].v-a[b[i].id][xx[b[i].id][b[i].cx+1]]-(b[x].v-a[b[x].id][xx[b[x].id][b[x].cx+1]])==mx){
//							cout<<b[i].v<<" "<<b[x].v<<endl;;
							bk[j][b[i].l]=1;
							ans+=b[i].v;
							ans-=b[x].v;
							book[b[i].id]=1;
//							cout<<b[x].v<<endl;
							int xc=xx[b[x].id][b[x].cx+1];
							jl[++ln[xc]][xc]=x;
							ans+=a[b[x].id][xc];
							cnt[xc]++;
							break;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

