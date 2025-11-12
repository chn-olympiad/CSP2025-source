#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
const int maxn=1e5+27;
typedef long long ll;
int n;
ll an,bn,cn;
ll ans=0;

ll use[maxn];

struct stu{
	ll a,b,c;
	ll v=0;
}s[maxn];


bool cmp1(stu x,stu y){
	return x.a>y.a;
}

bool cmp2(stu x,stu y){
	return x.b>y.b;
}

bool cmp3(stu x,stu y){
	return x.c>y.c;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>s[i].a>>s[i].b>>s[i].c;
			
		if(n<3){
			if(n==1) cout<<max(s[1].a,max(s[1].b,s[1].c))<<endl;
			else {
				int sum1=0,sum2=0;
				sum1=s[1].a+s[1].b+s[1].c;
				sum2=s[2].a+s[2].b+s[2].c;
				int a1=max(s[1].a,max(s[1].b,s[1].c)),a2=min(s[1].a,min(s[1].b,s[1].c));
				int a3=sum1-a1-a2;
				int b1=max(s[2].a,max(s[2].b,s[2].c)),b2=min(s[2].a,min(s[2].b,s[2].c));
				int b3=sum2-b1-b2;
				cout<<max(a1+b3,a3+b1)<<endl;
			}
			return 0;
		}
		
		sort(s+1,s+1+n,cmp1);
		ll i=1;
		an=0;
		while(an<n/2){
			ans+=s[i].a;
			s[i].v=1;
			use[i]=s[i].a;
			i++;
			an++;
		}
	//	cout<<endl<<"an:"<<an<<endl;
		
		sort(s+1,s+1+n,cmp2);
		i=1;
		bn=0;
		while(bn<n/2){
	//		cout<<"i: "<<i<<" s[i].v: "<<s[i].v<<" ";
			if(s[i].v==1){
				if(s[i].b>s[i].a){
					ans-=s[i].a;
					ans+=s[i].b;
					s[i].v=2;
					use[i]=s[i].b;
					an--;
				} else {
					i++;
					continue;
				}
			} else {
				ans+=s[i].b;
				s[i].v=2;
				use[i]=s[i].b;
			}
			bn++;
			i++;
//			cout<<ans<<endl;
		}
	//	cout<<endl<<ans<<" "<<"bn:"<<bn<<endl;
		
		sort(s+1,s+1+n,cmp3);
		cn=0;
		i=1;
//		cout<<an<<" "<<bn<<endl;
		while(cn+bn+an<=n){
	//		cout<<"i: "<<i<<" s[i].v: "<<s[i].v<<" ";
			if(s[i].v==1){
				if(s[i].c>s[i].a){
					ans-=s[i].a;
					ans+=s[i].c;
					s[i].v=3;
					use[i]=s[i].c;
					an--;
				} else {
					i++;
					continue;
				}
			} else if(s[i].v==2){
				if(s[i].c>s[i].b){
					ans-=s[i].b;
					ans+=s[i].c;
					s[i].v=3;
					use[i]=s[i].c;
					bn--;
				} else {
					i++;
					continue;
				}
			} else {
				ans+=s[i].c;
				s[i].v=3;
				use[i]=s[i].c;
			}
	//		cout<<"ans= "<<ans<<" cn: "<<cn<<endl;
			cn++;
			i++;
		}
		
//		for(int i=1;i<=n;i++) cout<<use[i]<<" ";
		
		ll minn=INT_MAX;
		ll lasti=0;
		if(an==0){
			for(int i=1;i<=n;i++){
				if(use[i]-s[i].a<minn){
					minn=use[i]-s[i].a;
					lasti=i;
				}
			}
			ans+=minn;
			an++;
			if(s[lasti].v==2) bn--;
			else cn--;
			s[lasti].v=1;
		}
		
		minn=INT_MAX;
		lasti=0;
		if(bn==0){
			for(int i=1;i<=n;i++){
				if(use[i]-s[i].b<minn){
					minn=use[i]-s[i].b;
					lasti=i;
				}
			}
			ans+=minn;
			bn++;
			if(s[lasti].v==1) an--;
			else cn--;
			s[lasti].v=2;
		}
		
		minn=INT_MAX;
		lasti=0;
		if(cn==0){
			for(int i=1;i<=n;i++){
				if(use[i]-s[i].c<minn){
					minn=use[i]-s[i].c;
					lasti=i;
				}
			}
			ans+=minn;
			cn++;
			if(s[lasti].v==2) bn--;
			else an--;
			s[lasti].v=3;
		}
		
		cout<<ans<<endl;
		
		ans=0;
		for(int i=1;i<=n;i++){
			s[i].a=0;
			s[i].b=0;
			s[i].c=0;
			s[i].v=0;
		}
	}
	return 0;
} 
/*
3
4
4 2 1  
3 2 4  
5 3 4  
3 5 1 
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
