#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,n,ans;
bool f1=true; 
bool f2=true;
int a[5][N];
int b[N];
bool cmp(int x,int y) {
	return x>y;
}
int dfs(int i,int x,int y) {
	if(i==1&&x==0&&y==1) return a[2][i];
	else if(i==1&&x==1&&y==0) return a[1][i];
	else if(x==0) return dfs(i-1,x,y-1)+a[2][i];
	else if(y==0) return dfs(i-1,x-1,y)+a[1][i];
	else return max(dfs(i-1,x-1,y)+a[1][i],dfs(i-1,x,y-1)+a[2][i]);
}
int dfs1(int i,int x,int y,int z) {
	if(i==1&&x==1&&y==0&&z==0) return a[1][i];
	else if(i==1&&x==0&&y==1&&z==0) return a[2][i];
	else if(i==1&&x==0&&y==0&&z==1) return a[3][i];
	else if(x==0) return max(dfs1(i-1,x,y-1,z)+a[2][i],dfs1(i-1,x,y,z-1)+a[3][i]);
	else if(y==0) return max(dfs1(i-1,x-1,y,z)+a[1][i],dfs1(i-1,x,y,z-1)+a[3][i]);
	else if(z==0) return max(dfs1(i-1,x-1,y,z)+a[1][i],dfs1(i-1,x,y-1,z)+a[2][i]);
	else return max(max(dfs1(i-1,x-1,y,z)+a[1][i],dfs1(i-1,x,y-1,z)+a[2][i]),dfs1(i-1,x,y,z-1)+a[3][i]);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--) {
		cin>>n;
		ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++) {
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]!=0||a[3][i]!=0) f1=false;
			if(a[3][i]!=0) f2=false;
			b[i]=a[1][i];
		}
		if(n==2) {
			for(int i=1;i<=3;i++) {
				for(int j=1;j<=3&&j!=i;j++) {
					ans=max(ans,a[i][1]+a[j][2]);
				}
			}
			cout<<ans<<"\n";
		}
		else if(n==4) {
			for(int x=1;x<=3;x++) {
				for(int y=1;y<=3;y++) {
					for(int z=1;z<=3;z++) {
						for(int w=1;w<=3;w++) {
							int aa=0,bb=0,cc=0;
							if(x==1) aa++;
							else if(x==2) bb++;
							else if(x==3) cc++;
							if(y==1) aa++;
							else if(y==2) bb++;
							else if(y==3) cc++;
							if(z==1) aa++;
							else if(z==2) bb++;
							else if(z==3) cc++;
							if(w==1) aa++;
							else if(w==2) bb++;
							else if(w==3) cc++;
							if(aa<=2&&bb<=2&&cc<=2) {
								ans=max(ans,a[x][1]+a[y][2]+a[z][3]+a[w][4]);
							}
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
		else if(f1==true) {
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++) {
				ans+=b[i];
			}
			cout<<ans<<"\n";
		}
		else if(f2==true) {
			cout<<dfs(n,n/2,n/2);
		}
		else {
			for(int i=1;i<=n/2;i++) {
				for(int j=1;j<=n/2;j++) {
					int k=n-i-j;
					if(k<=n/2) {
						ans=max(ans,dfs1(n,i,j,k));
					}
				}
			}
		}
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,n;
bool f1=true;
struct node {
	int id;
	int sum;
}a[N],b[N],c[N];
bool cmp(node x,node y) {
	return x.sum>y.sum;
}
int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--) {
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++) {
			cin>>a[i].sum>>b[i].sum>>c[i].sum;
			a[i].id=b[i].id=c[i].id=i;
			if(b[i].sum!=0||c[i].sum!=0) f1=false;
		}
		if(f1==true) {
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) {
				ans+=a[i].sum;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,n;
int f[N][5];
int ans;
struct node {
	int x,y,z;
	int xz;
}a[N];
int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--) {
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			f[i][1]=max(max(f[i-1][1],f[i-1][2]),f[i-1][3])+a[i].x;
			f[i][2]=max(max(f[i-1][1],f[i-1][2]),f[i-1][3])+a[i].y;
			f[i][3]=max(max(f[i-1][1],f[i-1][2]),f[i-1][3])+a[i].z;
		}
		cout<<max(max(f[n][1],f[n][2]),f[n][3])<<"\n";
	}
	return 0;
}
*/
