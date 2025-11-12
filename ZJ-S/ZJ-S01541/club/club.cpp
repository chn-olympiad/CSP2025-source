#include<bits/stdc++.h>
#include<vector>
#define pb push_back
#define int long long
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
	int g2,g3,g1;
};
struct edge{
	int num,g,val;
};
int T;
int n,m,ans,cnt;
bool book[N];
node t[N];
vector<int > d[4];
edge p[N*3];
bool cmp(edge f,edge s){
	return f.val>s.val;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//srand(time(0));
	cin>>T;
	while(T--){
		cin>>n;m=n/2;ans=0;cnt=0;
		for(int i=0;i<=3;i++)d[i].clear();
		memset(p,0,sizeof(p));
		memset(book,0,sizeof(book));
		for(int i=1;i<=n;i++){
			book[i]=0;
			cin>>t[i].a>>t[i].b>>t[i].c;
           	if(t[i].a>=t[i].b&&t[i].a>=t[i].c){
           		d[1].pb(i);
           		t[i].g2=t[i].b-t[i].a;
           		t[i].g3=t[i].c-t[i].a;
           		ans+=t[i].a;
			}
			else if(t[i].b>=t[i].a&&t[i].b>=t[i].c)
			{
				d[2].pb(i);
				t[i].g1=t[i].a-t[i].b;
				t[i].g3=t[i].c-t[i].b;
				ans+=t[i].b;
			}
			else{
				d[3].pb(i);
				t[i].g1=t[i].a-t[i].c;
				t[i].g2=t[i].b-t[i].c;
				ans+=t[i].c;
			}
		}
		int l1=d[1].size(),l2=d[2].size(),l3=d[3].size();
		if(l1<=m&&l2<=m&&l3<=m){
			cout<<ans<<"\n";
			continue;
		}
		if(l1>m){
			for(int i=0;i<l1;i++){
				int x=d[1][i];
				p[++cnt]=edge({x,2,t[x].g2});
				p[++cnt]=edge({x,3,t[x].g3});
			}
			sort(p+1,p+cnt+1,cmp);
			int j=1;
			while(l1>m){
				if(!book[p[j].num]){
					ans+=p[j].val;
					book[p[j].num]=1;
					l1--;
				}
				j++;
			}
		}
		else if(l2>m){
			for(int i=0;i<l2;i++){
				int x=d[2][i];
				p[++cnt]=edge({x,1,t[x].g1});
				p[++cnt]=edge({x,3,t[x].g3});
			}
			sort(p+1,p+cnt+1,cmp);
			int j=1;
			while(l2>m){
				if(!book[p[j].num]){
					ans+=p[j].val;
					book[p[j].num]=1;
					l2--;
				}
				j++;
			}
		}
		if(l3>m){
			for(int i=0;i<l3;i++){
				int x=d[3][i];
				p[++cnt]=edge({x,1,t[x].g1});
				p[++cnt]=edge({x,2,t[x].g2});
			}
			sort(p+1,p+cnt+1,cmp);
			int j=1;
			while(l3>m){
				if(!book[p[j].num]){
					ans+=p[j].val;
					book[p[j].num]=1;
					l3--;
				}
				j++;
			}
		}
		
		cout<<ans<<"\n";
	}
	return 0;
//	system("fc club2.out club2.ans");
//	system("fc club3.out club3.ans");
//	system("fc club4.out club4.ans");
//	system("fc club5.out club5.ans");
}
