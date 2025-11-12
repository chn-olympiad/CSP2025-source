#include<bits/stdc++.h>
using namespace std;
void t(int i,int m){
	int ans,tans;
	if(i<=m){
		 ans=1;
	}
	else{
		 ans=i/m+1;
	}
	if(ans%2==1){
		 tans=i%m;
		if(! tans)tans=m;
	}
	else{
		tans=m+1-i%m;
	}
	cout<<ans<<' '<<tans;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m],c=n*m;
	int b[c];
	for(int i=0;i<c;i++){
		cin>>b[i];
	}
	for(int j=1;j<=c*(c-1)/2+1;j++){
		for(int i=1;i<c;i++){
			if(b[i]<b[i+1]){
			int sum=b[i];
			b[i]=b[i+1];
			b[i+1]=sum;
		}
		}
		}
	int i;
	for(i=1;i<c;i++){
		if(b[0]>b[i]){
			break;
		}
	}
	t(i,m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
