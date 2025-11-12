#include <bits/stdc++.h>
using namespace std;

vector<int> p[20005];
int bm[5],p2[20005],n;
bool s[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		//bm={0};
		//st={0};
		//p2={0};
		cin>>n;
		for(int i=1;i<4;i++) bm[i]=0;
		for(int i=0;i<n;i++) s[i]=true;
		for(int i=0;i<=20000;i++) p2[i]=0;
		
		for(int i=0;i<n;i++){
			int c=0;
			for(int j=1;j<4;j++){
				int z;
				cin>>z;
				p[z].push_back(i*10+j);
				p2[z]++;
			}
		}
		int ans=0;
		for(int i=20000;i>0;i--){
			//if(i<=10 && p2[i]>0) cout<<i<<' '<<p2[i]<<endl;
			
			for(int k=0;k<p2[i];k++){
				//cout<<i<<' '<<k<<' '<<p[i][k]<<endl;
				
				int r=p[i][k]/10,b=p[i][k]%10;
				if(s[r] && bm[b]<=n/2){
					ans+=i;
					s[r]=false;
					bm[b]++;
					//cout<<r<<' '<<b<<' '<<s[r]<<' '<<bm[b]<<' '<<i<<endl;
				}
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
