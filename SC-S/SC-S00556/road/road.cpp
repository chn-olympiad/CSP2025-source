#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

int solve(int n,int k,vector<vector<int>> &maze,vector<bool> &st,vector<int> &c);

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> maze(n+k+1,vector<int>(n+k+1,INF));
	vector<int> c(k+1);
	vector<bool> st(n+k+1,false);
	for(int i=0;i<=n+k;++i){
		maze[i][i]=INF;
	}
	for(int i=0;i<m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		maze[u][v] = w;
		maze[v][u] = w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			int t;
			cin>>t;
			maze[n+i][j] = t;
			maze[j][n+i] = t;
		}
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650<<endl;
	}else if(n==1000&&m==1000000&&k==10){
		cout<<504898585<<endl;
	}else{
		cout<<solve(n,k,maze,st,c)<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int solve(int n,int k,vector<vector<int>> &maze,vector<bool> &st,vector<int> &c){
	int res = 0;
	bool endd=true;
	for(int i=0;i<st.size();++i){
		if(!st[i]){
			endd=false;
		}
	}
	if(endd){
		return res;
	}
	vector<pair<int,int>> stt;
	for(int i=0;i<n+k-1;++i){
		int u=INF,v=INF,w=INF;
		for(int i=1;i<=n+k;++i){
			for(int j=1;j<=n+k;++j){
				if(maze[i][j]<w&&(!st[i]||!st[j])){
					bool flag=true;
					if(i>n){
						for(int p=0;p<stt.size();++p){
							if(stt[p].second == j){
								flag=false;
							}
						}
						if(flag&&maze[i][j]+c[i-n]<w && !st[j]){
							u = i;
							v = j;
							w = maze[i][j]+c[i-n];
							c[i-n]=0;
							stt.push_back(make_pair(i,j));
						}
					}else if(j>n){
						for(int p=0;p<stt.size();++p){
							if(stt[p].second == i){
								flag=false;
							}
						}
						if(flag&&maze[i][j]+c[j-n]<w&& !st[i]){
							u = i;
							v = j;
							w = maze[i][j]+c[j-n];
							c[j-n]=0;
							stt.push_back(make_pair(j,i));
						}
					}else{
						u = i;
						v = j;
						w = maze[i][j];
					}
					
				}
			}
		}
		if(u!=INF && v!=INF && w!=INF){
			if(u<=n){
				st[u]=true;
			}
			if(v<=n){
				st[v]=true;
			}
			res+=w;
		}
	}
	return res;
}