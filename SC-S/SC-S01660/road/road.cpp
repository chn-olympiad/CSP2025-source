#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
struct node{
	int from,to,w;
};
bool cmp(node x,node y){
	return x.w<y.w;
}
vector<node> v;
int n,m,k,root[maxn];
int getroot(int x){
	if(x==root[x]){
		return x;
	}
	return root[x]=getroot(root[x]);
}
bool Union(int x,int y){
	int rx=getroot(x);
	int ry=getroot(y);
	if(rx==ry){
		return true;
	} 
	else{
		root[rx]=ry;
		getroot(x),getroot(y);
		return false;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n >>m >>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin >>x >>y >>w;
		v.push_back((node){x,y,w});
		v.push_back((node){y,x,w});
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			root[i]=i;
		}
		sort(v.begin(),v.end(),cmp);
		int ans=0,t=0;
		for(int i=0;i<2*m;i++){
			if(!Union(v[i].from,v[i].to)){
				root[v[i].from]=v[i].to;
				ans+=v[i].w;
				t++;
				if(t==n-1){
					break;
				}
			}
		}
		cout <<ans;
	} 
	else{
		cout <<0;
	}
	return 0;
}