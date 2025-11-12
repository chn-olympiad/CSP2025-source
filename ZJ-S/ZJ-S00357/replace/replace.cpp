#include<bits/stdc++.h>
#define int long long
#define N 1000010
using namespace std;
int T,n,i,ans,j,xx,l1;string a[N],b[N],s1,s2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>T;
	for(i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(T--){
		cin>>s1>>s2;l1=s1.size();ans=0;
		for(i=1;i<=n;i++){
			xx=a[i].size();
			for(j=0;j<l1;j++)
				if(s1.substr(j,xx)==a[i])
					if(s1.substr(0,j)==s2.substr(0,j)&&
					s1.substr(j+xx,l1-j-xx+1)==s2.
					substr(j+xx,l1-j-xx+1)&&s2.substr
					(j,xx)==b[i]){ans++;break;}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
#include<bits/stdc++.h>
#include<Windows.h>
#define int long long
#define N 310
using namespace std;
int n,m,k,lt,xa,xb,ya,yb,xc,yc,d,i,j,xd2,f[N][N],x[N*10],
y[N*10];char xd;
signed main(){
//	freopen(".in","r",stdin);
//	freopen("a.out","w",stdout);
	srand(time(0));lt=10;
	cin>>n>>m>>k>>d;xa=rand()%n+1,ya=rand()%m+1;
	for(i=1;i<=k;i++)x[i]=rand()%n+1,y[i]=rand()%m+1,
	f[x[i]][y[i]]=11;
	xb=rand()%n+1,yb=rand()%m+1;f[xa][ya]=3,f[xb][yb]=1;
	system("cls");
	while(1){
		cout<<lt<<"\n";
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)
				if(f[i][j]==0)cout<<".";
				else cout<<char(f[i][j]);
			cout<<"\n";
		}
		cin>>xd;f[xa][ya]=0;lt++;
		if(xd=='w')xa--;if(xd=='s')xa++;
		if(xd=='a')ya--;if(xd=='d')ya++;
		if(xd=='W')xa-=3;if(xd=='S')xa+=3;
		if(xd=='A')ya-=3;if(xd=='D')ya+=3;
*/