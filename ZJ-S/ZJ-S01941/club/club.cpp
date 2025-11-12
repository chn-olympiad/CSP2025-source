#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,a[N][10],ans;
bool f[5];
struct Node{
	int b,y,cy;
};
vector<Node> fi[5];
bool cmp(Node x,Node y){
	if(x.y!=y.y) return x.y>y.y;
	else return x.cy>y.cy;
}
void anser(int now){
	sort(fi[now].begin(),fi[now].end(),cmp);
	for(int i=0;i<fi[now].size();i++){
		if(i+1<=n/2){
			ans+=a[fi[now][i].b][now];
			a[fi[now][i].b][0]=1;
		}
		else{
			fi[a[fi[now][i].b][5]].push_back({fi[now][i].b,a[fi[now][i].b][5]-a[fi[now][i].b][6],1e5});
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			a[i][0]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				a[i][4]=1;
				if(a[i][2]>a[i][3]){
					a[i][5]=2;
					a[i][6]=3;
				}
				else{
					a[i][5]=3;
					a[i][6]=2;
				}
			}
			else{
				if(a[i][2]>a[i][3]){
					a[i][4]=2;
					if(a[i][3]>a[i][1]){
						a[i][5]=3;
						a[i][6]=1;
					}
					else{
						a[i][5]=1;
						a[i][6]=3;
					}
				}
				else{
					a[i][4]=3;
					if(a[i][2]>a[i][1]){
						a[i][5]=2;
						a[i][6]=1;
					}
					else{
						a[i][5]=1;
						a[i][6]=2;
					}
				}
			}
		}
		for(int i=1;i<=3;i++)while(!fi[i].empty()){
			fi[i].pop_back();
		}
		for(int i=1;i<=n;i++){
			if(a[i][4]==1){
				fi[1].push_back({i,a[i][a[i][4]]-a[i][a[i][5]],a[i][a[i][5]]-a[i][a[i][6]]});
			}
			else if(a[i][4]==2){
				fi[2].push_back({i,a[i][a[i][4]]-a[i][a[i][5]],a[i][a[i][5]]-a[i][a[i][6]]});
			}
			else{
				fi[3].push_back({i,a[i][a[i][4]]-a[i][a[i][5]],a[i][a[i][5]]-a[i][a[i][6]]});
			}
		}
		
		if(fi[1].size()>fi[2].size()&&fi[1].size()>fi[3].size()){
			anser(1);
			if(fi[2].size()>fi[3].size()){
				anser(2);
			}
			else{
				anser(3);
			}
		}
		else{
			if(fi[2].size()>fi[3].size()){
				anser(2);
				if(fi[1].size()>fi[3].size()){
					anser(1);
				}
				else{
					anser(3);
				}
			}
			else{
				anser(3);
				if(fi[1].size()>fi[2].size()){
					anser(1);
				}
				else{
					anser(2);
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			if(a[i][0]==0){
				ans+=a[i][a[i][4]];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
