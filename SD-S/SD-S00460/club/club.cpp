#include<bits/stdc++.h>
using namespace std;
struct node{
	int m=-1,x=-1,y=-1,b=-1;
};
vector<node> v;
bool cmp(node a,node b){
	if(a.m!=b.m){
		return a.m>b.m;
	}
	else{
		return a.y>b.y;
	}
}
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a[3];
		cin>>a[0]>>a[1]>>a[2];
		node tmp;
		for(int j=0;j<3;j++){
			if(a[j]>tmp.m){
				tmp.y=tmp.m;
				tmp.m=a[j];
				tmp.b=tmp.x;
				tmp.x=j+1;
			}
			else if(a[j]>tmp.y){
//				cout<<i<<endl;
				tmp.y=a[j];
				tmp.b=j+1;
			}
		}
		v.push_back(tmp);
	} 
	sort(v.begin(),v.end(),cmp);
	int c[4]={0,0,0,0};
	int ans=0;
	for(int i=0;i<n;i++){
		c[v[i].x]++;
		ans+=v[i].m;
		
		if(c[v[i].x]>n/2){
			c[v[i].x]--;
			c[v[i].b]++;
			ans-=v[i].m;
			ans+=v[i].y;
		}
	}cout<<ans<<endl;

}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
		v.clear();
	}
	return 0;
}
