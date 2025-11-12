#include<bits/stdc++.h>
using namespace std;
struct node{
	int maxx,mid,p;
	bool operator<(const node &x)const{
		return maxx-mid>x.maxx-x.mid;
	}
};
int t,n,a[100005][3],ans;
priority_queue<node> q;
template<typename T>
void clean(T &x){
	T tmp;
	swap(tmp,x);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int cnt[3];ans=0;clean(q);
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int val1=a[i][0],val2=a[i][1],val3=a[i][2];
			int maxx,mid;
			if(val1>val2&&val1>val3){
				maxx=0;
				if(val2>val3) mid=1;
				else mid=2;
			}
			else{
				if(val2>val3){
					maxx=1;
					if(val1>val3) mid=0;
					else mid=2;
				}
				else{
					maxx=2;
					if(val1>val2) mid=0;
					else mid=1;
				}
			}
			ans+=max({a[i][0],a[i][1],a[i][2]});
			cnt[maxx]++;
			q.push({a[i][maxx],a[i][mid],maxx});
		}
		int sum=0,pos;
		for(int i=0;i<3;i++){
			if(sum<cnt[i]){
				sum=cnt[i];pos=i;
			}
		}
		while(cnt[pos]>n/2){
			if(q.top().p!=pos) q.pop();
			else{
				ans-=q.top().maxx-q.top().mid;q.pop();
				cnt[pos]--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
