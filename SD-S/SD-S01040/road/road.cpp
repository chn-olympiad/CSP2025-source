#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MX=1e6+10;
const int NX=1e4+10;
struct node{
	int x,y,z;
};
vector<node> v;
int a[MX];
int n,m,k;
vector<int> rd[NX];
int bcj(int x){
	if(a[x]==x)return x;
	a[x]=bcj(a[x]);
	return a[x];
}
bool cmp(node x,node y){
	return x.z<y.z;
}
void kru(){
	sort(v.begin(),v.end(),cmp);
	ll res=0;
	for(int i=0;i<m;i++){
		int x=v[i].x,y=v[i].y,z=v[i].z;
		int p=bcj(x),q=bcj(y);
		if(p!=q){
			a[q]=p;
			res+=z;
		}
	}
	printf("%lld\n",res);
	return ;
}
void mian(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<n+1;j++){
			v.push_back({i,j,0});
		}
	}
	kru();
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v.push_back({x,y,z});
	}
	for(int i=1;i<=max(n,m);i++)a[i]=i;
	int fl=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<n+1;j++){
			int num;
			scanf("%d",&num);
			rd[k].push_back(num);
			if(num!=0)fl=1;
		}
	}
	if(k==0){
		kru();
	}
	else if(fl==0){
		mian();
	}
	return 0;
}
/*
这题大样例没有特殊性质吗，题目上说的约束条件难道不包括特殊性质？ 

5 6 0
1 2 1
1 3 2
2 4 5
3 4 2
2 5 7
3 5 3

5 5 1
1 2 100
1 3 100
2 4 100
2 5 100
3 4 100
0 0 0 0 0 0
*/
