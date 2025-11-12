#include<iostream>
#include<algorithm>
using namespace std;
int num[100005][5];
int p[100005];
int cnt[5];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	cin>>t;
	
	while(t--){
		int outans=-1;
		cin>>n;
		if(n==2){
			int a,b,c,d,e,f;
			cin>>a>>b>>c;
			cin>>d>>e>>f;
			int aa=a+e,bb=a+f,cc=b+d,dd=b+f,ee=c+d,ff=c+e;
			cout<<max(aa,max(bb,max(cc,max(dd,max(ee,ff)))));
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>num[i][j];
			}
			p[i]=num[i][1];
		}
		int ans=0;
		sort(p+1,p+n);
		for(int i=n;i>n/2;i--){
			ans+=p[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
