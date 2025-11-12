#include <bits/stdc++.h> 
using namespace std;
int T,n;
int a[100005],b[100005],c[100005];  
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>T;
	while(T--){
		long long ans;
		int aa=0,bb=0,cc=0,q=0,w=0,e=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z) a[++aa];
			if(y>=x&&y>=z) b[++bb];
			if(z>=y&&z>=x) c[++cc];
		}
		sort(a+1,a+aa+1);
		sort(b+1,b+bb+1);
		sort(c+1,c+cc+1);
		while(n--){
			if(aa>=1&&q<=n/2&&a[aa]>=b[bb]&&a[aa]>=c[cc]) ans+=a[aa],q++,aa--;
			else if(bb>=1&&w<=n/2&&b[bb]>=a[aa]&&b[bb]>=c[cc]) ans+=b[bb],w++,bb--;
			else ans+=c[cc],e++,cc--;
		}
		cout<<ans;
	}
	return 0;
}
