#include<bits/stdc++.h>
using namespace std;
int t,a[100011][4],f[100011],n=0,ans=0;
/*struct data{
	int bh,cj;
};
bool operator < (const data &x,const data &y){
	return x.cj>y.cj;
}*/
int min(int a,int b){
	return a<b?a:b;
}
int read() {
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
void wss()
{
		int n=0,ans=0;
		bool bja,bjb,bjc;
		memset(a,0,sizeof(a));
		priority_queue <int> qa;
		priority_queue <int> qb;
		priority_queue <int> qc;
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				qa.push(i);
//				cout<<"a "<<i<<"\n";
				bja=1;
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				qb.push(i);
//				cout<<"b "<<i<<"\n";
				bjb=1;
			}
			if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				qc.push(i);
//				cout<<"c "<<i<<"\n";
				bjc=1;
			}
		}
		int ll=0,g=1;
		int csa=0,csb=0,csc=0;
		while(bja==1||bjb==1||bjc==1){
			if(bja==1){
				bja=0;
				ll=1;
				while(ll<=min(n/2,n/2-csa)&&!qa.empty()){
					int x=qa.top();
					qa.pop();
					ans+=a[x][1];
					ll++;
				}
				csa+=ll;
				g=1;
				while(!qa.empty()){
					int x=qa.top();
					qa.pop();
					if(a[x][2]>=a[x][3]&&csb+g<=n/2){
						qb.push(x);
//						cout<<"b "<<x<<"\n";
						bjb=1;
						g++;
					}
					else{
						qc.push(x);
//						cout<<"c "<<x<<"\n";
						bjc=1;
					}
				}
			}
			if(bjb==1){
				bjb=0;
				ll=1;
				while(ll<=min((int)n/2,(int)n/2-csb)&&!qb.empty()){
					int x=qb.top();
					qb.pop();
					ans+=a[x][2];
					ll++;
				}
				csb+=ll;
				g=1;
				while(!qb.empty()){
					int x=qb.top();
					qb.pop();
					if(a[x][1]>=a[x][3]&&g+csa<=n/2){
						qa.push(x);
//						cout<<"a "<<x<<"\n";
						bja=1;
					}
					else{
						qc.push(x);
//						cout<<"c "<<x<<"\n";
						bjc=1;
					}
				}
			}
			if(bjc==1){
				bjc=0;
				ll=1;
				while(ll<=min(n/2,n/2-csc)&&!qc.empty()){
					int x=qc.top();
					qc.pop();
					ans+=a[x][3];
					ll++;
				}
				csc+=ll;
				g=1;
				while(!qc.empty()){
					int x=qc.top();
					qc.pop();
					if(a[x][1]>=a[x][2]&&csa+g<=n/2){
						qa.push(x);
//						cout<<"a "<<x<<"\n";
						bja=1;
					}
					else{
						qb.push(x);
//						cout<<"b "<<x<<"\n";
						bjb=1;
					}
				}
			}
		}
		printf("%d\n",ans);
}
void dfs(int js,int zz,int bja,int bjb,int bjc)
{
	if(bja>n/2||bjb>n/2||bjc>n/2) return;
//	cout<<js<<" "<<zz<<" "<<bja<<" "<<bjb<<" "<<bjc<<"\n";
	if(js==n){
		if(zz>ans){
			ans=zz;
		}
		return;
	}
	/*if(a[js][1]>=a[js][2]&&a[js][1]>=a[js][3]){
		dfs(js+1,zz+a[js+1][1],bja+1,bjb,bjc);
		if(a[js][3]>a[js][2]){
			dfs(js+1,zz+a[js+1][3],bja,bjb,bjc+1);
			dfs(js+1,zz+a[js+1][2],bja,bjb+1,bjc);
		}
		else{
			dfs(js+1,zz+a[js+1][2],bja,bjb,bjc+1);
			dfs(js+1,zz+a[js+1][3],bja,bjb,bjc+1);
		}
	}		
	if(a[js][2]>=a[js][1]&&a[js][2]>=a[js][3]){
		dfs(js+1,zz+a[js+1][2],bja,bjb+1,bjc);
		if(a[js][1]>a[js][3]){
			dfs(js+1,zz+a[js+1][1],bja+1,bjb,bjc);
			dfs(js+1,zz+a[js+1][3],bja,bjb,bjc+1);
		}
		else{
			dfs(js+1,zz+a[js+1][3],bja,bjb,bjc+1);
			dfs(js+1,zz+a[js+1][1],bja+1,bjb,bjc);
		}
	}
	if(a[js][3]>=a[js][2]&&a[js][3]>=a[js][1]){
		dfs(js+1,zz+a[js+1][3],bja,bjb,bjc+1);
		if(a[js][1]>a[js][2]){
			dfs(js+1,zz+a[js+1][1],bja+1,bjb,bjc);
			dfs(js+1,zz+a[js+1][2],bja,bjb+1,bjc);
		}
		else{
			dfs(js+1,zz+a[js+1][2],bja,bjb+1,bjc);
			dfs(js+1,zz+a[js+1][1],bja+1,bjb,bjc);
		}
	}*/
	dfs(js+1,zz+a[js+1][1],bja+1,bjb,bjc);
	dfs(js+1,zz+a[js+1][2],bja,bjb+1,bjc);
	dfs(js+1,zz+a[js+1][3],bja,bjb,bjc+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		ans=0;n=0;
		memset(a,0,sizeof(a));
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
			}
		}
		if(n>=30){
			wss();
		}
		else{
			dfs(0,0,0,0,0);
		}
		printf("%d\n",ans);
	}
	return 0;
}