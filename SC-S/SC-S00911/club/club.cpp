#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
const int N = 1e5+50;
using namespace std;

struct node{
	ll a,b,c;
}cl[N];

ll t,a_,b_,c_,ans,bt[N];
ll n;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		a_=0,b_=0,c_=0,ans=0;
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>cl[i].a >>cl[i].b >>cl[i].c;
			if(cl[i].a==max(cl[i].a,max(cl[i].b,cl[i].c))){
				ans+=cl[i].a;
				a_++;
			}
			else if(cl[i].b==max(cl[i].a,max(cl[i].b,cl[i].c))){
				ans+=cl[i].b;
				b_++;
			}
			else if(cl[i].c==max(cl[i].a,max(cl[i].b,cl[i].c))){
				ans+=cl[i].c;
				c_++;
			}
		}
		if(n/2>=max(a_,max(b_,c_))){
			cout <<ans <<endl;
			continue;
		}
		else{
			if(a_>n/2){
				int num=a_-n/2,j=1;
				for(int i=1;i<=n;i++){
					if(cl[i].a==max(cl[i].a,max(cl[i].b,cl[i].c))){
						bt[j++]=min(cl[i].a-cl[i].b,cl[i].a-cl[i].c);
					}
				}
				sort(bt+1,bt+j);
				for(int i=1;i<=num;i++){
					ans-=bt[i];
				}
			}
			if(b_>n/2){
				int num=b_-n/2,j=1;
				for(int i=1;i<=n;i++){
					if(cl[i].b==max(cl[i].a,max(cl[i].b,cl[i].c))){
						bt[j++]=min(cl[i].b-cl[i].a,cl[i].b-cl[i].c);
					}
				}
				sort(bt+1,bt+j);
				for(int i=1;i<=num;i++){
					ans-=bt[i];
				}
			}
			if(c_>n/2){
				int num=c_-n/2,j=1;
				for(int i=1;i<=n;i++){
					if(cl[i].c==max(cl[i].a,max(cl[i].b,cl[i].c))){
						bt[j++]=min(cl[i].c-cl[i].b,cl[i].c-cl[i].a);
					}
				}
				sort(bt+1,bt+j);
				for(int i=1;i<=num;i++){
					ans-=bt[i];
				}
			}
		}
		cout <<ans <<endl;
		for(int i=1;i<=n;i++) bt[i]=0;
	}
	return 0;
}
