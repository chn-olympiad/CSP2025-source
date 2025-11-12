#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
struct node{
	ll a,b,c;
}x[N];
struct edge{
	ll x,idx,flag;
}t[N*3];
bool cmp(edge x,edge y){
	return x.x>y.x;
}
ll vis[N];
ll T,sum;
ll n,len,cnta,cntb,cntc;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	//ting ping tian ming
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnta=cntb=cntc=0;
		sum=0;
		cin>>n;
		len=n/2;
		for(ll i=1;i<=n;++i){
			vis[i]=0;
			cin>>x[i].a>>x[i].b>>x[i].c;
			ll A=x[i].a-max(x[i].b,x[i].c);
			ll B=x[i].b-max(x[i].a,x[i].c);
			ll C=x[i].c-max(x[i].b,x[i].a);
			t[i*3-2]={A,i,1};
			t[i*3-1]={B,i,2};
			t[i*3-0]={C,i,3};
		}
		sort(t+1,t+1+n*3,cmp);
		for(ll i=1;i<=n*3;++i){
			ll idx=t[i].idx,flag=t[i].flag;
//			cout<<it.x<<' '<<it.idx<<" "<<it.flag<<" ";
			if(cnta+cntb+cntc==n) break;
			if(vis[idx]){
//				cout<<"\n";
				continue;
			}else{
//				cout<<"1\n";
				if(flag==1&&cnta<len){
					cnta++;
					sum+=x[idx].a;
					vis[idx]=1;
				}
				if(flag==2&&cntb<len){
					cntb++;
					sum+=x[idx].b;
					vis[idx]=1;
				}
				if(flag==3&&cntc<len){
					cntc++;
					sum+=x[idx].c;
					vis[idx]=1;
				}
				
			}
//			cout<<"cnt:"<<cnta<<' '<<cntb<<" "<<cntc<<"\n";
		}
		cout<<sum<<"\n";
	}
	return 0;
}
