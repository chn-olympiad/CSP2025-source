#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s[12][12],t;
bool cmp(int p,int q){
	if(p>q) return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2==1) s[i][j]=a[m*i-m+1];
			else s[i][j]=a[m*i-i+1];
		}
	}
	bool b=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==t) {
				cout<<i<<" "<<j<<endl;
				b=1;
				break;	
			}
		}
		if(b) break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
