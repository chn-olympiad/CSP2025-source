#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const ll N=1e5+10;
/*====================*/
const ll INF=0x3F3F3F3F3F3F3F3F;
/*====================*/
struct qq{
	ll x,y,z;
	ll maxx,mio,mins,mi;
	ll minn,mn;
	friend bool operator<(const qq &f,const qq &l){
		if(f.maxx!=l.maxx){
			return f.maxx>l.maxx;
		}else if(f.mins!=l.mins){
			return f.mins>l.mins;
		}else{
			return f.minn>l.minn;
		}	
	}
}a[N];
/*====================*/
ll n,sum;
vector<pair<ll,ll> >p1,p2,p3;
/*====================*/
void Solve(void){
	ll num[4],sum=0;
	memset(num,0,sizeof num);
	
	int cnt1=0,cnt2=0,cnt3=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		ll bx=0,by=0,bz=0;
		if(a[i].x>=a[i].y){bx++;}
		else by++;
		if(a[i].y>=a[i].z){by++;}
		else bz++;
		if(a[i].z>=a[i].x){bz++;}
		else bx++;
		if(bx==2){
			a[i].maxx=a[i].x;
			a[i].mio=1;
			cnt1++;
			p1[cnt1].first=a[i].x;
			p1[cnt1].second=i;
		}
		else if(by==2){
			a[i].maxx=a[i].y;
			a[i].mio=2;
			cnt2++;
			p2[cnt2].first=a[i].y;
			p2[cnt2].second=i;
		}
		else{
			a[i].maxx=a[i].z;
			a[i].mio=3;
			cnt3++;
			p3[cnt3].first=a[i].z;
			p3[cnt3].second=i;
		}
		if(bx==1){a[i].mins=a[i].x;a[i].mi=1;}
		else if(by==1){
			a[i].mins=a[i].y;
			a[i].mi=2;
		}
		else{
			a[i].mins=a[i].z;
			a[i].mi=3;
		}
		if(bx==0){
			a[i].minn=a[i].x;
			a[i].mn=1;
		}
		else if(by==0){
			a[i].minn=a[i].y;
			a[i].mn=2;
		}
		else{
			a[i].minn=a[i].z;
			a[i].mn=3;
		}																							
	}
	//cout<<n<<endl;
	sort(p1.begin(),p1.end());
	sort(p2.begin(),p2.end());
	sort(p3.begin(),p3.end());
	queue<ll>re;
	for(int i=1;i<=cnt1;i++){
		if(num[1]<=n/2){
			sum+=p1[i].first;
		}
		else{
			re.push(p1[i].second);
		}
	}
	for(int i=1;i<=cnt2;i++){
		if(num[2]<=n/2){
			sum+=p2[i].first;
		}
		else{
			re.push(p2[i].second);
		}
	}
	for(int i=1;i<=cnt3;i++){
		if(num[3]<=n/2){
			sum+=p3[i].first;
		}
		else{
			re.push(p3[i].second);
		}
	}
	while(!re.empty()){
		ll i=re.front();
		re.pop();
		if(num[a[i].mi]<n/2){
			sum+=a[i].mins;
			num[a[i].mi]++;
		}else{
			sum+=a[i].minn;
			num[a[i].mn]++;
		}
	}
	cout<<sum<<"\n";
}
/*====================*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;cin>>T;
	while(T--)Solve();
	return 0;
}
  
