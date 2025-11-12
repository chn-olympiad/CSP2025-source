#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m;
int len,a[N*N],k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++)	cin>>a[i];
	k=a[1];
	sort(a+1,a+1+len,cmp);
	int x,y;
	for(int i=1;i<=len;i++)
		if(a[i]==k){
			y=(int)((i-1)/(2*n))*2;
			x=i-n*y;
			if(x<=n)
				y++;
			else{
				y+=2;
				x=(2*n)-x+1;
			}
			break;
		}
	cout<<y<<" "<<x;
	return 0;
}
