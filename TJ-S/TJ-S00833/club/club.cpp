#include<bits/stdc++.h>
using namespace std;


bool cmp1(vector<int> x, vector<int> y){
	return x[1]>y[1];
}
bool cmp2(int x, int y){
	return x<y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int t1 = 0; t1<t; t1++){
		int n;
		cin>>n;
		vector<vector<vector<int> > > graph;
		for(int i = 0; i<n; i++){
			vector<vector<int> >temp(3,vector<int> (2, 0));
			cin>>temp[0][1]>>temp[1][1]>>temp[2][1];
			temp[0][0] = 1;
			temp[1][0] = 2;
			temp[2][0] = 3;
			sort(temp.begin(),temp.end(),cmp1);
			temp[1][1] = temp[0][1]-temp[1][1];
			temp[2][1] = temp[0][1]-temp[2][1];
			graph.push_back(temp);
		}

		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		long long ans = 0;
		for(int i = 0; i<n; i++){
			if(graph[i][0][0] == 1){
				count1++;
			}else if(graph[i][0][0] == 2){
				count2++;
			}else if(graph[i][0][0] == 3){
				count3++;
			}
			ans+=graph[i][0][1];
		}

		vector<int> comp;
		if(count1>(n/2)){
			for(int i = 0; i<n; i++){
				if(graph[i][0][0] == 1){
					comp.push_back(graph[i][1][1]);
				}
			}
			sort(comp.begin(),comp.end(),cmp2);
			for(int i = 0; i<count1-(n/2);i++){
				ans-=comp[i];
			}
		}else if(count2>(n/2)){
			for(int i = 0; i<n; i++){
				if(graph[i][0][0] == 2){
					comp.push_back(graph[i][1][1]);
				}
			}
			sort(comp.begin(),comp.end(),cmp2);
			for(int i = 0; i<count2-(n/2);i++){
				ans-=comp[i];
			}
		}else if(count3>(n/2)){
			for(int i = 0; i<n; i++){
				if(graph[i][0][0] == 3){
					comp.push_back(graph[i][1][1]);
				}
			}
			sort(comp.begin(),comp.end(),cmp2);
			for(int i = 0; i<count3-(n/2);i++){
				ans-=comp[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
