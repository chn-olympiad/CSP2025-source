#include<bits/stdc++.h> 

using namespace std;

struct member{
	long long num[3],maxx;
};

long long t,n,x;
member l[100005];
long long k[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
			int q[3] = {0,0,0};
			for (int i = 1;i <= n;i++){
				cin >> l[i].num[0] >> l[i].num[1] >> l[i].num[2];
				if (l[i].num[0] >= l[i].num[1] and l[i].num[0] >= l[i].num[2]) {
					q[0]++;
					l[i].maxx = 0;
				}
				else if (l[i].num[1] >= l[i].num[0] and l[i].num[1]  >= l[i].num[2]){
					q[1]++;
					l[i].maxx=1;
				}
				else{
				q[2]++;
				l[i].maxx = 2;	
				}
			} 
			
			long long flag = 1,ans = 0,v = 0;
			//memset(k,0,sizeof(k));
			for (int i = 0;i < 3;i++){
				if (q[i] > n/2){
					x = i;
					flag = 0;
				}
				//cout << i << endl;
			}
			if (flag){
				for (int i = 1;i <= n;i++){
					ans += l[i].num[l[i].maxx];
				}
			}
			else{
				for (int i = 1;i <= n;i++){
					ans += l[i].num[l[i].maxx];
					if (l[i].maxx == x){
						long long maxx = 0;
						for (int j = 0;j < 3;j++){
							if (j != x){
								maxx = max(maxx,l[i].num[j]);
							}
						}
						k[v++] = l[i].num[x] - maxx;
					}
				}
				sort(k,k+v);
				for (int i = 0;i < q[x]-n/2;i++){
					ans -= k[i];
				}
			
			}
			
			cout << ans << endl;
	}
	return 0;
}
