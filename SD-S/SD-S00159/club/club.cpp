#include<bits/stdc++.h>
using namespace std;
int b[1000001][4];
pair<int,int> c[1000001];
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.first<y.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
	for(int i=1;i<=1000001;i++){
		for(int j=1;j<=3;j++){
			b[i][j]=0;
		} 
	}
		int n;
		cin>>n;
		int a1=0,a2=0,a3=0;
		long long cnt=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			c[i].second=i;
			if(x>=y&&y>=z){
				c[i].first=x-y;
				a1++;
				b[i][1]=1;
				cnt+=x;
			}
			else if(x>=z&&z>=y){
				a1++;
				c[i].first=x-z;
				cnt+=x;
				b[i][1]=1;
			}
			else if(z>=x&&x>=y){
				a3++;
				c[i].first=z-x;
				b[i][3]=1;
				cnt+=z;
				c[i].second=i;
			} 
			else if(z>=y&&y>=x){
				a3++; 
				c[i].first=z-y; 
				cnt+=z;
				b[i][3]=1;
			}
			else if(y>=x&&x>=z){
				a2++;
				c[i].first=y-x;
				cnt+=y;
				b[i][2]=1;
			}
			else if(y>=z&&z>=x){
				a2++;
				c[i].first=y-z;
				cnt+=y;
				b[i][2]=1;
			}
			}
			sort(c+1,c+n+1,cmp);
			if(a1>n/2){
				for(int i=1;i<=n;i++){
					if(b[c[i].second][1]==1&&a1>n/2){
						a1--;
						cnt-=c[i].first;
					}
				}
			}
			else if(a2>n/2){		
				for(int i=1;i<=n;i++){
					if(b[c[i].second][2]==1&&a2>n/2){
						a2--;
						cnt-=c[i].first;
					}
				}
			}
			else if(a3>n/2){
		for(int i=1;i<=n;i++){
					if(b[c[i].second][3]==1&&a3>n/2){
						a3--;
						cnt-=c[i].first;
					}
				}
			}
			else{
				cnt-=0;
			}
			cout<<cnt<<"\n";
		}
		
	}


