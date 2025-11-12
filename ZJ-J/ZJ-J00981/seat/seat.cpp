#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,pos,a[N*N];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int temp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==temp){
			pos=i;
			break;
		}
	}
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++){
				cnt++;
				if(cnt==pos){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				cnt++;
				if(cnt==pos){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
