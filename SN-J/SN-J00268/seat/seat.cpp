#include<bits/stdc++.h>
using namespace std;
struct student{
	int c,r;
}a[105];
int n,m;
bool cmp(student p,student k){
	return p.c>k.c;
}
int b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].c;
	int h=a[1].c;
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,f=0;
	for(int i=1;i<=n*m;i++){
		if(x>=1&&x<=n){
			b[x][y]=a[i].c;
			if(f==0) x++;
			else if(f==1) x--;
		}
		else if(f==0&&x>n){
			f=1;
			y++;
			b[x-1][y]=a[i].c;
			x=x-2;
		}
		else if(f==1&&x<1){
			f=0;
			y++;
			b[x+1][y]=a[i].c;
			x=x+2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			if(b[i][k]==h){
				cout<<k<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
