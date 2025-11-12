#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,p[N][4],sum;
struct node{
	int ch1,ch2,ch3,order;
	bool vis;
}group[N];
bool cmp(node x,node y){
	int mxx=max(x.ch1,max(x.ch2,x.ch3)),mxy=max(y.ch1,max(y.ch2,y.ch3));
	int mnx=min(x.ch1,min(x.ch2,x.ch3)),mny=min(y.ch1,min(y.ch2,y.ch3));
	int mdx=x.ch1+x.ch2+x.ch3-mxx-mnx,mdy=y.ch1+y.ch2+y.ch3-mxy-mny;
	if(mxx!=mxy)return mxx>mxy;
	else if(mdx!=mdy)return mdx>mdy;
	return mnx>mny;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		memset(group,0,sizeof(group));
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> p[i][1] >> p[i][2] >> p[i][3];
			group[i].ch1=abs(p[i][1]-p[i][2]);
			group[i].ch2=abs(p[i][2]-p[i][3]);
			group[i].ch3=abs(p[i][1]-p[i][3]);
			group[i].order=i;
		}
		sort(group+1,group+1+n,cmp);
		int t1=0,t2=0,t3=0;
		for(int i=1;i<=n;i++){
			int mx=max(group[i].ch1,max(group[i].ch2,group[i].ch3));
			if(mx==group[i].ch1){
				int pm=max(p[group[i].order][1],p[group[i].order][2]);
				if(pm==p[group[i].order][1]&&t1<n/2)
					t1++,sum+=p[group[i].order][1],group[i].vis=1;
				else if(pm==p[group[i].order][2]&&t2<n/2)
					t2++,sum+=p[group[i].order][2],group[i].vis=1;
			}
			else if(mx==group[i].ch2){
				int pm=max(p[group[i].order][2],p[group[i].order][3]);
				if(pm==p[group[i].order][2]&&t2<n/2)
					t2++,sum+=p[group[i].order][2],group[i].vis=1;
				else if(pm==p[group[i].order][3]&&t3<n/2)
					t3++,sum+=p[group[i].order][3],group[i].vis=1;
			}
			else if(mx==group[i].ch3){
				int pm=max(p[group[i].order][1],p[group[i].order][3]);
				if(pm==p[group[i].order][1]&&t1<n/2)
					t1++,sum+=p[group[i].order][1],group[i].vis=1;
				else if(pm==p[group[i].order][3]&&t3<n/2)
					t3++,sum+=p[group[i].order][3],group[i].vis=1;
			}
		}
		bool f_group=0;
		for(int i=1;i<=n;i++){
			if(group[i].vis==0){
				f_group=1;break;
			}
		}
		if(f_group){
			for(int i=1;i<=n;i++){
				if(group[i].vis==0){
					if(t1==n/2)
						sum+=max(p[group[i].order][2],p[group[i].order][3]),group[i].vis=1;
					else if(t2==n/2)
						sum+=max(p[group[i].order][1],p[group[i].order][3]),group[i].vis=1;
					else if(t3==n/2)
						sum+=max(p[group[i].order][1],p[group[i].order][2]),group[i].vis=1;
				}
			}
		}
		cout << sum << endl;
		sum=0;
	}
	return 0;
}
