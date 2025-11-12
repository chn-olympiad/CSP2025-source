#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[4][N],f[250][250][250];
bool flag[N];
struct node{
	int m,id;
}x[N],y[N];
bool cmp(node x,node y){
	return x.m>y.m;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>T;
	while(T--){
		cin>>n;
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]||a[3][i])flag1=0;
			if(a[3][i])flag2=0;
		}
		int ans=0; 
		if(flag1){
			sort(a[1]+1,a[1]+n+1);
			for(int i=n;i>n/2;i--){
				ans+=a[1][i];
			}
			cout<<ans<<endl;
		}
		
		
		
		else if(n<=250){
			memset(f,0,sizeof(f));
			f[1][1][0]=a[1][1],f[1][0][1]=a[2][1],f[1][0][0]=a[3][1];
			for(int i=2;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					for(int k=0;k<=min(i,n/2);k++){
						if(i-j-k>n/2||j+k>i)continue;
						if(j>0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[1][i]);
						if(k>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[2][i]);
						if(i-j-k>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[3][i]);
						ans=max(ans,f[i][j][k]);
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(flag2){
			for(int i=1;i<=n;i++){
				x[i].m=a[1][i];
				y[i].m=a[2][i];
			}
			sort(x+1,x+n+1,cmp);
			sort(y+1,y+n+1,cmp);
			int i=1,j=1,s1=0,s2=0;
			while(s1<n&&s2<n){
				if(x[i].m>=y[j].m){
					s1++;
					ans+=x[i].m;
					flag[x[i].id]=1;
				}
				else{
					s2++;
					ans+=y[j].m;
					flag[y[j].id]=1;
				}
//				cout<<s1<<" "<<s2<<endl;
//				for(int l=1;l<=n;l++)cout<<flag[l]<<" ";
//				cout<<endl;
				while(flag[x[i].id])i++;
				while(flag[y[j].id])j++;
			}
			if(s1==n){
				for(int i=1;i<=n;i++){
					if(!flag[i])ans+=a[2][i];
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(!flag[i])ans+=a[1][i];
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

