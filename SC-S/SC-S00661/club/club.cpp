#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int T,n,ans=0,a[maxn][3];
struct node{
	int id,val;
};
vector<node> p1,p2,p3;
bool cmp(node u1,node u2){
	return u1.val<u2.val;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]) ans+=a[i][0],p1.push_back({i,min(a[i][0]-a[i][1],a[i][0]-a[i][2])});
			else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2]) ans+=a[i][1],p2.push_back({i,min(a[i][1]-a[i][0],a[i][1]-a[i][2])});
			else ans+=a[i][2],p3.push_back({i,min(a[i][2]-a[i][0],a[i][2]-a[i][1])});
		}
		if((int)p1.size()>n/2){
			sort(p1.begin(),p1.end(),cmp);
			for(int i=0;i<(int)p1.size()-n/2;i++) ans-=p1[i].val;
		} else if((int)p2.size()>n/2){
			sort(p2.begin(),p2.end(),cmp);
			for(int i=0;i<(int)p2.size()-n/2;i++) ans-=p2[i].val;
		}else if((int)p3.size()>n/2){
			sort(p3.begin(),p3.end(),cmp);
			for(int i=0;i<(int)p3.size()-n/2;i++) ans-=p3[i].val;
		}
		printf("%d\n",ans); ans=0;
		p1.clear(); p2.clear(); p3.clear();
	}
	return 0;
}