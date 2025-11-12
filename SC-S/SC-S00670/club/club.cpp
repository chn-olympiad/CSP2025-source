#include <iostream>
using namespace std;
int T,n,p[150010],a[150010],in[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	for(int t=0;t<T;++t){
		cin >> n;
		if(n==2){
			int ans=0;
			for(int i=0;i<2;++i){
				for(int j=0;j<3;++j){
					cin >> p[j];
				}
				for(int j=0;j<3;++j){
					cin >> a[j];
				}
			}
			for(int i=0;i<3;++i){
				for(int j=0;j<3;++j){
					if(i!=j){
						ans=max(ans,p[i]+a[j]);
					}
				}
			}
			cout << ans << endl;
			for(int i=0;i<5;++i){
				a[i]=0;
				p[i]=0;
			}
			n=0,ans=0;
			continue;
		}
		for(int i=0;i<n;++i){
			for(int j=1;j<=3;++j){
				cin >> in[j];
			}
			for(int j=1;j<=3*n/2;++j){
				if(j%3==0)a[j]=in[3];
				else a[j]=in[j%3];
				a[j]=max(a[j]+p[j-1],max(p[j],a[j-1]+p[j]-p[j-1]));
			}
			for(int j=1;j<=3*n/2;++j){
				p[j]=a[j];
				a[j]=0;
			}
		}
		cout << p[3*n/2] << endl;
		for(int j=1;j<=3*n/2;++j){
			p[j]=0;
			a[j]=0;
		}
		n=0;
	}
	return 0;
}

