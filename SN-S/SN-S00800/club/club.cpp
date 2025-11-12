#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,maxx,ans=0;
		vector<int> v;
		cin>>n;
		for(int j=0;j<n;i++){
			for(int z=0;z<3;z++){
				cin>>v[z];
			}
			maxx=max(v[0],v[1]);
			maxx=max(maxx,v[2]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
