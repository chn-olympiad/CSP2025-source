#include<bits/stdc++.h>
using namespace std;
const int inf=10005;
int n,m;
int a[inf];
int sum;
int mp[105][105];
bool cmp(int x,int y){
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	int p=0,ans=1;
	int x=1,y=1;
	sort(a+1,a+sum+1,cmp);
	while(ans<=sum){
		mp[x][y]=a[ans];
		if(p==0){
			if(x<n){
				x++;
			}else{
				y++;
				p=2;	
			}
		}else if(p==2){
			if(x>1){
				x--;
			}else{
				y++;
				p=0;
			}
		}
		ans++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==cnt){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}/