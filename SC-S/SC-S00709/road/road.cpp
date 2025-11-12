#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,q;
const ll N=1e5+100;
struct s{

ll c,cfs,b;
}a[N];
ll p[N];
ll sum;


	

void add(ll a,ll b){
	p[a]=b; 
}
ll find(ll a){
	if(p[a]==a) return a;
	return find(p[a]);
}

bool cmp(s c,s d){
	return c.b<d.b;
}
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>T>>n>>q;
	
	ll j=0,u=n;
	for(ll i=0;i<=T;i++){
		p[i]=i;
	}
	while(n--){
		
		cin>>a[j].c>>a[j].cfs>>a[j].b;
		j++;
	
} 
	sort(a,a+u,cmp);
	for(int i=0;i<u;i++){
		if(find(a[i].c)==find(a[i].cfs)){
			continue;
		}
		else{
			sum+=a[i].b;
			add(a[i].c,a[i].cfs);
		}
	}
	cout<<sum;
}