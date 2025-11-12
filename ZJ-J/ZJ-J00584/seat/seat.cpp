#include<bits/stdc++.h>
using namespace std;
int n,m,stu[101],k,idx,c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&stu[i]);
	}
	k=stu[1];
	sort(stu+1,stu+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(stu[i]==k)idx=i;
	}
	c=idx/n;
	r=(idx-1)%n+1;
	if(idx%n>0)c++;
	if(c%2==0)r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}
