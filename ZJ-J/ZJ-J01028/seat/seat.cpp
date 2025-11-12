#include <bits/stdc++.h>
using namespace std;
int a[110];
int ans[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+sum+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=sum;i++){
		ans[x][y]=a[i];
		if(a[i]==r){
			cout<<x<<' '<<y;
			break;
		}
		if((y==1 && x%2==0) || (y==n && x%2==1)){
			x++;
		}else{
			if(x%2==1)y++;
			else y--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
