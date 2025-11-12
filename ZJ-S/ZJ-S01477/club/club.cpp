#include <bits/stdc++.h>
using namespace std;
#define Ll long long
#define Max3(a,b,c) max(max(a,b),c)
#define Min3(a,b,c) min(min(a,b),c)
const int NN=1e5+5;
int T,N;
Ll A[NN][5],Dt[NN],S[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		S[0]=S[1]=S[2]=0;
		Ll Ans=0;
		for(int I=1;I<=N;I++){
			cin>>A[I][0]>>A[I][1]>>A[I][2];
			A[I][3]=Max3(A[I][0],A[I][1],A[I][2]),Ans+=A[I][3];
			Dt[I]=0x3f3f3f3f3f3f3f3f;
			for(int J=0;J<3;J++)
				if(A[I][J]==A[I][3]){
					++S[J],A[I][4]=J;
					for(int K=0;K<3;K++)
						if(K!=J)
							Dt[I]=min(Dt[I],A[I][3]-A[I][K]);
					break;
				}
		}
		for(int I=0;I<3;I++)
			if(S[I]>N/2){
				vector<Ll> X;
				X.clear();
				for(int J=1;J<=N;J++)
					if(A[J][4]==I)
						X.push_back(Dt[J]);
				sort(X.begin(),X.end());
				for(int J=0;J<S[I]-N/2;J++) Ans-=X[J];
				break;
			}
		cout<<Ans<<'\n';
	}
	return 0;
}

