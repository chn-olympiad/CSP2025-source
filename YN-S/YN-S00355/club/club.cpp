#include <bits/stdc++.h>
using namespace std;

vector<int> A, B, C;
int AA, BB, CC;
int T;
int n;
long long ans;
int a, b, c;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		AA=BB=CC=0;
		A.clear();
		B.clear();
		C.clear();
		ans=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			if (a>=b)
				if (a>=c){
					ans+=a;
					AA++;
					A.push_back(min(a-b,a-c));
				}else{
					ans+=c;
					CC++;
					C.push_back(min(c-b,c-a));
				}else{
				if(b>=c){
					ans+=b;
					BB++;
					B.push_back(min(b-a,b-c));
				}else{
					ans+=c;
					CC++;
					C.push_back(min(c-b,c-a));
				}
			}
		}
		if(AA>n/2){
			sort(A.begin(),A.end());
			for (int i=0;i<AA-n/2;i++)ans-=A[i];
		}
		if(BB>n/2){
			sort(B.begin(),B.end());
			for (int i=0;i<BB-n/2;i++)ans-=B[i];
		}
		if(CC>n/2){
			sort(C.begin(),C.end());
			for (int i=0;i<CC-n/2;i++)ans-=C[i];
		}
		printf("%lld\n", ans);
	}

	return 0;
}
