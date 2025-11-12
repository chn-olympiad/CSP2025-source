#include<bits/stdc++.h>

using namespace std;

int mx(int a,int b,int c){
	if(a>=b && b>=c) return 0;
	if(a>=c && c>=b) return 0;
	if(b>=a && a>=c) return 1;
	if(b>=c && c>=a) return 1;
	if(c>=a && a>=b) return 2;
	if(c>=b && b>=a) return 2;
}
int mn(int a,int b,int c){
	if(a>=b && b>=c) return 2;
	if(a>=c && c>=b) return 1;
	if(b>=a && a>=c) return 2;
	if(b>=c && c>=a) return 0;
	if(c>=a && a>=b) return 1;
	if(c>=b && b>=a) return 0;
}
int mdl(int a,int b,int c){
	if(a>=b && b>=c) return b;
	if(a>=c && c>=b) return c;
	if(b>=a && a>=c) return a;
	if(b>=c && c>=a) return c;
	if(c>=a && a>=b) return a;
	if(c>=b && b>=a) return b;
}
int md(int a,int b,int c){
	if(a>=b && b>=c) return 1;
	if(a>=c && c>=b) return 2;
	if(b>=a && a>=c) return 0;
	if(b>=c && c>=a) return 2;
	if(c>=a && a>=b) return 0;
	if(c>=b && b>=a) return 1;
}
int T,n;
int x,y,z;
int maxx,minn,midd;
long long ans;
struct asd{
	int fst,snd,trd;
	int dlt;
};
asd num[100010];
bool cmp(asd Q,asd QQ){
	return Q.dlt > QQ.dlt;
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		ans = 0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x>>y>>z;
			maxx = max(x,y);
			maxx = max(maxx,z);
			minn = min(x,y);
			minn = min(minn,z);
			midd = mdl(x,y,z);
			num[i].fst = x;
			num[i].snd = y;
			num[i].trd = z;
			num[i].dlt = maxx-midd;
		}
		sort(num,num+n,cmp);
		int sum[3] = {0,0,0};
		for(int i=0;i<n;i++){
			if(sum[mx(num[i].fst,num[i].snd,num[i].trd)] < n/2){
				sum[mx(num[i].fst,num[i].snd,num[i].trd)]++;
				maxx = max(num[i].fst,num[i].snd);
				maxx = max(maxx,num[i].trd);
				ans += maxx;
			}
			else{
				ans += mdl(num[i].fst,num[i].snd,num[i].trd);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
