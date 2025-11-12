#include<bits/stdc++.h>
#define int long long
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=1e6+9;
int n,m,a[N],b[N],c[N],ans;

bitset<N> vis_a,vis_b,vis_c;

struct node{
	int id,val;
};
bool operator <(const node &x,const node &y){
	return x.val<y.val;
}
priority_queue<node> a_b;
priority_queue<node> a_c;
priority_queue<node> b_a;
priority_queue<node> b_c;
priority_queue<node> c_a;
priority_queue<node> c_b;
priority_queue<node> zz;
int num_a=0,num_b=0,num_c=0;
void push_a(int i){
	num_a++;
	vis_a[i]=1;
	a_b.push({i,b[i]-a[i]});
	a_c.push({i,c[i]-a[i]});
}
void push_b(int i){
	num_b++;
	vis_b[i]=1;
	b_a.push({i,a[i]-b[i]});
	b_c.push({i,c[i]-b[i]});
}
void push_c(int i){
	num_c++;
	vis_c[i]=1;
	c_a.push({i,a[i]-c[i]});
	c_b.push({i,b[i]-c[i]});
}

void solve(){
	cin>>n;
	vis_a.reset();
	vis_b.reset();
	vis_c.reset();
	a_b=a_c=b_a=b_c=c_a=c_b=zz;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	num_a=0,num_b=0,num_c=0;
	for(int i=1;i<=n;i++){
		int it_a=0,flag=0;
		int in_a=a[i];
		while((!a_b.empty())&&!vis_a[a_b.top().id]) a_b.pop();
		while((!a_c.empty())&&!vis_a[a_c.top().id]) a_c.pop();
		if(num_a>=n/2){
			if(a_b.top().val>a_c.top().val){
				in_a+=a_b.top().val;
				it_a=a_b.top().id;
			}else{
				in_a+=a_c.top().val;
				it_a=a_c.top().id;
				flag=1;
			}
		}
		
		int it_b=0;
		int in_b=b[i];
		while((!b_a.empty())&&!vis_b[b_a.top().id]) b_a.pop();
		while((!b_c.empty())&&!vis_b[b_c.top().id]) b_c.pop();
		if(num_b>=n/2){
			if(b_a.top().val>b_c.top().val){
				in_b+=b_a.top().val;
				it_b=b_a.top().id;
			}else{
				in_b+=b_c.top().val;
				it_b=b_c.top().id;
				flag=1;
			}
		}
		
		int it_c=0;
		int in_c=c[i];
		while((!c_b.empty())&&!vis_c[c_b.top().id]) c_b.pop();
		while((!c_a.empty())&&!vis_c[c_a.top().id]) c_a.pop();
		if(num_c>=n/2){
			if(c_a.top().val>c_b.top().val){
				in_c+=c_a.top().val;
				it_c=c_a.top().id;
			}else{
				in_c+=c_b.top().val;
				it_c=c_b.top().id;
				flag=1;
			}
		}
		
		if(in_a>max(in_b,in_c)){
			ans+=in_a;
			if(it_a){
				if(flag){
					//a_c
					a_c.pop();
					vis_a[it_a]=0;
					push_c(it_a);
				}else{
					//a_b
					a_b.pop();
					vis_a[it_a]=0;
					push_b(it_a);
				}
			}
			push_a(i);
		}else if(in_b>max(in_a,in_c)){
			ans+=in_b;
			if(it_b){
				if(flag){
					//b_c
					b_c.pop();
					vis_b[it_b]=0;
					push_c(it_b);
				}else{
					//b_a
					b_a.pop();
					vis_b[it_b]=0;
					push_a(it_b);
				}
			}
			push_b(i);
		}else{
			ans+=in_c;
			if(it_c){
				if(flag){
					//c_b
					c_b.pop();
					vis_c[it_c]=0;
					push_b(it_c);
				}else{
					//c_a
					c_a.pop();
					vis_c[it_c]=0;
					push_a(it_c);
				}
			}
			push_c(i);
		}
	}
	while((!a_b.empty())&&!vis_a[a_b.top().id]) a_b.pop();
	while((!a_b.empty())&&a_b.top().val>0&&num_b<n/2){
		ans+=a_b.top().val;
		vis_a[a_b.top().id]=0;
		push_b(a_b.top().id);
		a_b.pop();
	}
	while((!a_c.empty())&&!vis_a[a_c.top().id]) a_c.pop();
	while((!a_c.empty())&&a_c.top().val>0&&num_c<n/2){
		ans+=a_c.top().val;
		vis_a[a_c.top().id]=0;
		push_c(a_c.top().id);
		a_c.pop();
	}
	while((!b_a.empty())&&!vis_b[b_a.top().id]) b_a.pop();
	while((!b_a.empty())&&b_a.top().val>0&&num_a<n/2){
		ans+=b_a.top().val;
		vis_b[b_a.top().id]=0;
		push_a(b_a.top().id);
		b_a.pop();
	}
	while((!b_c.empty())&&!vis_b[b_c.top().id]) b_c.pop();
	while((!b_c.empty())&&b_c.top().val>0&&num_c<n/2){
		ans+=b_c.top().val;
		vis_b[b_c.top().id]=0;
		push_c(b_c.top().id);
		b_c.pop();
	}
	while((!c_b.empty())&&!vis_c[c_b.top().id]) c_b.pop();
	while((!c_b.empty())&&c_b.top().val>0&&num_b<n/2){
		ans+=c_b.top().val;
		vis_c[c_b.top().id]=0;
		push_b(c_b.top().id);
		c_b.pop();
	}
	while((!c_a.empty())&&!vis_c[c_a.top().id]) c_a.pop();
	while((!c_a.empty())&&c_a.top().val>0&&num_a<n/2){
		ans+=c_a.top().val;
		vis_c[c_a.top().id]=0;
		push_a(c_a.top().id);
		c_a.pop();
	}
	
	cout<<ans<<"\n";
	ans=0;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

