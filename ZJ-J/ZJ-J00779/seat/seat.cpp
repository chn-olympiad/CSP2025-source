#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int n1=n*m;
	for(int i=1;i<=n1;i++)
		cin>>a[i];
	int s1=a[1];
	sort(a+1,a+n1+1);
	int cnt=n1+1;
	for(int j=1;j<=m;j++){
		bool flag=0;
		if(j%2==1){
			for(int i=1;i<=n;i++){
				cnt--;
				if(a[cnt]==s1){
					cout<<j<<" "<<i<<'\n';
					flag=1;
					break;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				cnt--;
				if(a[cnt]==s1){
					cout<<j<<" "<<i<<'\n';
					flag=1;
					break;
				}
			}
		}
		if(flag) break;
	}
	return 0;
}
