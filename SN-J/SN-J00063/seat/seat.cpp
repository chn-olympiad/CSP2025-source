//SN-J00063
#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[305],cnt,s[15][15];
bool flag;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1],flag=false;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		flag=!flag;
		if(flag)
			for(int j=1;j<=n;j++) s[j][i]=a[++cnt];
		else
			for(int j=n;j;j--) s[j][i]=a[++cnt];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]==k){
				cout<<j<<" "<<i;
				return 0;
			}
}
