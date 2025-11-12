#include<bits/stdc++.h>
using namespace std;
int a[100010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int s=n*m,cnt=a[1],asd;
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++){
		if(cnt==a[i]){
			asd=i;
			break;
		} 
	}
	int pd=1;
	int x=1,j=1,j1=1,j2=1,zz=0;
	while(s--){
		zz++;
		if(zz==asd){
			cout<<j<<" "<<x;
			break;
		}
		if(x==n&&j<m&&j1==1){
			j++;
			pd=0;
			j1=0;
			continue;
		}
		if(pd==1){
			x++;
			j1=1;
			continue;
		}
		if(x==1&&j<m&&j2==1){
			j++;
			pd=1;
			j2=0;
			continue;
		}
		if(pd==0){
			x--;
			j2=1;
			continue;
		}
		
	}
	return 0;
} 
