#include<bits/stdc++.h>
using namespace std;

const int N=10000,M=1000000;
vector<vector<int>> sa(N);
int a1[M],d[M];

int main(){
	
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t,ans=0;
	cin>>t;
	while(t--){
		int n,a,b,c;
		int sum=0;
		cin>>n;
		memset(a1,0,sizeof a1);
		int k=0;
		bool fb=true,fc=true;
		for(int i=0;i<n;i++){
			
			cin>>a>>b>>c;
			if(c==0 && b==0 ){
				a1[k]=a;
				k++;
			}
			else{
				fb=false;
				fc=false;
			}
				
			if(a>=b) d[i]=a;
			else d[i]==b;
			if(c>d[i]) d[i]=c;
			sum+=d[i];
			
			//sa.push_back({a,b,c});
			sa[i]={a,b,c}; 
		}
		
		if(n==2){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(i!=j){
						int aa=sa[0][i]+sa[1][j];
						if(aa>ans) ans=aa;
					}
				}
			}
		}
		else{
			if(fb && fc) {
			
				sort(a1+0,a1+n+1);
				for(int i=n/2-1;i>=0;i--){
					ans+=a1[i];
				}
			}
			else ans=sum;
		}
		cout<<ans<<'\n';
		
	}
	
	return 0;
}