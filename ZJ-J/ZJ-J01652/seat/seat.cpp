#include <bits/stdc++.h>

using namespace std;
const int N=110;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	int flag=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			cout<<y<<" "<<x;
			break;
		}
		if(flag==1){
			if(x==n){
				y++;
				flag=0;
			}else{
				x++;
			}
		}else if(flag==0){
			if(x==1){
				y++;
				flag=1;
			}else{
				x--;
			}
		}
	}
	return 0;
}
