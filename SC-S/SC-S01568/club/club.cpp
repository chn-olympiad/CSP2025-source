#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int ls=0,sl=0,ss=0;
struct my{
	int ft,sd,td;
	int w,mx;
};
my a[114514];
bool pd(my x,my y){
	return x.mx>y.mx;
}
bool pd2(my x,my y){
	return x.mx<y.mx;
}
void solve(){
	int n,ans=0,ans1=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].ft>>a[i].sd>>a[i].td;
		if(max(max(a[i].ft,a[i].sd),a[i].td)==a[i].ft ){
			a[i].w=1;
			a[i].mx=a[i].ft;
		}
		if(max(max(a[i].ft,a[i].sd),a[i].td)==a[i].sd ){
			a[i].w=2;
			a[i].mx=a[i].sd;
		}
		if(max(max(a[i].ft,a[i].sd),a[i].td)==a[i].td ){
			a[i].w=3;
			a[i].mx=a[i].td;
		}
	}
	sort(a,a+n,pd);
	ls=0,sl=0,ss=0;
	for(int i=0;i<n;i++){
		if(a[i].w==1){
			ls++;
			if(ls>n/2){
				ls--;
				if(max(a[i].sd,a[i].td)==a[i].sd ){
					sl++;
					if(sl>n/2){
						sl--;
						ss++;
						ans+=a[i].td;
					}
					else ans+=a[i].sd;
				}
				else if(max(a[i].sd,a[i].td)==a[i].td ){
					ss++;
					ans+=a[i].td;
				}
			}
			else ans+=a[i].ft;
		}
		if(a[i].w==2){
			sl++;
			if(sl>n/2){
				sl--;
				ss++;
				ans+=a[i].td;
			}
			else ans+=a[i].sd;
		}
		if(a[i].w==3){
			ss++;
			ans+=a[i].td;
		}
	}
	ls=0,sl=0,ss=0;
	sort(a,a+n,pd2);
	for(int i=0;i<n;i++){
		if(a[i].w==1){
			ls++;
			if(ls>n/2){
				ls--;
				if(max(a[i].sd,a[i].td)==a[i].sd ){
					a[i].w=2;
				}
				else if(max(a[i].sd,a[i].td)==a[i].td ){
					a[i].w=3;
				}
			}
			else ans1+=a[i].ft;
		}
		if(a[i].w==2){
			sl++;
			if(sl>n/2){
				sl--;
				a[i].w=3;
			}
			else ans1+=a[i].sd;
		}
		if(a[i].w==3){
			ss++;
			ans1+=a[i].td;
		}
	}
	cout<<max(ans,ans1)<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0