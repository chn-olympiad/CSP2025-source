#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=1e6+10,MOD=1e9+7;
int a[N][4],n,flag[N],ans;
struct Node{
	int x,y,idx;
	friend bool operator < (Node a,Node b){
		return min(a.x,a.y)>min(b.x,b.y);
	}
};
void solve(){
	vector<int> v1,v2,v3;
	ans=0;
	bool flag1=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0||a[i][3]!=0) flag1=0;
	}
	if(flag1){
		vector<int> v1;
		for(int i=1;i<=n;i++){
			v1.push_back(a[i][1]);
		}
		sort(v1.begin(),v1.end(),greater<int>());
		for(int i=0;i<n/2;i++) ans+=v1[i];
		cout<<ans<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		int maxn=max(a[i][1],max(a[i][2],a[i][3]));
		if(maxn==a[i][1]) v1.push_back(i),flag[i]=1;
		else if(maxn==a[i][2]) v2.push_back(i),flag[i]=2;
		else v3.push_back(i),flag[i]=3;
	}
	if(v1.size()>n/2){
		vector<Node> v1c;
		for(int i:v1){
			v1c.push_back({a[i][1]-a[i][2],a[i][1]-a[i][3],i});
		}
		sort(v1c.begin(),v1c.end());
		for(int i=n/2;i<v1c.size();i++){
			if(v1c[i].x<v1c[i].y){
				v2.push_back(v1c[i].idx);
				flag[v1c[i].idx]=2;
			}else{
				v3.push_back(v1c[i].idx);
				flag[v1c[i].idx]=3;
			}
		}
	}
	if(v2.size()>n/2){
		vector<Node> v2c;
		for(int i:v2){
			v2c.push_back({a[i][2]-a[i][1],a[i][2]-a[i][3],i});
		}
		sort(v2c.begin(),v2c.end());
		for(int i=n/2;i<v2c.size();i++){
			if(v2c[i].x<v2c[i].y){
				v1.push_back(v2c[i].idx);
				flag[v2c[i].idx]=1;
			}else{
				v3.push_back(v2c[i].idx);
				flag[v2c[i].idx]=3;
			}
		}
	}
	if(v3.size()>n/2){
		vector<Node> v3c;
		for(int i:v3){
			v3c.push_back({a[i][3]-a[i][1],a[i][3]-a[i][2],i});
		}
		sort(v3c.begin(),v3c.end());
		for(int i=n/2;i<v3c.size();i++){
			if(v3c[i].x<v3c[i].y){
				v1.push_back(v3c[i].idx);
				flag[v3c[i].idx]=1;
			}else{
				v2.push_back(v3c[i].idx);
				flag[v3c[i].idx]=2;
			}
		}
	}
	for(int i=1;i<=n;i++) ans+=a[i][flag[i]];
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}

