#include <iostream>
#include <algorithm>
using namespace std;
int n,m,cnt=1,num=1;
int a[105];
int f[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=m*n;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1)
		{
			for(int j=1;j<=n;j++){
				f[j][i]=a[num];
				num++;
				if(f[j][i]==k)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else if(i%2==0){
			for(int j=n;j>=1;j--){
				f[j][i]=a[num];
				num++;
				if(f[j][i]==k)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
