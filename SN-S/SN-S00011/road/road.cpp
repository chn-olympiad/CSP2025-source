#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,k,b[1005][1005],c[10005],d;
struct node{
	ll x,y,z;
}a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
	for(ll i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int cmp=0;
		for(int j=0;j<=n;j++){
			cin>>b[j];
			cmp+=b[i];
		}
		d=min(d,cmp);
	} 
	cout<<d; 
	return 0;
}
//哦太好了T2废了 
/*
工大高中部像那个什么恐怖无限流副本 
尤其是厕所特别旧 
五楼最里边的那个厕所特别恐怖 
墙上全是蜘蛛网
天花板是塌下来的
那个门旧的令我怀疑人生
我现在很害怕 
所以T2怎么写
*/ 
