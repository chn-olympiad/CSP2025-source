#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	vector<int> x;
	for (int i=1;i<=n*m;i++){
		int y;
		cin>>y;
		x.push_back(y);
	}
	int r=x[0];
	sort(x.begin(),x.end(),cmp);
	int t=0;
	for (int i=1;i<=m;i++){
		if (i%2==1)
			for (int j=1;j<=n;j++)
				a[i][j]=x[t++];
		else
			for (int j=n;j>=1;j--)
				a[i][j]=x[t++];
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if (a[i][j]==r){
				cout<<i<<' '<<j;
				return 0;
			}
	return 0;
}
