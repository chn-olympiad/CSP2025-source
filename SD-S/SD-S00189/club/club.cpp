#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll t,n,a,b,c,sum,ans;
bool book[N];
struct node{
	ll num,flag,id;
}abc[3*N];
bool cmp(node x,node y){
	return x.num>y.num;
}
void pian(){
	ll a_=n/2,b_=n/2,c_=n/2;
	sort(abc+1,abc+1+n*3,cmp);
	ll i=0;
	while(n){
		i++;
		if(book[abc[i].id]) continue;
		if(abc[i].flag==1){
			if(a_){
				ans+=abc[i].num;
				a_--;
				n--;
				book[abc[i].id]=1;
				//cout<<"```"<<ans<<endl;
			}
			else continue;
		}
		else if(abc[i].flag==2){
			if(b_){
				ans+=abc[i].num;
				b_--;
				n--;
				book[abc[i].id]=1;
				//cout<<"¡¤¡¤¡¤"<<ans<<endl;
			}
			else continue;
		}
		else{
			if(c_){
				ans+=abc[i].num;
				c_--;
				n--;
				book[abc[i].id]=1;
				//cout<<"..."<<ans<<endl;
			}
			else continue;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		ll maxn_b=-1e6,maxn_c=-1e6;
		for(ll i=1;i<=n;i++){
			cin>>a>>b>>c;
			abc[(i-1)*3+1].num=a;
			abc[(i-1)*3+1].flag=1;
			abc[(i-1)*3+2].num=b;
			abc[(i-1)*3+2].flag=2;
			abc[(i-1)*3+3].num=c;
			abc[(i-1)*3+3].flag=3;
			abc[(i-1)*3+1].id=abc[(i-1)*3+2].id=abc[(i-1)*3+3].id=i;
			maxn_b=max(maxn_b,b);
			maxn_c=max(maxn_c,c);
		}
		if(maxn_b==maxn_c&&maxn_b==0){
			sort(abc+1,abc+1+3*n,cmp);
			for(ll i=1;i<=n/2;i++){
				ans+=abc[i].num;
			}
			cout<<ans<<endl;
		}
		else{
			pian();
		}
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/
