#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105][105],tem[10005],cnt=1,temp;
bool cmp(int x,int y){
	return x>y;
}
bool flag,trr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>tem[i];
	}
	temp=tem[1];
	sort(tem+1,tem+1+n*m,cmp);
	int i=1,j=0;
		for(;;){
			if(j-1==m){
				break;
			}
			else if(i!=n&&!flag&&i!=1){
				i++;
			}
			else if(i!=n&&flag&&i!=1){
				i--;
			}
			else if(i==n){
				flag=1;
    			j++;
				a[i][j]=tem[cnt];
				cnt++;
				i--;
			}else{
				flag=0;
   				j++;
				a[i][j]=tem[cnt];
				cnt++;
				i++;
			}
			a[i][j]=tem[cnt];
			cnt++;
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
   			if(a[i][j]==temp){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}