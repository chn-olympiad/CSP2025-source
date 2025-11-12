#include<bits/stdc++.h>
using namespace std;
int T,N,book1=1;
deque<int>Q1,Q2,Q3;
int A[100100],B[100100],C[100100],E[100100],F[100100],G[100100];
long long Num;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int xa=0,xb=0,xc=0;
		cin>>N;
		Num=0;
		book1=1;
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));
		for(int i=1;i<=N;i++){
			cin>>A[i]>>B[i]>>C[i];
			if(B[i]!=0||C[i]!=0)book1=0;
			if(A[i]>=B[i]&&A[i]>=C[i])E[i]=1;
			else if(B[i]>=A[i]&&B[i]>=C[i])E[i]=2;
			else E[i]=3;
			if(A[i]<=B[i]&&A[i]<=C[i])F[i]=1;
			else if(B[i]<=A[i]&&B[i]<=C[i])F[i]=2;
			else F[i]=3;
			if(F[i]!=1||E[i] !=1)G[i]=1;
			if(E[i]!=2||F[i] !=2)G[i]=2;
			else G[i] =3;
		}
		if(book1==1){
			sort(A+1,A+N+1);
			for(int i=N/2+1;i<=N;i++){
				Num+=A[i];		
			}
			cout<<Num<<endl;
		}
	}
	return 0;
}
