#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e5+10;
int n,ans;
struct pr{
	int vi,p,id;
};
int f[N],t[i];
bool cmp(pr A,pr B){
	return A.vi > B.vi;
}
signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n; ans=0;
		vector<pr> v;
		int k[4]; 
		k[1]=k[2]=k[3]=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c; f[i] = 0; t[i]=1e9+10;
			pr t; 
			t.vi = a; t.id = 1; t.p = i;
			v.push_back(t);
			t.vi = b; t.id = 2; t.p = i;
			v.push_back(t);
			t.vi = c; t.id = 3; t.p = i;
			v.push_back(t);
		}
		sort(v.begin(),v.end(),cmp);
		for(auto it:v){
			if(f[it.p]){
				continue;
			}
			else{
				k[it.id]++;
				ans+=it.vi;
				f[it.p]=it.id;
			}
		}
		
		for(auto it:v){
			if(f[it.p]){
				if(f[it.p] == it.p){
					t[i] = it.vi;
				}
				if(f[it.p] != it.id){
					t[i] = it.vi;
					k[it.id]--;
					for(int i=1;i<=n;i++){
						
					}
				}
			}
		}
		
		
//			if(f[it.p]){
////				printf("%lld %lld %lld\n",it.vi,it.p,it.id);
////				if(f[it.p]) cout<<"y\n";
////				else cout<<"n\n"<<it.id<<'\n';
//				continue;
//			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
