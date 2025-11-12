//CSP-J
//SN-J00313
//张之奇
//西安市铁一中学 

#include <bits/stdc++.h>
using namespace std;

const int maxn=15;
int n,m;
struct ST{
	int id;
	int s;
}a[maxn*maxn];
int b[maxn][maxn];

bool cmp(ST x,ST y){
	return x.s>y.s;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)	cin>>a[i].s,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for (int j=1;j<=m;j++){
		if (j%2==1){
			for (int i=1;i<=n;i++)	b[i][j]=a[++cnt].id;
		}
		else {
			for (int i=n;i>=1;i--)	b[i][j]=a[++cnt].id;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (b[i][j]==1){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
