#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

bool cmp(const tuple<int,int,int> &a,const tuple<int,int,int> &b);

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<tuple<int,int,int>> a(n);
		for(int i=0;i<n;++i){
			cin>>get<0>(a[i])>>get<1>(a[i])>>get<2>(a[i]);
		}
		bool flag=true;
		for(int i=0;i<n;++i){
			if(get<1>(a[i])!=0 || get<2>(a[i])!=0){
				flag=false;
			}
		}
		if(flag){
			sort(a.begin(),a.end(),cmp);
			int res=0;
			for(int i=0;i<n/2;++i){
				res+=get<0>(a[i]);
			}
			cout<<res<<endl;
		}else{
			vector<int> temp;
			for(int i=0;i<n;++i){
				temp.push_back(get<0>(a[i]));
				temp.push_back(get<1>(a[i]));
				temp.push_back(get<2>(a[i]));
			}
			sort(temp.begin(),temp.end(),greater<>());
			int res=0;
			for(int i=0;i<n/3;++i){
				res+=temp[i];
			}
			cout<<res<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

bool cmp(const tuple<int,int,int> &a,const tuple<int,int,int> &b){
	return get<0>(a)>get<0>(b);
}

