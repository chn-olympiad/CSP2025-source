#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct p{
	int xx,yy;
}a1[10];
struct p1{
	int mn,md,mx;
};
struct p2{
	int ii,num;
};
p1 a2[100001],a[100001];
int cmp(p aa,p bb){
	return aa.xx<bb.xx;
}
int cmp1(p2 aa,p2 bb){
	return aa.num<bb.num;
}
vector<p2>v1;
vector<p2>v2;
vector<p2>v3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		v1.clear();
		v2.clear();
		v3.clear();
		int n,ans=0;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a1[1].xx>>a1[2].xx>>a1[3].xx;
			a1[1].yy=1,a1[2].yy=2,a1[3].yy=3;
			sort(a1+1,a1+4,cmp);
			ans+=a1[3].xx;
			a[i].mx = a1[3].yy,a2[i].mx = a1[3].xx;
			a[i].md = a1[2].yy,a2[i].md = a1[2].xx;
			a[i].mn = a1[1].yy,a2[i].mn = a1[1].xx;
		}
		for(int i = 1;i<=n;i++){
			if(a[i].mx==1){
				v1.push_back({i,a2[i].mx});
			}
			else if(a[i].mx==2){
				v2.push_back({i,a2[i].mx});
			}
			else if(a[i].mx==3){
				v3.push_back({i,a2[i].mx});
			}
		}
		sort(v1.begin(),v1.end(),cmp1);
		sort(v2.begin(),v2.end(),cmp1);
		sort(v3.begin(),v3.end(),cmp1);
		if(v1.size()>(n/2)){
			int sum1=ans,sum2=ans;
			for(int i = v1.size()-1-n/2;i>=0;i--){
				sum1-=v1[i].num;
				sum1+=a2[v1[i].ii].md;
			}
			for(int i = v1.size()-1;i>v1.size()-n/2-1;i--){
				sum2-=v1[i].num;
				sum2+=a2[v1[i].ii].md;
			}
//			cout<<sum1<<' '<<sum2<<endl;
			ans = max(sum1,sum2);
		}
		else if(v2.size()>n/2){
			int sum1=ans,sum2=ans;
			for(int i = v2.size()-1-n/2;i>=0;i--){
				sum1-=v2[i].num;
				sum1+=a2[v2[i].ii].md;
			}
			for(int i = v2.size()-1;i>v2.size()-n/2-1;i--){
				sum2-=v2[i].num;
				sum2+=a2[v2[i].ii].md;
			}
			ans = max(sum1,sum2);
		}
		else if(v3.size()>n/2){
			int sum1=ans,sum2=ans;
			for(int i = v3.size()-1-n/2;i>=0;i--){
				sum1-=v3[i].num;
				sum1+=a2[v3[i].ii].md;
			}
			for(int i = v3.size()-1;i>v3.size()-n/2-1;i--){
				sum2-=v3[i].num;
				sum2+=a2[v3[i].ii].md;
			}
			ans = max(sum1,sum2);
		}
		cout<<ans<<endl;
	} 
	return 0;
}