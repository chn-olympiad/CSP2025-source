#include<fstream>
//#include<iostream>
#include<algorithm>
using namespace std;
ifstream cin("club.in");
ofstream cout("club.out");

//注意换行问题
//Warn:Last Enter! ok
int cmp(int i,int j) {
	return i>j;
}
int main() {
	int NOUSE;
	cin>>NOUSE;
	bool ENT=true;
	for(; NOUSE>0; NOUSE--) {
		if(ENT) ENT=false;
		else cout<<"\n";
		int n;
		cin>>n;
		int I[n],II[n],III[n];

		bool A=false,B=false,C=false;
		bool fA=false,fB=false,fC=false;
		for(int i=0; i<n; i++) {
			cin>>I[i]>>II[i]>>III[i];
			if(I[i]==0) {
				A=true;
			}
			if(II[i]==0) {
				B=true;
			}
			if(III[i]==0) {
				C=true;
			}
			if(I[i]!=0) {
				fA=true;
			}
			if(II[i]!=0) {
				fB=true;
			}
			if(III[i]!=0) {
				fC=true;
			}
			
		}
		//B is subset of A//type A
		if(A && B && !fA && !fB) {
			sort(III,III+n,cmp);
			int summ=0;
			for(int i=0; i<n/2; i++) {
				summ+=III[i];
			}
			cout<<summ;
			continue;
		} else if(A && C && !fA && !fB) {
			sort(II,II+n,cmp);
			int summ=0;
			for(int i=0; i<n/2; i++) {
				summ+=II[i];
			}
			cout<<summ;
			continue;
		} else if(C && B && !fC && !fB) {
			sort(I,I+n,cmp);
			int summ=0;
			for(int i=0; i<n/2; i++) {
				summ+=I[i];
			}
			cout<<summ;
			continue;
		} else if(n==2) {
			int q=I[0]+II[1],
			    w=I[0]+III[1],
			    e=I[1]+II[0],
			    r=I[1]+III[0],
			    t=II[0]+III[1],
			    y=II[1]+III[0];
			cout<<max(q,max(w,max(e,max(r,max(t,y)))));
		} else if(n==4) {
			int I01=I[0]+I[1],
			    II01=II[0]+II[1],
			    III01=III[0]+III[1],
			    I02=I[0]+I[2],
			    II02=II[0]+II[2],
			    III02=III[0]+III[2],
			    I03=I[0]+I[3],
			    II03=II[0]+II[3],
			    III03=III[0]+III[3],
			    I12=I[1]+I[2],
			    II12=II[1]+II[2],
			    III12=III[1]+III[2],
			    I13=I[1]+I[3],
			    II13=II[1]+II[3],
			    III13=III[1]+III[3],
			    I23=I[2]+I[3],
			    II23=II[2]+II[3],
			    III23=III[2]+III[3];
			int q=I01+II[2]+III[3],
			    w=I01+II[3]+III[2],
			    e=I[2]+II01+III[3],
			    r=I[2]+II[3]+III01,
			    t=I[3]+II01+III[2],
			    y=I[3]+II[2]+III01,

			    u=I12+II[0]+III[3],
			    i=I12+II[3]+III[0],
			    o=I[3]+II12+III[0],
			    p=I[3]+II[0]+III12,
			    a=I[0]+II12+III[3],
			    s=I[0]+II[3]+III12,

			    d=I23+II[0]+III[1],
			    f=I23+II[1]+III[0],
			    g=I[0]+II23+III[1],
			    h=I[0]+II[1]+III23,
			    j=I[1]+II23+III[0],
			    k=I[1]+II[0]+III23,

			    l=I02+II[1]+III[3],
			    z=I02+II[3]+III[1],
			    x=I[3]+II02+III[1],
			    c=I[3]+II[1]+III02,
			    v=I[1]+II02+III[3],
			    b=I[1]+II[3]+III02,

			    QP=I03+II[1]+III[2],
			    m=I03+II[2]+III[1],
			    Q=I[2]+II03+III[1],
			    W=I[2]+II[1]+III03,
			    E=I[1]+II03+III[2],
			    R=I[1]+II[2]+III03,

			    T=I13+II[0]+III[2],
			    Y=I13+II[2]+III[0],
			    U=I[2]+II13+III[0],
			    QR=I[2]+II[0]+III13,
			    O=I[0]+II13+III[2],
			    P=I[0]+II[2]+III13,

			    A=I01+II23,
			    S=I01+III23,
			    D=II01+I23,
			    F=II01+III23,
			    G=III01+I23,
			    H=III01+II23,

			    J=I02+II13,
			    K=I02+III13,
			    L=II02+I13,
			    Z=II02+III13,
			    X=III02+II13,
			    C=III02+I13,

			    V=I03+II12,
			    B=I03+III12,
			    N=II03+I12,
			    M=II03+III12,
			    QW=III03+II12,
			    QE=III03+I12;
			cout<<max(q,max(w,max(e,max(r,max(t,max(y,max(u,max(i,max(o,max(p,max(a,max(s,max(d,max(f,max(f,max(g,max(h,max(j,max(k,max(l,max(z,max(x,max(c,max(v,max(b,max(QP,max(m,max(Q,max(W,max(E,max(R,max(T,max(Y,max(U,max(QR,max(O,max(P,max(A,max(S,max(D,max(F,max(F,max(G,max(H,max(J,max(K,max(L,max(Z,max(X,max(C,max(V,max(B,max(N,max(M,max(QW,QE)))))))))))))))))))))))))))))))))))))))))))))))))))))));

		}
	}
	cin.close();
	cout.close();
	return 0;
}
