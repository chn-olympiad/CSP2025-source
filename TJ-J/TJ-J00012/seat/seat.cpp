#include<bits/stdc++.h>
using namespace std;
bool cmp(int x1,int y1){
	return x1>y1;
}
int m,n,c[101]={0},r,cnt=1;
int mp[11][11]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>c[i];
		if(i==1){
			r=c[i];
		}
	}
	sort(c+1,c+num+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[i][j]=c[cnt];
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				mp[i][j]=c[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]==r){
				cout<<i<<" "<<j;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);	 
	return 0;
}
