#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T,n,a,b,c,d,ans;
int A[N],B[N],C[N];
bool flag = true;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		d = n;
		while(d--){
			cin >> a >> b >> c;
			A[n-d] = a;
			B[n-d] = b;
			C[n-d] = c;
			if(b!=0||c!=0){
				flag=false;
			}
		}
		if(flag){ 
		sort(A+1,A+1+n);
		for(int i=1;i<=n/2;i++){
			ans+=A[i]; 
		}
		} else {
			for(int i=1;i<=n;i++)ans+=max(A[i],max(B[i],C[i]));
		}
		cout << ans << "\n";
	}
	return 0;
}