#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005][5],cz[100005],my[5],t,n,m,i,j,zd,zdh,zx,zxh,s;//a[][i]
bool pd;
int main()
{//解注释！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t>0){
		scanf("%lld",&n);
		m=n,s=0;//初始化 
		for(i=1;i<=3;i++) my[i]=0;
		for(i=1;i<=n;i++) cz[i]=0;
		for(i=1;i<=n;i++){
			a[i][0]=i;
			zd=0,zx=INT_MAX;
			for(j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				if(a[i][j]>zd) zd=a[i][j],zdh=j;
				if(a[i][j]<zx) zx=a[i][j],zxh=j;
			}
			cz[i]=a[i][zdh]-a[i][6-zdh-zxh];
			my[zdh]++;
			a[i][4]=zdh;//志愿编号 
			s+=zd;
		}
		zdh=1;
		if(my[zdh]<my[2]) zdh=2; 
		if(my[zdh]<my[3]) zdh=3;
		if(my[zdh]>(n/2)){
			for(i=1;i<=n;i++){
				if(a[i][4]!=zdh){
					cz[a[i][0]]=-1;
					m--;
				}
			}
			sort(cz+1,cz+n+1);
			m-=n/2;
			i=1;
			while(m){
				if(cz[i]>=0){
					s-=cz[i];
					m--;
				}
				i++;
			}
		}
		printf("%lld\n",s);
		t--;
	}
	return 0;
}
