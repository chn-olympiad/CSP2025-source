#include<bits/stdc++.h>
using namespace std;
int x[1001][6]={},book[10001]={},s=1,u=0,f[1001][1001],rs=21474836,ss=0,d[10001];
int a,b,c;int n,m,k;
void l(){
	while(s!=n){int mi=214748364,k=0;
		for(int i=1;i<=m;i++){
			if(book[x[i][0]]!=book[x[i][1]]){
				if(x[i][2]<mi){
					k=i;mi=x[i][2];
				}
			}
		}for(int i=1;i<=m;i++){
			if(book[i]==book[x[k][1]])book[i]=book[x[k][0]];
		}s++;u+=mi; 
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++) book[i]=i;
	for(int i=1;i<=m;i++){
		cin>>x[i][0]>>x[i][1]>>x[i][2];
	}for(int i=1;i<=k;i++){
		for(int j=0;j<n+1;j++){
			cin>>f[i][j];
		}
	}for(int i=1;i<=n;i++) book[i]=i;
	l();ss=u;
	for(int i=1;i<=k;i++){
		rs=min(rs,u);s=1;u=f[i][0];
		for(int k=1;k<=n;k++) book[k]=k;
		for(int j=1;j<=n;j++){
			for(int o=j+1;o<=n;o++){
				m++;
				x[m][0]=j;x[m][1]=o;x[m][2]=f[i][j]+f[i][o];
			}
		}
		l();
		m-=n*(n-1)/2;d[i]=ss<u;
	}
	cout<<rs;
}/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
