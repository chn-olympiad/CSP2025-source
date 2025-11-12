#include<bits/stdc++.h>
using namespace std;

long long  T,N;
long long ANS;
long long ANS1;
long long maxnum;
long long A[200010],B[200010],C[200010];
struct Node{
	int size;
	long long num;
};
Node DP[200010][4];
long long ANS2;
long long CountA,CountB,CountC;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		ANS=0;
		maxnum=N/2;
		for(int i=1;i<=N;i++){
			cin>>A[i]>>B[i]>>C[i];
			CountA+=A[i];
			CountB+=B[i];
			CountC+=C[i];
		}
		if(CountB==0&&CountC==0){
			sort(A+1,A+N+1,cmp);
			for(int i=1;i<=maxnum;i++){
				ANS+=A[i];
			}
			cout<<ANS<<endl;
		}
		else{
			for(int i=1;i<=N;i++){
				ANS+=max(A[i],max(B[i],C[i]));
			}		
			cout<<ANS<<endl;
		}
		
	}
}
