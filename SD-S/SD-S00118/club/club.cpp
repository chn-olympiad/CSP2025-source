#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
struct S{
	pair<int,int> a[4];
	int s;
};
bool cmp1(pair<int,int> a,pair<int,int> b){
	return a.second>b.second;
}
bool cmp2(pair<int,vector<S> > a,pair<int,vector<S> > b){
	return a.second.size()>b.second.size();
}
bool cmp3(S a,S b){
	return a.s<b.s;
}
int T,n;
S a[1000010];
pair<int,vector<S> > club[4];
int t[4];
int sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	club[1].first=1;
	club[2].first=2;
	club[3].first=3;
	cin>>T;
	while(T--){
		sum=0;
		club[1].second.resize(0);
		club[2].second.resize(0);
		club[3].second.resize(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a[1].second>>a[i].a[2].second>>a[i].a[3].second;
			a[i].a[1].first=1;
			a[i].a[2].first=2;
			a[i].a[3].first=3;
			
			sort(a[i].a+1,a[i].a+4,cmp1);
			a[i].s=a[i].a[1].second-a[i].a[2].second;
			club[a[i].a[1].first].second.push_back(a[i]);
			sum+=a[i].a[1].second;
		}
		sort(club+1,club+4,cmp2);
		if(club[1].second.size()>n/2){
			sort(club[1].second.begin(),club[1].second.end(),cmp3); 
			for(int i=0;i<club[1].second.size()-n/2;i++){
				sum-=club[1].second[i].s;
				//cout<<club[1].second.size()<<" ";
				club[1].second[i].s=club[1].second[i].a[2].second-club[1].second[i].a[3].second;
				
				if(club[2].first==club[1].second[i].a[2].first)club[2].second.push_back(club[1].second[i]);
				else club[3].second.push_back(club[1].second[i]);
			}
			if(club[2].second.size()<club[3].second.size()){
				swap(club[2],club[3]);
			}
			
			if(club[2].second.size()>n/2){
				sort(club[2].second.begin(),club[2].second.end(),cmp3);
				for(int i=0;i<club[2].second.size()-n/2;i++){
					sum-=club[2].second[i].s;
				}
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
