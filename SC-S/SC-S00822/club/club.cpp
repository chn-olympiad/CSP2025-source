#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans = 0;
		cin>>n;
		vector<int> A(n);
		vector<int> B(n);
		vector<int> C(n);
		for (int i = 0;i < n;i++){
			cin>>A[i]>>B[i]>>C[i];
		}
		int a = 0,b = 0,c = 0;
		for (int i = 0;i < n;i++){
			int x = max(A[i],max(B[i],C[i]));

			if (A[i] == x){
				a++;
				ans += A[i];
				if (a > n / 2){
					a--;
					ans -= A[i];
					x = max(B[i],C[i]);
					if (B[i] == x && b + 1 <= n / 2){
						b++;
						ans += B[i];
					}else{
						c++;
						ans += C[i];
					}
				}
			}else if (B[i] == x){
				b++;
				ans += B[i];
				if (b > n / 2){
					b--;
					ans -= B[i];
					x = max(A[i],C[i]);
					if (A[i] == x && a + 1 <= n / 2){
						a++;
						ans += A[i];
					}else{
						c++;
						ans += C[i];
					}
				}
			}else if (C[i] == x){
				c++;
				ans += C[i];
				if (c > n / 2){
					c--;
					ans -= C[i];
					x = max(A[i],B[i]);
					if (A[i] == x && a + 1 <= n / 2){
						a++;
						ans += A[i];
					}else{
						b++;
						ans += B[i];
					}
				}
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}