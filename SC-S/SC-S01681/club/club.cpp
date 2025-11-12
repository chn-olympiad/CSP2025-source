#include<bits/stdc++.h>
using namespace std;
struct Man{
	int a1,a2,a3;
}M[100001],A[50001],B[50001],C[50001];
int la,lb,lc;
void Push(Man x,char y){
	if(y=='a'){
		A[la++]=x;
	}else if(y=='b'){
		B[lb++]=x;
	}else{
		C[lc++]=x;
	}
}
bool comp1(Man &a,Man &b){
	return (a.a1-max(a.a2,a.a3))>(b.a1-max(b.a2,b.a3));
}
bool comp2(Man &a,Man &b){
	return (a.a2-max(a.a1,a.a3))>(b.a2-max(b.a1,b.a3));
}
bool comp3(Man &a,Man &b){
	return (a.a3-max(a.a2,a.a1))>(b.a3-max(b.a2,b.a1));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,i,j,v,mv,sum=0;char V,MV;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;la=0;lb=0;lc=0;sum=0;
		memset(M,0,sizeof(M));
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));
		for(j=0;j<n;j++){
			cin>>M[j].a1>>M[j].a2>>M[j].a3;
			if(M[j].a1 >= M[j].a2 && M[j].a1 >= M[j].a3){
				if(la < n/2){
					Push(M[j],'a');
				}else{
					sort(A,A+la,comp1);
					if(A[la-1].a2>=A[la-1].a3){
						V='b';v=A[la-1].a2;
					}else{
						V='c';v=A[la-1].a3;
					}
					if(M[j].a2>=M[j].a3){
						MV='b';mv=M[j].a2;
					}else{
						MV='c';mv=M[j].a3;
					}
					if(M[j].a1+v >= A[la-1].a1+mv){
						Push(A[la-1],V);
						A[la-1]=M[j];
					}else{
						Push(M[j],MV);
					}
				}
			}else if(M[j].a2 >= M[j].a1 && M[j].a2 >= M[j].a3){
				if(lb < n/2){
					Push(M[j],'b');
				}else{
					sort(B,B+lb,comp2);
					if(B[lb-1].a1>=B[lb-1].a3){
						V='a';v=B[lb-1].a1;
					}else{
						V='c';v=B[lb-1].a3;
					}
					if(M[j].a1>=M[j].a3){
						MV='a';mv=M[j].a1;
					}else{
						MV='c';mv=M[j].a3;
					}
					if(M[j].a2+v >= A[la-1].a2+mv){
						Push(B[lb-1],V);
						B[lb-1]=M[j];
					}else{
						Push(M[j],MV);
					}
				}
			}else{
				if(lc < n/2){
					Push(M[j],'c');
				}else{
					sort(C,C+lc,comp3);
					if(C[lc-1].a1>=C[lc-1].a2){
						V='a';v=C[lc-1].a1;
					}else{
						V='b';v=C[lc-1].a2;
					}
					if(M[j].a1>=M[j].a2){
						MV='a';mv=M[j].a1;
					}else{
						MV='b';mv=M[j].a2;
					}
					if(M[j].a3+v >= A[la-1].a3+mv){
						Push(C[lc-1],V);
						C[lc-1]=M[j];
					}else{
						Push(M[j],MV);
					}
				}
			}
		}
		for(j=0;j<la;j++){
			sum+=A[j].a1;
		}
		for(j=0;j<lb;j++){
			sum+=B[j].a2;
		}
		for(j=0;j<lc;j++){
			sum+=C[j].a3;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}