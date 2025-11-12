#include<bits/stdc++.h>
using namespace std;
inline maxx(long long a,long long b){
	return a>b?a:b;
}
inline minn(long long a,long long b){
	return a<b?a:b;
}
struct nnn{
	long long in[4],mx;
}f[100010];
long long n,t,a[4],ans;
short g;
bool cmp(nnn x,nnn y){
	if(x.in[1]+x.in[2]+x.in[3]!=y.in[1]+y.in[2]+y.in[3]) {
		return x.in[1]+x.in[2]+x.in[3]<y.in[1]+y.in[2]+y.in[3];
	}
	if(x.mx!=y.mx) {
		return x.mx<y.mx;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>f[i].in[1]>>f[i].in[2]>>f[i].in[3];
			f[i].mx=maxx(f[i].in[1],f[i].in[2]);
			f[i].mx=maxx(f[i].in[3],f[i].mx);
		}
		sort(f+1,f+n+1,cmp);
		a[1]=a[2]=a[3]=0;
		for(int i=1;i<=n;i++){
			if(f[i].in[1]>f[i].in[2]){
				if(f[i].in[1]>f[i].in[3]){
					g=0;
				}else{
					g=2;
				}
			}else{
				if(f[i].in[2]>f[i].in[3]){
					g=1;
				}else{
					g=2;
				}
			}
			ww:
				
			if(a[g+1]+1>n/2){
				g=g%3+1;
				goto ww;
			}else{
				a[g+1]++;
			}
			ans+=f[i].in[g+1];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
