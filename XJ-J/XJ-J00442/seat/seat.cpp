#include<bits/stdc++.h>
using namespace std;
string s;
int a[1005],cnt=1,n,m,x,ans1,ans2;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(a[cnt]==x){
				ans1=j;
				ans2=i;
			}
			cnt++;
		}
		j++;
		for(int i=n;i>=1;i--){
			if(a[cnt]==x){
				ans1=j;
				ans2=i;
			}
			cnt++;
		}
	} 
	cout<<ans1<<" "<<ans2;
	return 0;
} 
