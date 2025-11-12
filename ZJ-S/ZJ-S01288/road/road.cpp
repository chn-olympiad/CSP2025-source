#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie();
	int n,m,k;
	long long ans=100000000000000;
	cin>>n>>m>>k;
	vector<vector<long long> > mp(n+1+k,vector<long long>(n+1+k,INT_MAX));
	for(int i=0;i<m;i++){
		int dj;
		int a,b;
		cin>>a>>b>>dj;
		mp[b-1][a-1]=dj;
		mp[a-1][b-1]=dj;
	}
	
	vector<int>cun(n+k+1,0);

	for(int i=0;i<k;i++){
		int ka;
		cin>>ka;
		cun[n+i]=ka;
		for(int ii=0;ii<n;ii++){
			int d;
			cin>>d;
			mp[i+n][ii]=d+ka;
			mp[ii][i+n]=d+ka;
		}
		
	}
	vector<long long>quanz(n+1+k,-1);

	
		vector<int>ud(n+k+1,0);
		vector<int>kai;
		quanz[0]=-1;
		kai.push_back(0);
		long long anss=0;
		while(kai.size()!=0){
			
			int head=kai[0];
			
			for(int i=0;i<n+k;i++){
				if(head>=n && ud[head]!=0){
					mp[head][i]-=cun[head];
				}
				if(mp[head][i]!=INT_MAX && (mp[head][i]<quanz[i] || quanz[i]==-1) ){
					kai.push_back(i);
				
					quanz[i]=mp[head][i];
					if(head>=n && ud[head]==0){
						cout<<head<<endl;
						ud[head]++;
					}
					
				}
				
			}
			kai.erase(kai.begin());
		
		}

		for(int i=0;i<n;i++){
			if(quanz[i]!=-1){
				ans+=quanz[i];
			}
		}
		cout<<ans<<endl;
	}
	

