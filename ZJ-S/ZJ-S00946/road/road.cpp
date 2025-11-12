#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d",&n);scanf("%d",&m);scanf("%d",&k);
	cout<<n<<m<<k;
	int st[n][n];
	memset(st,0,sizeof(st));
	if(k==0){
		int a,b,c;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&a);scanf("%d",&b);scanf("%d",&c);
			st[a][b]=c;
			st[b][a]=c;
	   }
		int sum=0;
		bool use[n];
		int jl[n];
		memset(use,0,sizeof(use));
		use[0]=1;
		for(int i=0;i<n;i++)
		jl[i]=st[0][i];
		for(int i=1;i<n-1;i++){
			int min=0;
			for(int k=0;k<n;k++)
			if(jl[k]>0&&jl[k]<jl[min])min=k;
			sum+=jl[min];
			for(int k=0;k<n;k++)
			{
				if(jl[k]==0&&use[k]==0)jl[k]=st[min][k];
				else if(use[k]==0)jl[k]=max(jl[k],st[min][k]);
			}
		}
		cout<<sum;
	}
	else{
		int a,b,c;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&a);scanf("%d",&b);scanf("%d",&c);
			st[a][b]=c;
			st[b][a]=c;
	   }
	   int free;
	   scanf("%d",&free);
	   for(int i=0;i<k;i++)
	   for(int j=0;j<=n;j++){
	   	scanf("%d",&c);
	   	if(c<st[i][j]){
	   		st[i][j]=c;
	   		st[j][i]=c;
		   }
	   }
		int sum=0;
		bool use[n];
		int jl[n];
		memset(use,0,sizeof(use));
		use[0]=1;
		for(int i=0;i<n;i++)
		jl[i]=st[0][i];
		int p[n];
		for(int i=1;i<=n-1;i++){
			int min=0;
			for(int k=0;k<n;k++)
			if(jl[k]>0&&jl[k]<jl[min])min=k;
			sum+=jl[min];p[i]=jl[min];
			for(int k=0;k<n;k++)
			{
				if(jl[k]==0&&use[k]==0)jl[k]=st[min][k];
				else if(use[k]==0)jl[k]=max(jl[k],st[min][k]);
			}	
		}
		sort(p,p+n,cmp);
		for(int i=0;i<k;i++)sum-=p[i];
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
