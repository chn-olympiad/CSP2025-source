#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],k,x,w,j=1,o=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	w=n*m;
	for(int i=1;i<=w;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+w+1,cmp);
	for(int i=1;i<=w;i++)
		if(a[i]==k)
			x=i;
	for(int i=2;i<=x;i++){
		if(j%2!=0) o++;
		else o--;
		if((o==1||o==n)&&i<=x-1){
			j++;
			i++;
		}
	}
	cout<<j<<" "<<o;
	return 0;
}
