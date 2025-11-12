#include<iostream>
#include<algorithm>
using namespace std;
const int N=400001;
int A[N],B[N],C[N],Id[N];
bool cmp(int i,int j){
	int S[5]={0,A[i],B[i],C[i]};
	int T[5]={0,A[j],B[j],C[j]};
	if(S[1]<S[2])swap(S[1],S[2]);
	if(S[2]<S[3])swap(S[2],S[3]);
	if(S[1]<S[2])swap(S[1],S[2]);
	if(T[1]<T[2])swap(T[1],T[2]);
	if(T[2]<T[3])swap(T[2],T[3]);
	if(T[1]<T[2])swap(T[1],T[2]);
	return S[3]-S[2]>T[3]-T[2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,CntA=0,CntB=0,CntC=0,Ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>A[i]>>B[i]>>C[i],Id[i]=i;
		sort(Id+1,Id+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(A[Id[i]]>=B[Id[i]]&&A[Id[i]]>=C[Id[i]])
				if(CntA<n/2)	CntA++,Ans+=A[Id[i]];
				else if((B[Id[i]]>C[Id[i]]&&CntB<n/2))
					CntB++,Ans+=B[Id[i]];
				else	CntC++,Ans+=C[Id[i]];
			else if(B[Id[i]]>=A[Id[i]]&&B[Id[i]]>=C[Id[i]])
				if(CntB<n/2)	CntB++,Ans+=B[Id[i]];
				else if((A[Id[i]]>C[Id[i]]&&CntA<n/2))
					CntA++,Ans+=A[Id[i]];
				else	CntC++,Ans+=C[Id[i]];
			else if(C[Id[i]]>=B[Id[i]]&&C[Id[i]]>=A[Id[i]])
				if(CntC<n/2)	CntC++,Ans+=C[Id[i]];
				else if((B[Id[i]]>A[Id[i]]&&CntB<n/2))
					CntB++,Ans+=B[Id[i]];
				else	CntA++,Ans+=A[Id[i]];
		}
		cout<<Ans<<endl;
	}
	return 0;
}
