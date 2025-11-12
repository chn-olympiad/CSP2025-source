#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=1e5+5;
struct node{
	ll a,b,c;
}arr[M];
struct p{
	ll a,b;
	int pos;
};
bool cmp(p x,p y){
	if(x.a==y.a){
		if(x.b==y.b)return x.pos<y.pos;
		else return x.b<y.b; 
	}
	return x.a<y.a;
}
vector<p>a1,b1,c1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		a1.clear();
		b1.clear();
		c1.clear();
		memset(arr,0,sizeof(arr));
		int n,lim;
		scanf("%d",&n);
		lim=n/2;
		for(int i=1;i<=n;i++){
			ll a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			arr[i].a=a;
			arr[i].b=b;
			arr[i].c=c;
			if(a>=max(b,c))a1.push_back((p){a-max(b,c),max(b,c)-min(b,c),i});
			else if(b>=max(a,c))b1.push_back((p){b-max(a,c),max(a,c)-min(a,c),i});
			else c1.push_back((p){c-max(a,b),max(a,b)-min(a,b),i});
		}
		if(a1.size()>lim){
			sort(a1.begin(),a1.end(),cmp);
			int cnt=0,sum=a1.size()-lim;
			for(auto i:a1){
				cnt++;
				if(cnt>sum)break;
				if(arr[i.pos].b>arr[i.pos].c){
					b1.push_back((p){0,arr[i.pos].b-arr[i.pos].c,i.pos});
				}else{
					c1.push_back((p){0,arr[i.pos].c-arr[i.pos].b,i.pos});	
				}
			}
			a1.erase(a1.begin(),a1.begin()+sum);
		}
		if(b1.size()>lim){
			sort(b1.begin(),b1.end(),cmp);
			int cnt=0,sum=b1.size()-lim;
			for(auto i:b1){
				cnt++;
				if(cnt>sum)break;
				if(arr[i.pos].a>arr[i.pos].c){
					a1.push_back((p){0,arr[i.pos].a-arr[i.pos].c,i.pos});
				}else{
					c1.push_back((p){0,arr[i.pos].c-arr[i.pos].a,i.pos});	
				}
			}
			b1.erase(b1.begin(),b1.begin()+sum);
		}
		if(c1.size()>lim){
			sort(c1.begin(),c1.end(),cmp);
			int cnt=0,sum=c1.size()-lim;
			for(auto i:c1){
				cnt++;
				if(cnt>sum)break;
				if(arr[i.pos].a>arr[i.pos].b){
					a1.push_back((p){0,arr[i.pos].a-arr[i.pos].b,i.pos});
				}else{
					b1.push_back((p){0,arr[i.pos].b-arr[i.pos].a,i.pos});	
				}
			}
			c1.erase(c1.begin(),c1.begin()+sum);
		}
		ll ans=0;
		for(auto v:a1)ans+=arr[v.pos].a;
		for(auto v:b1)ans+=arr[v.pos].b;
		for(auto v:c1)ans+=arr[v.pos].c;
		printf("%lld\n",ans);
	}
	return 0;
}