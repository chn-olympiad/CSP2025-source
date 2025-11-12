#include<bits/stdc++.h>
using namespace std;
/*
5
1 2 3 4 5
*/
int n,a[1005],tmp[1005],cnt;
void cal(int c,int j,int p){
	if(c==0){
		int maxn=0,tot=0;
		for(int i=1;i<p;i++){
			tot+=tmp[i];maxn=max(maxn,tmp[i]);
		}
		if(2*maxn<tot) cnt++;
		return;
	}
	for(int i=j+1;i<=n-c+1;i++){
		tmp[p]=a[i];
		cal(c-1,i,p+1);
		tmp[p]=0;
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2) cout<<0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		cal(i,0,1);
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
