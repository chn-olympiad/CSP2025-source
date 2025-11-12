#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,r,mc,a[110];
bool cmp(int a,int b);
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(mc=1;a[mc]!=r;mc++);
	int row,line;
	line=(mc-1)/n+1;
	if(line%2){
		row=mc%n;
		if(!row) row=n;
	}else{
		row=n-mc%n+1;
		if(row==n+1) row=1;
	}
	cout<<line<<' '<<row;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
bool cmp(int a,int b){return a>b;}