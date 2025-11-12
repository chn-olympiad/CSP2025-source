#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,P=0,T,vis[N],mx,my;
struct node{int a,b,c;}a[N];
bool cmp(node a,node b){return a.a>b.a;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>T;
while(T--){
	cin>>n;m=n>>1;
	int sum=0;
	for(int i=0;i<n;++i){
		cin>>a[i].a>>a[i].b>>a[i].c;
		mx=max(mx,a[i].c);
		my=max(my,a[i].b);
	}
	sort(a,a+n,cmp);
	if(mx==0&&my==0){
		for(int i=0;i<m;++i)sum+=a[i].a;
		cout<<sum<<endl;
	}else if(mx==0){
		
	}
}	return 0;
}/*
不存在一个部门被分配多于n/2个新成员
2
10 9 8->2
 4 0 0->1
10\4]
 9]0
 8 0
	13
*/
