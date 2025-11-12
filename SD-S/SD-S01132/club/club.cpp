#include<bits/stdc++.h> 
using namespace std;
struct Node{
	int a,b,c;
}l[100010];
long long f[110][110][110];
bool cmp1(Node a,Node b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(f,0,sizeof f);
		bool cnt1=1,cnt2=1;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>l[i].a>>l[i].b>>l[i].c;
			if(l[i].b){
				cnt1=0;
			}
			if(l[i].c){
				cnt2=0;
			}
		}
		if(n<=200){
			for(int m=1;m<=n;m++){
				for(int i=0;i<=m&&i<=n/2;i++){
					for(int j=max(0,m-i-n/2);i+j<=m&&j<=n/2;j++){
						int k=m-i-j;
						if(i>0){
							f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+l[m].a);
						}
						if(j>0){
							f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+l[m].b);
						}
						if(k>0){
							f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+l[m].c);
						}
					}
				}
			}
			long long ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=max(0,n-i-n/2);j<=n/2;j++){
					int k=n-i-j;
					ans=max(ans,f[i][j][k]);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(cnt1&&cnt2){
			sort(l,l+1+n,cmp1);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=l[i].a;
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
