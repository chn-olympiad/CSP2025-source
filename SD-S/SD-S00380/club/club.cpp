#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,T;
const int N=1e5+10;
typedef pair<int,int> piir;
struct person{
	vector<piir> con;
	//满意度 部门 
	int ind;
}a[N];
int cnt[6],ans;
priority_queue<piir,vector<piir>,greater<piir> >p[6];
//满意度 员工编号 
person comp(person a,person b,int j){
	int ra,rb,sum1=0,sum2=0;
	for(int k=0;k<=2;k++){
		if(a.con[k].second==j)ra=k;
		if(b.con[k].second==j)rb=k;
	}
	if(a.con[ra].first<b.con[rb].first)return b;
	else if(a.con[ra].first>b.con[rb].first)return a;
	else{
		if(ra==2)return a;
		if(rb==2)return b;
		ra++,rb++;
		if(a.con[ra].first<b.con[rb].first)return a;
		else if(a.con[ra].first>b.con[rb].first)return b;
		else{
			if(ra==2)return a;
			if(rb==2)return b;
			ra++,rb++;
			if(a.con[ra].first<b.con[rb].first)return a;
			else if(a.con[ra].first>b.con[rb].first)return b;
			else return a;
		}
	}
}
bool cmp(piir a,piir b){
	return a.first>b.first;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(cnt,0,sizeof cnt);
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)a[i].con.clear();
		int a1,a2,a3;
		for (int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a1,&a2,&a3);
			a[i].con.push_back(make_pair(a1,1));
			a[i].con.push_back(make_pair(a2,2));
			a[i].con.push_back(make_pair(a3,3));
			a[i].ind=i;
			sort(a[i].con.begin(),a[i].con.end(),cmp);
		}
		for(int i=1;i<=n;i++){
			for (int j=0;j<=2;j++){
				int pat=a[i].con[j].second,cot=a[i].con[j].first;
				if(cnt[pat]+1<=n/2){
					p[pat].push(make_pair(cot,i));
					cnt[pat]++;
					break;
				}
				else{
					person k=a[p[pat].top().second];
					person win=comp(k,a[i],pat);
					if(win.ind==k.ind)continue;
					else{
						int h;
						for (int l=0;l<=2;l++)if(win.con[l].second==pat)h=win.con[l].first;
						p[pat].pop();
						p[pat].push(make_pair(h,win.ind));
						swap(k,a[i]);
						i--;
						break;
					}
				}
			}
		}
		for(int k=1;k<=3;k++){
			while(!p[k].empty()){
				int h=p[k].top().first;
				ans+=h;
				p[k].pop();
			}
		}
		printf("%lld\n",ans);
	}
}
