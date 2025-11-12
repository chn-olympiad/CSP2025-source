#include<bits/stdc++.h>
using namespace std;
int n;
struct masspoint{
	int a,b,c;
}asd[100010];
int x[100010][3];
int f[210][210][210];
bool cmp(masspoint a,masspoint b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>x[i][0]>>x[i][1]>>x[i][2];
		int ans=0;
		if(n>450){
			for(int i=1;i<=n;i++)
				asd[i]={x[i][0],x[i][1],x[i][2]};
			sort(asd+1,asd+1+n,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=asd[i].a;
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int a=0;a<i;a++){
				if(a>n/2)	break;
				for(int b=0;b+a<i;b++){
					if(b>n/2)	break;
					int c=i-1-a-b;
					if(c>n/2)	continue;
					if(a+1<=n/2)
						f[a+1][b][c]=max(f[a+1][b][c],f[a][b][c]+x[i][0]);
					if(b+1<=n/2)
						f[a][b+1][c]=max(f[a][b+1][c],f[a][b][c]+x[i][1]);
					if(c+1<=n/2)
						f[a][b][c+1]=max(f[a][b][c+1],f[a][b][c]+x[i][2]);	
				}
			}
		for(int i=0;i<=n;i++)
			for(int j=0;i+j<=n;j++){
				int k=n-i-j;
				if(i>n/2||j>n/2||k>n/2)	continue;
				ans=max(ans,f[i][j][k]);
			}
		cout<<ans<<"\n";
	}
	return 0;
}
//60pts.
