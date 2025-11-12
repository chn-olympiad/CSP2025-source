#include <bits/stdc++.h>
using namespace std;
const int Maxn=100002;
int N=0;
int A[Maxn][3];
int Popu[3];
int Chs[Maxn];
void Readintest(void){
	scanf("%d",&N);
	for(int I=1;I<=N;++I){
		for(int J=0;J<=2;++J){
			scanf("%d",&A[I][J]);
		}
	}
	return ;
}
void Test(void){
	int Ans=0;
	Popu[0]=Popu[1]=Popu[2]=0;
	for(int I=1;I<=N;++I){
		int Maxofi=max(A[I][0],max(A[I][1],A[I][2]));
		for(int J=0;J<=2;++J){
			if(Maxofi==A[I][J]){
				++Popu[J];
				Chs[I]=J;
				Ans=Ans+A[I][J];
				break;
			}
		}
	}
	int Maxofpopu=max(Popu[0],max(Popu[1],Popu[2]));
	for(int I=0;I<=2;++I){
		if(Popu[I]==Maxofpopu){
			priority_queue<int>Pq;
			for(int J=1;J<=N;++J){
				if(Chs[J]==I){
					Pq.push(max(A[J][(I+1)%3],A[J][(I+2)%3])-A[J][I]);
				}
			}
			for(int J=Maxofpopu-N/2;J>=1;--J){
				Ans=Ans+Pq.top();
				Pq.pop();
			}
			break;
		}
	}
	printf("%d\n",Ans);
	return ;
}
int main(void){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		Readintest();
		Test();
	}
	return 0;
}
