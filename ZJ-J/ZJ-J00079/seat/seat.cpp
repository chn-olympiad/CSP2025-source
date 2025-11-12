#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],bao,x=1,y=1,r;
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==r)
			bao=i;
	bao--;
	while(bao){
		bao--;
		if(x%2==1){
			y++;
			if(y>n){
				y--;
				x++;
			}
		}else{
			y--;
			if(y<1){
				y++;
				x++;
			}
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
