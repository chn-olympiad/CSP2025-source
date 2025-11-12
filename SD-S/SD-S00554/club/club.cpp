#include<bits/stdc++.h>
using namespace std;
inline void read(int &a){
	int f=1;a=0;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-f;
		c=getchar();
	}
	while(isdigit(c)){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar(); 
	}
	a*=f;
}
const int N=1e5+5;
struct node{
	int num,s1[10];
}s[N];
int t,anss,n,f[N][5][5],c[N][5][5][5],sum2,sum3,sum1,cc[N];
inline void dfs(int res,int c1,int c2,int c3,int m){
	if(c1>n/2||c2>n/2||c3>n/2) return ;
	if(c1+c2+c3==n){
		anss=max(res,anss);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1) dfs(res+s[m].s1[i],c1+1,c2,c3,m+1);
		if(i==2) dfs(res+s[m].s1[i],c1,c2+1,c3,m+1);
		if(i==3) dfs(res+s[m].s1[i],c1,c2,c3+1,m+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){	
				read(s[i].s1[j]);
				if(j==2) sum2+=s[i].s1[j];
				if(j==1) sum1+=s[i].s1[j];
				if(j==3) sum3+=s[i].s1[j];
				cc[i]+=s[i].s1[j];
			}
			s[i].num=i;
		}
		if((sum1==0&&sum2==0)||(sum1==0&&sum3==0)||(sum2==0&&sum3==0)){
			sort(cc+1,cc+1+n);
			int ans=0;
			for(int i=n;i>=n-n/2;i--) ans+=cc[i];
			printf("%d\n",ans);
			continue;
		}
		if(n<=30){
			anss=0;
			dfs(0,0,0,0,1);
			printf("%d\n",anss);
			continue;
		}
		int ans=-0x3f3f3f;
		memset(f,0,sizeof f);
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++) f[1][i][j]=s[1].s1[i];
		}
		c[1][1][1][1]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int mx=0;
				for(int k=1;k<=3;k++){
//					cout<<i<<" "<<j<<" "<<k<<":"<<endl;
					for(int kk=1;kk<=3;kk++){
//						cout<<kk<<" | ";
						if(c[i-1][k][kk][j]==n/2){
//							cout<<endl;
							continue;
						} 
						f[i][j][k]=f[i-1][k][kk]+s[i].s1[j],f[i][j][k];
						for(int m=1;m<=3;m++)
						if(m==j) c[i][j][k][m]=c[i-1][k][kk][m]+1;
						else c[i][j][k][m]=c[i-1][k][kk][m];
//						cout<<s[i].s1[j]<<" "<<f[i-1][k][kk]<<" "<<f[i][j][k]<<" "<<c[i][j][k][1]<<" "<<c[i][j][k][2]<<" "<<c[i][j][k][3]<<endl;				
					}
					ans=max(ans,f[i][j][k]);
//					for(int kk=1;kk<=3;kk++) cout<<c[i-1][k][kk]<<" ";
//					cout<<endl;
				}
				
			}
		} 
		printf("%d\n",ans);
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
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
