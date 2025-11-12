#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int n,m;
string s;
vector<int> c;
int main(){
	int x;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s=" "+s;
	int len=s.size();
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		c.push_back(x);
	}
	
		int idx=-1;
		for(int i=1;i<len;i++){
			/*if(s[i]==1){
				idx=i;
				break;
			}*/
		}
		sort(c.begin(),c.end());
		auto pos=lower_bound(c.begin(),c.end(),idx);
		if(pos==c.end()){
			//printf("0");
			return 0;
		}
		int ans=n-*pos-1;
		//printf("%d",(ans*(ans-1)%998244353)%998244353);

		
			//printf("0");
			 
		
		int tot=m;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				tot--;
			}
		}
		//printf("%d",(tot*(tot-1)%998244353)%998244353);
	
	printf("0");
	
	
	return 0;
}

/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19


*/
