#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll maxn=1e5+7;
bool vis[maxn];
struct stu_bf{
	ll a,b,c,idx;
};
vector<stu_bf> an_bf;
ll ans=0;

ll lims,cnt1=0,cnt2=0,cnt3=0;
void dfs(ll l,ll r,ll suma,ll sumb,ll sumc){
	if (l==r){
		ans=max(ans,suma+sumb+sumc);
		return;
	}
	if (cnt1<lims) {
		cnt1++;
		dfs(l+1,r,suma+an_bf[l].a,sumb,sumc);
		cnt1--;
	}
	if (cnt2<lims) {
		cnt2++;
		dfs(l+1,r,suma,sumb+an_bf[l].b,sumc);
		cnt2--;
	}
	if (cnt3<lims) {
		cnt3++;
		dfs(l+1,r,suma,sumb,sumc+an_bf[l].c);
		cnt3--;
	}
	return;
}

bool comp_a(stu_bf a,stu_bf b){
	return a.a>b.a;
}

struct stu{
	pair<ll,ll> sco[3];
	ll idx;
};

bool comp1(pair<ll,ll> pla,pair<ll,ll> plb){
	return pla.first>plb.first;
}

bool comp2(stu a,stu b){
	return (a.sco[0].first+a.sco[1].first+a.sco[2].first)>(b.sco[0].first+b.sco[1].first+b.sco[2].first);
}


vector<stu> an3,an2,an1;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	ll t;
	cin>>t;
	while (t--){
		an_bf.clear();
		cnt1=0,cnt2=0,cnt3=0;
		ans=0;
		
		an3.clear();
		an2.clear();
		an1.clear();
		
		ll n;
		cin>>n;
		bool isb0=1,isc0=1;
		for (ll i=1;i<=n;i++){
			ll abf,bbf,cbf;
			cin>>abf>>bbf>>cbf;
			if (bbf!=0) isb0=0;
			if (cbf!=0) isc0=0;
			an_bf.push_back({abf,bbf,cbf,i});
			
			
			pair<ll,ll> a[3];
			ll cnt0=0;
			a[0]={abf,1};
			a[1]={bbf,2};
			a[2]={cbf,3};
			for (ll j=0;j<3;j++){
				if (a[j].first==0) {
					cnt0++;
				}
			}
			sort(a,a+3,comp1);
			
			stu now;
			now.sco[0]=a[0];
			now.sco[1]=a[1];
			now.sco[2]=a[2];
			now.idx=i;
			
			if (cnt0==0) an3.push_back(now);
			if (cnt0==1) an2.push_back(now);
			if (cnt0==2) an1.push_back(now);
		}
		
		lims=n/2;
	
		if (n<=20){
			dfs(0,n,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		
		if (isb0 && isc0){
			ans=0;
			sort(an_bf.begin(),an_bf.end(),comp_a);
			for (ll i=0;i<lims;i++){
				ans+=an_bf[i].a;
			}
			cout<<ans<<"\n";
			continue;
		}
		
		sort(an1.begin(),an1.end(),comp2);
		sort(an2.begin(),an2.end(),comp2);
		sort(an3.begin(),an3.end(),comp2);
		
		ll siz1=an1.size();
		ll siz2=an2.size();
		ll siz3=an3.size();
		
		ll cnt[4]={0,0,0,0};
		ll sum[4]={0,0,0,0};
		
		for (ll i=0;i<siz1;i++){
			if (cnt[an1[i].sco[0].second]<lims){
				sum[an1[i].sco[0].second]+=(an1[i].sco[0].first);
				cnt[an1[i].sco[0].second]++;
				continue;	
			}
		}
		
		for (ll i=0;i<siz2;i++){
			if (cnt[an2[i].sco[0].second]<lims){
				sum[an2[i].sco[0].second]+=(an2[i].sco[0].first);
				cnt[an2[i].sco[0].second]++;
				continue;	
			}
			else {			
				if (cnt[an2[i].sco[1].second]<lims){
					sum[an2[i].sco[1].second]+=(an2[i].sco[1].first);
					cnt[an2[i].sco[1].second]++;
					continue;	
				}
			}
		}
		
		for (ll i=0;i<siz3;i++){
			if (cnt[an3[i].sco[0].second]<lims){
				sum[an3[i].sco[0].second]+=(an3[i].sco[0].first);
				cnt[an3[i].sco[0].second]++;
				continue;	
			}
			else {
				if (cnt[an3[i].sco[1].second]<lims){
					sum[an3[i].sco[1].second]+=(an3[i].sco[1].first);
					cnt[an3[i].sco[1].second]++;
					continue;	
				}
				else {
					if (cnt[an3[i].sco[2].second]<lims){
						sum[an3[i].sco[2].second]+=(an3[i].sco[2].first);
						cnt[an3[i].sco[2].second]++;
						continue;	
					}
				}
			}
		}
		cout<<sum[1]+sum[2]+sum[3]<<"\n";
	}
}

