#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,b[11][11]={},a[105],r,r1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;int c=n*m;
	for(int i=1;i<=c;i++)cin>>a[i];r=a[1];
	sort(a+1,a+c+1,cmp);
	//for(int i=1;i<=c;i++)if(a[i]==r)r1=i;
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				cnt+=1;
				b[i][j]=a[cnt];
				if(b[i][j]==r){
					cout<<j<<" "<<i;return 0;
				}
			}
		}
		else if(j%2==0){
			for(int i=n;i>=1;i--){
				cnt+=1;b[i][j]=a[cnt];if(b[i][j]==r){
					cout<<j<<" "<<i;return 0;
				}
			}
		}
	}
}
