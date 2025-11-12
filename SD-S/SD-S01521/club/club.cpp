#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<typename type>
void read(type &x){
	x=0;
	bool flag=0;
	char ch=getchar();
	while(!isdigit(ch)){
		ch=='-'?flag=1:0;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	flag?x=-x:0;
}
const int N=1e5+5;
int T,n;
int a[N][5];
vector<int> v[5];
ll ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		ans=0;
		v[1].clear();
		v[2].clear();
		v[3].clear();
		priority_queue<int,vector<int>,greater<int> > q;
		read(n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				read(a[i][j]);
			}
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				v[1].push_back(i);
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				v[2].push_back(i);
			}
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
				v[3].push_back(i);
			}
			ans+=max(max(a[i][1],a[i][2]),a[i][3]);
		}
		if(v[1].size()>(n/2)){
			for(int i=0;i<v[1].size();++i){
				int j=v[1][i];
				q.push(min(a[j][1]-a[j][2],a[j][1]-a[j][3]));
			}
			while(q.size()>(n/2)){
				ans-=q.top();
				q.pop();
			}
		}
		if(v[2].size()>(n/2)){
			for(int i=0;i<v[2].size();++i){
				int j=v[2][i];
				q.push(min(a[j][2]-a[j][1],a[j][2]-a[j][1]));
			}
			while(q.size()>(n/2)){
				ans-=q.top();
				q.pop();
			}
		}
		if(v[3].size()>(n/2)){
			for(int i=0;i<v[3].size();++i){
				int j=v[3][i];
				q.push(min(a[j][3]-a[j][1],a[j][3]-a[j][2]));
			}
			while(q.size()>(n/2)){
				ans-=q.top();
				q.pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
