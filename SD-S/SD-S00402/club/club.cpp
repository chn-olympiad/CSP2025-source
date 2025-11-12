/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
//#define int long long
int T,n,a[100006][4],ans,b[100006],v[100006];
struct node{
	int s,id;
}c[100006];
bool cmp(node x,node y){
	return x.s>y.s;
}
void fun(int k){
	for(int i=1;i<=n;++i)
		v[i]=0;
	int s=0,l=0,r=0;
	for(int i=1;i<=n;++i){
		if(k==1){
			b[i]=max(a[i][2],a[i][3]);			
			if(a[i][2]>a[i][3])
				++l;
			else
				++r,v[i]=1;
		}
		if(k==2){
			b[i]=max(a[i][1],a[i][3]);
			if(a[i][1]>a[i][3])
				++l;
			else
				++r,v[i]=1;	
		}
		if(k==3){
			b[i]=max(a[i][1],a[i][2]);
			if(a[i][1]>a[i][2])
				++l;
			else
				++r,v[i]=1;
		}
		c[i].s=a[i][k]-b[i];
		c[i].id=i;
		s+=b[i];
	}
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=n/2;++i){
		if(v[c[i].id]){
			--r;
		}else{
			--l;
		}
		s+=c[i].s;
		if(i>=max(l,r)){
			if(s>ans)
				ans=s;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=3;++j)
				cin>>a[i][j];
		ans=0;
		for(int i=1;i<=3;++i)
			fun(i);
		cout<<ans<<"\n";
	}
	return 0;
}
