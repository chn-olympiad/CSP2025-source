 /*
 3 3
 94 95 96 97 98 99 100 93 92
 */
#include<bits/stdc++.h>
using namespace std;
const int N=1000+10;
int n,m; 
int mp[N],a[N][N];
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int w=n*m;
	for(int i=1;i<=n*m;i++) cin>>mp[i];
	int sum=mp[1];
	sort(mp+1,mp+w+1,cmp);
	//for(int i=1;i<=n*m;i++) cout<<mp[i];
	//cout<<endl;
	int len=0,c=m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2!=0) a[i][j]=mp[++len];
			else if(i%2==0){
				a[i][c]=mp[++len];
				c--;
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(sum==a[i][j]){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
