#include<bits/stdc++.h>
using namespace std;
# define For(i,a,b) for(int i=a; i<=b; i++)
int P[10203];
int a[16542][5];
int num[5];
int n,S;
int ans=0;
void loop(int m) {

	if(m==n+1) {
		num[1]=0;
		num[2]=0;
		num[3]=0;
		For(i,1,n) {
			++num[P[i]];
		}
		if(num[1]>n/2||num[2]>n/2||num[3]>n/2) {
			return;
		}
		S=0;
		For(i,1,n) {
			S+=a[i][P[i]];
			
		}
		ans=max(ans,S);
		//cerr<<S<<' ';
		return;
	}
	For(i,1,3) {
		P[m]=i;
		loop(m+1);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--) {
		ans=0;
		cin>>n;
		For(i,1,n) {
			For(j,1,3) {
				cin>>a[i][j];
			}
		}
		loop(1);
		cout<<ans<<'\n';
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}



