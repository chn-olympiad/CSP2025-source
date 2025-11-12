#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;
ll n,m,k,c[15],s[10010],l,ans;
bool f[15];
struct iop{
	int x,y,p,pi;
}a[N],b[N];
bool cmp(iop a,iop b){return a.p<b.p;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		cin>>a[i].x>>a[i].y>>a[i].p;
	}
	for(int i=1; i<=k; i++){
		cin>>c[i];
		for(int j=1; j<=n; j++) cin>>s[j];
		for(int j=1; j<n; j++){
			for(int q=j+1; q<=n; q++){
				b[++l].p=s[j]+s[q],b[l].pi=i;
			}
		}
	}
	sort(a+1,a+1+m,cmp);
	sort(b+1,b+1+l,cmp);
	for(int i=1; i<=m; i++) cout<<a[i].p<<" ";
	cout<<endl;
	for(int i=1; i<=l; i++) cout<<b[i].p<<" "<<c[b[i].pi]<<endl;
	cout<<endl;
	int q=0,y=1,u=1;
	while(q<n-1){
		if(f[b[y].pi]==false) b[y].p+=c[b[y].pi];
		if(a[u].p<b[u].p){
			ans+=a[u].p;
			u++;
		}else{
			ans+=b[y].p;
			f[b[y].pi]=true;
			y++;
		}
		cout<<ans<<endl;
		q++;
	}
	cout<<ans;
	return 0; 
}
