//SN-J00427 强立琨 西安市交大附中浐灞右岸学校 
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int b[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	cnt=b[1];
	sort(b+1,b+n*m+1,cmp);
	int ans=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(b[ans]==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
				ans++;
			} 
		} 
		else{
			for(int j=n;j>=1;j--){
				if(b[ans]==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
				ans++;
			} 
		} 
	}
	return 0;
}
