#include<bits/stdc++.h>
using namespace std;
long long T;
int G[100010][3];
int N,Num,k1,k2,k3,K;
vector<int >A,B,C;
bool cmp(int b1,int b2){
	return G[b1][K]>G[b2][K];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		Num=0;k1=0;k2=0;k3=0,K=0;
		cin>>N;
		for(int i=0;i<A.size();i++){
			A[i]=0;
		}
		for(int i=0;i<B.size();i++){
			B[i]=0;
		}
		for(int i=0;i<C.size();i++){
			C[i]=0;
		}
		for(int i=0;i<N;i++){
			int a,b,c;
			cin>>a>>b>>c;
			G[i][0]=a,G[i][1]=b,G[i][2]=c;
			if(a>b&&a>c){
				k1++;
				Num+=a;
				A.push_back(i);
				continue;
			}
			if(b>c&&b>a){
				k2++;
				Num+=b;
				B.push_back(i);
				continue;
			}
			k3++;
			Num+=c;
			C.push_back(i);
		}
		if(k1<=N/2&&k2<=N/2&&k3<=N/2){
			cout<<Num<<endl;
			continue;
		}
		Num=0;
		if(k1>N/2){
			K=0;
			sort(A.begin(),A.end(),cmp);
			for(int i=0;i<N/2;i++){
				Num+=G[A[i]][K];
			}
			for(int i=N/2;i<=k1;i++){
				if(G[A[i]][1]>G[A[i]][2]){
					B.push_back(i);
					k2++;
				}else{
					C.push_back(i);
					k3++;
				}
			}
			for(int i=0;i<k2;i++){
				Num+=G[B[i]][1];
			}
			for(int i=0;i<k3;i++){
				Num+=G[C[i]][2];
			}
			cout<<Num<<endl;
			continue;
		}
		if(k2>N/2){
			K=1;
			sort(B.begin(),B.end(),cmp);
			for(int i=0;i<N/2;i++){
				Num+=G[B[i]][K];
			}
			for(int i=N/2;i<=k2;i++){
				if(G[B[i]][0]>G[B[i]][2]){
					A.push_back(i);
					k1++;
				}else{
					C.push_back(i);
					k3++;
				}
			}
			for(int i=0;i<k1;i++){
				Num+=G[A[i]][0];
			}
			for(int i=0;i<k3;i++){
				Num+=G[C[i]][2];
			}
			cout<<Num<<endl;
			continue;
		}
		if(k3>N/2){
			K=2;
			sort(C.begin(),C.end(),cmp);
			for(int i=0;i<N/2;i++){
				Num+=G[C[i]][K];
			}
			for(int i=N/2;i<=k3;i++){
				if(G[C[i]][0]>G[C[i]][1]){
					A.push_back(i);
					k1++;
				}else{
					B.push_back(i);
					k2++;
				}
			}
			for(int i=0;i<k1;i++){
				Num+=G[A[i]][0];
			}
			for(int i=0;i<k2;i++){
				Num+=G[B[i]][1];
			}
			cout<<Num<<endl;
			continue;
		}
	}
	return 0;
}
