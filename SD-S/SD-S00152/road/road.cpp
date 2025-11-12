#include <bits/stdc++.h>
using namespace std;

const int NN=1000005;
struct note
{
	int u,v,w;
}e[NN];


int N,M,K;
int a[15][NN],c[15];
int fa[NN*11];
//int newr[]

bool mycmp(note a,note b)
{
	return a.w<b.w;
}

int find(int u)
{
	if(fa[u]!=u)
		fa[u]=find(fa[u]);
	return fa[u];
}

void hebing(int u,int v)
{
	fa[fa[v]]=u;
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	////////////////////////////////////////////
	cin>>N>>M>>K;
	
	for(int i=1;i<=M;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	
	for(int i=1;i<=K;i++)
	{
		cin>>c[i];
		for(int j=1;j<=N;j++)
			cin>>a[i][j];
	}
	/////////////////////////////////////////////////////
//	if(K==0)   ////K==0特殊处理 
//	{
	
					sort(e+1,e+M+1,mycmp);
					for(int i=1;i<=N;i++) fa[i]=i;
					
					int ans=0;
					for(int i=1;i<=M;i++)
					{
						int u,v;
						u=e[i].u;
						v=e[i].v;
						if(find(u)!=find(v))
						{
							hebing(u,v);
							ans+=e[i].w;
						}
					}
//	}
	/////////////////////////////////////////////
	int xn=0,num=0;//xn表示加入了几座村庄 
	if(K!=0)
{
	
	for(int l=1;l<=K;l++) //枚举1~l村庄 
	{
		xn++;
		
		for(int i=1;i<=N;i++) //加入N条边 
		{
			int cc=M+i; //第cc条边 
			e[cc].w=a[l][i];
			e[cc].u=i;
			e[cc].v=N+xn;
		}
		
		sort(e+1,e+M+xn*N+1,mycmp);
		for(int i=1;i<=N*11;i++) fa[i]=i;		
		
		for(int i=1;i<=M+xn*N;i++)
		{
			int u,v;
			u=e[i].u;
			v=e[i].v;
			if(find(u)!=find(v))
			{
				hebing(u,v);
				num+=e[i].w;
			}
		}
		
		//cout<<"aaa "<<xn<<' '<<num<<endl;
		
		if(num+c[l]>=ans) xn--;
		else ans=num+c[l];
	}
		
}
	
	//////// n<=10^3 二维存图
	
	 
				
	/*for(int i=1;i<=N;i++)
		cout<<"aaa "<<i<<" "<<fa[i]<<endl;*/
	cout<<ans<<endl;
	//cout<<"num "<<num<<endl<<"nx "<<xn<<endl;
	
	
	return 0;
}
