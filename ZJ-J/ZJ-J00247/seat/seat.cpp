#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=15+5,M=105+5;
int n,m,a[M],num[N][N],s,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++)
				num[i][j]=a[++cnt];
		}
		else{
			for(int i=n;i>=1;i--)
				num[i][j]=a[++cnt];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(num[i][j]==s)
				printf("%d %d",j,i);
	}
	return 0;
}