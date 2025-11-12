#include<bits/stdc++.h>
using namespace std;
long long x=1,y=1,n,m,a[110],ar,ans[20][20];
bool zt=0,p=0;
//zt=1:shang zt=0:xia;
bool cmp(int q,int h){
	if(q!=h)
		return q>h;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>ar;
	a[1]=ar;
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ar){
			cout<<y<<" "<<x;
			break;
		}
		if((x==n||x==1)&&p){
			y++;
			zt=!zt;
			p=0;
		}
		else if(zt){
			x--;
			p=1;
		}
		else{
			x++;
			p=1;
		}
	}
	return 0;
}

