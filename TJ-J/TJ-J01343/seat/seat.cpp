#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector< vector<int> > map;
	for(int i=0;i<n;i++){
		vector<int> ls(m,-1);
		map.push_back(ls);
	}
	vector<int> s(n*m);
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	int R=s[0];
	sort(s.begin(),s.end());
	int l=0;
	for(int i=s.size()-1;i>=0;i--){
		for(int h=0;h<n;h++){
			map[h][l]=s[i];
			i--;
		}
		l++;
	}
	for(int i=0;i<n;i++){
		for(int k=0;k<m;k++){
			if(map[i][k]==R){
				cout<<k+1<<' '<<i+1;
				return 0;
			}
		}
	}
	return 0;
}
