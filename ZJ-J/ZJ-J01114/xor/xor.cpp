#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
int n,k;
int a[500005],ans;
node v[500005];
int x;
bool cmp(node x,node y){
	if(x.y!=y.y) return x.y<y.y;
	else return x.x<x.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		int last = 0;
		for(int j = i;j<=n;j++){
			last = (last^a[j]);
			if(last == k){
				v[++x].x = i;
				v[x].y = j;
			}
		}
	}
	sort(v+1,v+x+1,cmp);
	int last = 0;
	for(int i = 1;i<=x;i++){
		if(last<v[i].x){
			last = v[i].y;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
