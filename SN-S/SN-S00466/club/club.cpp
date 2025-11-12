#include <bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n;
int a[100010][10];
struct ss{
	int lu,tu;
} b[100010][5][5];
typedef pair <int,int> p;
priority_queue <p,vector<p>,greater<p> >q1;
priority_queue <p,vector<p>,greater<p> >q2;
priority_queue <p,vector<p>,greater<p> >q3;
int tong[5];
signed main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=5;i++){
			tong[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(j==k){
						continue;
					}
					b[i][j][k].lu =a[i][j]-a[i][k];
				}
				int biao=0;
				b[i][j][0].lu =1e9;
				if(b[i][j][1].lu >=0&&j!=1){
					if(b[i][j][1].lu <b[i][j][0].lu ){
						b[i][j][0]=b[i][j][1];
						biao=1;
					}
				}
				if(b[i][j][2].lu >=0&&j!=2){
					if(b[i][j][2].lu <b[i][j][0].lu ){
						b[i][j][0].lu =b[i][j][2].lu ;
						biao=2;
					}
				}
				if(b[i][j][3].lu >=0&&j!=3){
					if(b[i][j][3].lu <b[i][j][0].lu ){
						b[i][j][0].lu =b[i][j][3].lu ;
						biao=3;
					}
				}
				b[i][j][0].tu=biao;
			}
			int maxx=0;
			int ji=0;
			if(a[i][1]>maxx){
				maxx=a[i][1];
				ji=1;
			}
			if(a[i][2]>maxx){
				maxx=a[i][2];
				ji=2;
			}
			if(a[i][3]>maxx){
				maxx=a[i][3];
				ji=3;
			}
			tong[ji]++;
			a[i][0]=maxx;
			if(ji==1){
				q1.push({b[i][ji][0].lu ,i});
			}
			if(ji==2){
				q2.push({b[i][ji][0].lu ,i});
			}
			if(ji==3){
				q3.push({b[i][ji][0].lu ,i});
			}
		}
		while(tong[1]>n/2||tong[2]>n/2||tong[3]>n/2){
			if(tong[1]>n/2){
				for(int i=1;i<=tong[1]-n/2;i++){
					p y=q1.top();
					q1.pop();
					if(b[y.second][1][0].tu==2){
						q2.push({b[y.second][b[y.second][1][0].tu][0].lu,y.second});
						tong[2]++;
					}
					if(b[y.second][1][0].tu==3){
						q3.push({b[y.second][b[y.second][1][0].tu][0].lu,y.second});
						tong[3]++;
					}
				}
				tong[1]=n/2;
			}
			if(tong[2]>n/2){
				for(int i=1;i<=tong[2]-n/2;i++){
					p y=q2.top();
					q2.pop();
					if(b[y.second][2][0].tu==1){
						q1.push({b[y.second][b[y.second][2][0].tu][0].lu,y.second});
						tong[1]++;
					}
					if(b[y.second][2][0].tu==3){
						q3.push({b[y.second][b[y.second][2][0].tu][0].lu,y.second});
						tong[3]++;
					}
				}
				tong[2]=n/2;
			}
			if(tong[3]>n/2){
				for(int i=1;i<=tong[3]-n/2;i++){
					p y=q3.top();
					q3.pop();
					if(b[y.second][3][0].tu==1){
						q1.push({b[y.second][b[y.second][3][0].tu][0].lu,y.second});
						tong[1]++;
					}
					if(b[y.second][3][0].tu==2){
						q2.push({b[y.second][b[y.second][3][0].tu][0].lu,y.second});
						tong[2]++;
					}
				}
				tong[3]=n/2;
			}
		}
		while(!q1.empty()){
			p x=q1.top();
			q1.pop();
			ans+=a[x.second][1];
		}
		while(!q2.empty()){
			p x=q2.top();
			q2.pop();
			ans+=a[x.second][2];
		}
		while(!q3.empty()){
			p x=q3.top();
			q3.pop();
			ans+=a[x.second][3];
		}
		cout<<ans<<endl;
	}
	return 0;
}
