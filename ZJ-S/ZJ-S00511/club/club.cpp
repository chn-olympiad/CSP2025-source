#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3],n,pos,num;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		priority_queue< pair<int,int> ,vector< pair<int,int> >,greater< pair<int,int> > >x,y,z;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int maxx=max(a[i][0],max(a[i][1],a[i][2]));
			ans+=maxx;
			if(a[i][0]==maxx){
				x.push({maxx-max(a[i][1],a[i][2]),i});
				if(x.size()>n/2){
					pos=x.top().second,num=x.top().first;
					x.pop();
					ans-=num;
					if(y.size()<n/2-1&&a[pos][0]-a[pos][1]==num){
						y.push({a[pos][1]-a[pos][2],pos});
					}else z.push({a[pos][2]-a[pos][1],pos});
				}
			}else if(a[i][1]==maxx){
				y.push({maxx-max(a[i][0],a[i][2]),i});
				if(y.size()>n/2){
					pos=y.top().second,num=y.top().first;
					y.pop();
					ans-=num;
					if(x.size()<n/2-1&&a[pos][1]-a[pos][0]==num){
						x.push({a[pos][0]-a[pos][2],pos});
					}else z.push({a[pos][2]-a[pos][0],pos});
				}
			}else if(a[i][2]==maxx){
				z.push({maxx-max(a[i][0],a[i][1]),i});
				if(z.size()>n/2){
					pos=z.top().second,num=z.top().first;
					z.pop();
					ans-=num;
					if(y.size()<n/2-1&&a[pos][2]-a[pos][0]==num){
						x.push({a[pos][0]-a[pos][1],pos});
					}else y.push({a[pos][1]-a[pos][0],pos});
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
