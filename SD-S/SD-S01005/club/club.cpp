#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
} 

int T;
int n;
int a[N][4];
int val[4][N];

bool cmp(int x,int y){
	return x>y;
}

int tot[4];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	T=read();
	while(T--){
		n=read();
		int flag=n/2;
		tot[1]=tot[2]=tot[3]=0;
		for(int i=1;i<=n;i++)
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		int ans=0;
		for(int i=1;i<=n;i++){
			int tmp=max(a[i][1],max(a[i][2],a[i][3]));
			for(int j=1;j<=3;j++)
				if(a[i][j]==tmp){
					int mx=0;
					for(int k=1;k<=3;k++)
						if(k!=j)mx=max(mx,a[i][k]);
					val[j][++tot[j]]=mx-tmp;
					ans+=tmp;
					break;
				}
		}
		int tmp=0;
		for(int i=1;i<=3;i++)
			if(tot[i]>flag){
				tmp=i;
				break;
			}
		if(!tmp){
			cout<<ans<<"\n";
			continue;
		}
		sort(val[tmp]+1,val[tmp]+tot[tmp]+1,cmp);
		for(int i=1;i<=tot[tmp]-flag;i++)
			ans+=val[tmp][i];
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
