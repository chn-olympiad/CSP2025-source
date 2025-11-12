#include<bits/stdc++.h>
using namespace std;
int a1[100005],a2[100005],a3[100005];
int num[100005];
int c[100005];
int n1,n2,n3;
vector<int> v;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin>> T;
	while(T--){
		v.clear();
		int n; scanf("%d",&n);
		n1 = 0; n2 = 0; n3 = 0;
		long long  ans = 0;
		for(int i = 1;i<=n;i++) scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		for(int i = 1;i<=n;i++){
			int x = a1[i];
			int y = a2[i];
			int z = a3[i];
			if(x>y && x>z){
				n1++; c[i] = 1;
				num[i] = x - max(y,z);
				ans += x;
			}
			else if(y>x && y>z){
				n2++; c[i] = 2;
				num[i] = y - max(x,z);
				ans += y;
			}
			else if(z>x && z>y){
				n3++; c[i] = 3;
				num[i] = z - max(x,y);
				ans += z;
			}
			else ans += max(max(x,y),max(y,z));
		}
		if(n1 > n/2 || n2 > n/2 || n3>n/2){
			int t,m;
			if(n1>n/2){
				m = n1 - n/2;
				t = 1;
			}if(n3>n/2){
				m = n3 - n/2;
				t = 3;
			}if(n2>n/2){
				m = n2 - n/2;
				t = 2;
			}
			for(int i = 1;i<=n;i++){
				if(c[i] == t){
					v.push_back(num[i]);
				}	
			}
			sort(v.begin(),v.end());
			for(int i = 0;i<m;i++) ans -= v[i];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
