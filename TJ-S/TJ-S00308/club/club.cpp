#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t=0,n=0,temp=0,sum=0,c[4]={0,0,0,0};
struct node{
	ll a1,a2,a3;
};
node a[100010];
ll maxfunc(ll a,ll b,ll c){
	if(a>b){
		if(a>c){
			return a;
		}else{
			return c;
		}
	}else{
		if(b>c){
			return b;
		}else{
			return c;
		}
	}
}
void update(ll n){
	sum+=n;
}
void check(ll n,ll a,ll b,ll x){
	if(n==a){
		if(c[1]==temp){
			if(max(b,x)==b){
				if(c[2]==temp){
					c[3]==temp?c[3]+=0:c[3]++;
					update(x);
				}else{
					c[2]==temp?c[2]+=0:c[2]++;
					update(b);
				}
			}else{
				if(c[3]==temp){
					c[2]==temp?c[2]+=0:c[2]++;
					update(b);
				}else{
					c[3]==temp?c[3]+=0:c[3]++;
					update(x);
				}
			}
		}else{
			c[1]==temp?c[1]+=0:c[1]++;
			update(a);
		}
	}else if(n==b){
		if(c[2]==temp){
			if(max(a,x)==a){
				if(c[1]==temp){
					c[3]==temp?c[3]+=0:c[3]++;
					update(x);
				}else{
					c[1]==temp?c[1]+=0:c[1]++;
					update(a);
				}
			}else{
				if(c[3]==temp){
					c[1]==temp?c[1]+=0:c[1]++;
					update(a);
				}else{
					c[3]==temp?c[3]+=0:c[3]++;
					update(x);
				}
			}
		}else{
			c[2]==temp?c[2]+=0:c[2]++;
			update(b);
		}
	}else{
		if(c[3]==temp){
			if(max(a,b)==a){
				if(c[1]==temp){
					c[2]==temp?c[2]+=0:c[2]++;
					update(b);
				}else{
					c[1]==temp?c[1]+=0:c[1]++;
					update(a);
				}
			}else{
				if(c[2]==temp){
					c[1]==temp?c[1]+=0:c[1]++;
					update(a);
				}else{
					c[2]==temp?c[2]+=0:c[2]++;
					update(b);
				}
			}
		}else{
			c[3]==temp?c[3]+=0:c[3]++;
			update(x);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(ll i=1;i<=t;i++){
		cin>>n;
		for(ll j=1;j<=n;j++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		} 
		temp=n/2;
		for(ll j=1;j<=n;j++){
			check(maxfunc(a[i].a1,a[i].a2,a[i].a3),a[i].a1,a[i].a2,a[i].a3);
		}
		cout<<sum<<endl; 
		sum=0;
		temp=0;
		n=0;
	}
	return 0;
} 
