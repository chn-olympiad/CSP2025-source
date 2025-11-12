#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int mid=n/2,myd=0;
		vector<int> A(n);
		int a=0,b=0,c=0;
		bool pd=true;
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			int max_myd=max(x,max(z,y));
			int min_myd=min(x,min(z,y));
			int mid_myd=(x+y+z)-(max_myd+min_myd);
			if(max_myd==x){
				if(a<mid){
					a++;
					myd+=x;
					continue;
				}
				if(y==mid_myd){
					if(b<mid){
						b++;
						myd+=y;
						continue;
					}
					c++;
					myd+=z;
					continue;
				}
			}
			else if(max_myd==y){
				if(b<mid){
					b++;
					myd+=y;
					continue;
				}
				if(x==mid_myd){
					if(a<mid){
						a++;
						myd+=x;
						continue;
					}
					c++;
					myd+=z;
					continue;
				}
			}
			else if(max_myd==z){
				if(c<mid){
					c++;
					myd+=z;
					continue;
				}
				if(y==mid_myd){
					if(b<mid){
						b++;
						myd+=y;
						continue;
					}
					a++;
					myd+=x;
					continue;
				}
			}
		}
		cout<<myd<<'\n';
	}
	return 0;
}
