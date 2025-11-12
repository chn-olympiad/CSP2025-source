#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int f[210][210][210];
int a[N],b[N],c[N];
int seq[N][4];
priority_queue<int,vector<int>,greater<int> > q;
int gt(int i,int id){
	if(id==1)return a[i];
	if(id==2)return b[i];
	if(id==3)return c[i];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		if(n<=200){
			memset(f,0,sizeof(f));
			for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(i+j==n)break; 
				for(int k=0;k<=n/2;k++){
					if(i+j+k>=n)break; 
					f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[i+j+k+1]);
					f[i][j+1][k]=max(f[i][j+1][k],f[i][j][k]+b[i+j+k+1]);
					f[i][j][k+1]=max(f[i][j][k+1],f[i][j][k]+c[i+j+k+1]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(i+j+k==n) ans=max(ans,f[i][j][k]);
				}
			}
		}
		cout<<ans<<'\n';
		}else{
			while(!q.empty()) q.pop(); 
			bool fl=1;
			for(int i=1;i<=n;i++){
				if(b[i]||c[i]) fl=0;
			}
			if(fl){
				sort(a+1,a+n+1);
				int ans=0;
				for(int i=n;i>n/2;i--) ans+=a[i];
				cout<<ans<<'\n';
			}else{
				int ans=0;
				for(int i=1;i<=n;i++){
					if(a[i]>=b[i]) seq[i][1]=1,seq[i][2]=2;
					else seq[i][2]=1,seq[i][1]=2;
				}
				int la=0,lb=0;
				int l[5]={0}; 
				
				for(int i=1;i<=n;i++){
					
					if(l[seq[i][1]]==n/2){
						if(gt(i,seq[i][1])-q.top()>gt(i,seq[i][2])){
							ans+=gt(i,seq[i][1])-q.top();
							q.pop();
						}else{
							ans+=gt(i,seq[i][2]);
						}
						
						if(seq[i][1]==1) l[2]++;
						else l[1]++;
					}else{
						ans+=gt(i,seq[i][1]);
						if(seq[i][1]==1){
							l[1]++;
							q.push(gt(i,1)-gt(i,2));
						} 
						else{
							l[2]++;
							q.push(gt(i,2)-gt(i,1));
						} 
					}
					
				}
				cout<<ans<<'\n';
			}

		}
		
	}



	return 0;
} 
