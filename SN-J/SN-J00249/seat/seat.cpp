#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],cnt,num,xx,i,b[10005];
bool cmp(int x,int y){
	return x>y;
}
int cl(int x,int y){
	if(x%y !=0){
		return x/y+1;
	}
	else{
		return x/y;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt)
		num=i;
	}
	int lie=cl(num,n);
	xx=num%(n*2);
	
	for(i=1;i<=n;i++){
		b[i]=i;
	}
	for(int j=n;j>=1;j--){
		
		b[i]=j;
		i++;
	}
	if(n==1){
		b[xx]=1;
	}
	cout<<lie<<" "<<b[xx];
}
