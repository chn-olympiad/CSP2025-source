#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,t;
int a[N],b[N],c[N];
int tonga[N],tongb[N],tongc[N];
void solve(){
	int ans=0;
	int k=n/2;
	while(1){
		int maxn=0;
		int s=0;
		int maxnn=0;
		int ss=0;
		int maxnnn=0;
		int sss=0;
		int rs=0;
		for(int i=1;i<=n;i++){
			if(maxn<a[i]){
				maxn=a[i];
				s=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(maxnn<b[i]){
				maxnn=b[i];
				ss=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(maxnnn<c[i]){
				maxnnn=c[i];
				sss=i;
			}
		}
		if(s==ss || s==sss || ss==sss || s==ss==sss){
			if(s==ss==sss){
				int mmm=maxn;
				rs=s;
				char nb='a';
				if(mmm<maxnn){
					mmm=maxnn;
					rs=ss;
					nb='b';
				}
				if(mmm<maxnnn){
					mmm=maxnnn;
					rs=sss;
					nb='c';
				}
				if(nb=='a'){
					tonga[rs]=1;
					sum+=a[rs];
				}else if(nb=='b'){
					tongb[rs]=1;
					sum+=b[rs];
				}else if(nb=='c'){
					tongc[rs]=1;
					sum+=c[rs];
				}	
			}else if(ss==sss){
				if(b[ss]>c[sss]){
					sum+=b[ss];
				}else{
					sum+=c[sss];
				}
			}		
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int i=1;
	while(t--){
		cin>>n;
		cin>>a[i]>>b[i]>>c[i];
		solve();
		i++;
	}
	return 0;
} 
