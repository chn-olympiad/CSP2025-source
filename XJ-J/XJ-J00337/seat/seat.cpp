#include<bits/stdc++.h>
using namespace std;
long long a[100000],b[1001][1001];
bool cmp(int s,int d){
	return s>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;

	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	int cn=a[1];
	int cnt=1;
	int x=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			b[x][i]=a[cnt];
		
			if(a[cnt]==cn){
				if(x>n){
					x-=(x-n);
				}
				cout<<i<<" "<<x;
			}
			cnt++;
				if(i%2!=0&&x<=n){
				x++;
			}
			else if(i%2==0&&x>=1){
				x--;
			}
			
		} 
		
	} 
	return 0 ;
	
}
