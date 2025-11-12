#include<bits/stdc++.h>
#define endl '\n'
#define QwQ return 0;
#define IOSO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int a[110];
int main(){
	IOSO
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			s=a[i];
		}
	}
	sort(a+1,a+1+n*m,greater<int>() );
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	int x=1,y=1,flag=1;
	for(int i=1;i<=n*m;i++){
//		cout<<x<<" "<<y<<" "<<a[i]<<" "<<flag<<endl;
		if(a[i]==s){
			break;
		}
		if(flag){
			if(x==n){
				x=n;
				y++;
				flag=0;
			}else{
				x++;
			}
		}else{
			if(x==1){
				x=1;
				y++;
				flag=1;
			}else{
				x--;
			}
		}
	}
	cout<<y<<" "<<x<<endl;
	QwQ;
}
