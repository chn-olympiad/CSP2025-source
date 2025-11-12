#include<bits/stdc++.h>
#define double long double 
#define int long long 
#define re0 return 0;
#define exf exit(0);
#define mod 10000007
#define N 100010
using namespace std;
int n,T,nxtn,ST;
struct Club{
	int c1,c2,c3,dt;
}ap[N];
bool cmp1(Club A,Club B){return A.c1>B.c1;}
bool cmp2(Club A,Club B){return A.c2>B.c2;}
bool cmp3(Club A,Club B){return A.c3>B.c3;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		nxtn=n/2;
		for(int i=1;i<=n;i++){
			cin>>ap[i].c1>>ap[i].c2>>ap[i].c3;
		}	
		int max1=0,max2=0,max3=0,s,t=1;
		stable_sort(ap+1,ap+1+n,cmp1);
		for(int i=1;i<=nxtn;i++){max1+=ap[i].c1;}
		stable_sort(ap+1,ap+1+n,cmp2);
		for(int i=1;i<=nxtn;i++){max2+=ap[i].c2;}
		if(max1<max2) max1=max2,t=2;
		stable_sort(ap+1,ap+1+n,cmp3);
		for(int i=1;i<=nxtn;i++){max2+=ap[i].c3;}
		if(max1<max3) max1=max3,t=3;
		if(t==1){
			stable_sort(ap+1,ap+1+n,cmp1);
			for(int i=nxtn+1;i<=n;i++){max1+=(ap[i].c2<ap[i].c3?ap[i].c3:ap[i].c2);}}	
		if(t==2){
			stable_sort(ap+1,ap+1+n,cmp2);
			for(int i=nxtn+1;i<=n;i++){max1+=(ap[i].c1<ap[i].c3?ap[i].c3:ap[i].c1);}}	
		if(t==3){
			stable_sort(ap+1,ap+1+n,cmp3);
			for(int i=nxtn+1;i<=n;i++){max1+=(ap[i].c2<ap[i].c1?ap[i].c1:ap[i].c2);}}	
		cout<<max1<<'\n';
		continue;
	}
	re0;
}
/*
AFO

1
2
10 9 8
4 0 0

*/
