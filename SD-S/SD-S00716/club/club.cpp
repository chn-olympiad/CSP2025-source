#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
using namespace std;
struct node{
	int a,b,c,cha;
}A[110000];
int cmp1(node x,node y){
	return x.a > y.a;
}
int cmp2(node x,node y){
	return x.cha > y.cha;
}
long long sum,maxx = 0,n,ida,idb,idc,f1,f2,f3,maxid;
void q(long long l){
	if(l == n + 1){
		maxx = max(maxx,sum);
		return ;
	}
	if(ida >= maxid) f1 = 1;
	else f1 = 0;
	if(idb >= maxid) f2 = 1;
	else f2 = 0;
	if(idc >= maxid) f3 = 1;
	else f3 = 0;
	if(f1 != 1){
		sum += A[l].a;//cout<<"A "<<sum<<" "<<l<<endl;
		ida++;
		l++;
		q(l);
		l--;
		ida--;
		sum -= A[l].a;
	}
	if(f2 != 1){
		sum += A[l].b;//cout<<"B "<<sum<<" "<<l<<endl;
		idb++;
		l++;
		q(l);
		l--;
		idb--;
		sum -= A[l].b;		
	}
	if(f3 != 1){
		sum += A[l].c;//cout<<"C "<<sum<<" "<<l<<endl;
		idc++;
		l++;
		q(l);
		l--;
		idc--;
		sum -= A[l].c;
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T,m,i,j,o,maxid,maxx=0,flag1=0,flag2=0,sum=0,ida1=0,idb1=0;
	cin>>T;
	while(T--){
		cin>>n;
		maxid = n / 2;
		for(i = 1 ; i <= n ; i++){
			cin>>A[i].a>>A[i].b>>A[i].c;
			if(A[i].b != 0) flag1 = 1;
			if(A[i].c != 0) flag2 = 1;
		}
		if(n == 2){
			long long s1,s2;
			for(i = 1 ; i <= 3 ; i++){
				if(i == 1) s1 = A[1].a;
				if(i == 2) s1 = A[1].b;
				if(i == 3) s1 = A[1].c;
				for(j = 1 ; j <= 3 ; j++){
					if(i == j)continue;
					if(j == 1) s2 = A[2].a;
			    	if(j == 2) s2 = A[2].b;
			    	if(j == 3) s2 = A[2].c;
			    	maxx = max(s1 + s2,maxx);
				}
			}
			cout<<maxx<<endl;
		}
		if(flag1 == 0 && flag2 == 0){
			sort(A + 1 , A + 1 + n , cmp1);
			for(i = 1 ; i <= maxid ; i++){
				sum += A[i].a;
			}
			cout<<sum<<endl;
		}
		if(flag2 == 0){
			for(i = 1 ; i <= n ; i++){
				A[i].cha = max(A[i].a,A[i].b) - min(A[i].a,A[i].b);
			}
			sort(A + 1 , A + 1 + n,cmp2);
			for(i = 1 ; i <= n ; i++){
				if(A[i].a > A[i].b && ida1 < maxid){
					sum += A[i].a;
					ida1++;
				}
				else if(A[i].a < A[i].b && idb1 < maxid){
					sum += A[i].b;
					idb1++;
				}
				else if(ida1 == maxid) sum += A[i].b;
				else if(idb1 == maxid) sum += A[i].a;
			//	cout<<sum<<endl;
			}
			cout<<sum<<endl;
		}
		else{
			q(1);
			cout<<maxx<<endl;
		}
	}
//  while(T--){
//		cin>>n;
//		aa=1;bb=1;cc=1;
//		maxx=0;
//		maxid = n / 2;
//		for(i = 1 ; i <= n ; i++){
//			cin>>N[i].a>>N[i].b>>N[i].c;
//			A[i]=N[i].a;
//			B[i]=N[i].b;
//			C[i]=N[i].c;
//		}
//		q();
//		sort(A+1,A+1+n,cmp);
//		sort(B+1,B+1+n,cmp);
//		sort(C+1,C+1+n,cmp);
//		dp[0][0][0]=0;
//		for(i=0;i<=maxid;i++){
//			for(j=0;j<=maxid;j++){
//				if(i+j>n) break;
//				for(o=0;o<=maxid;o++){
//					if(i+j+o>n) break;
//					if(j==0&&o==0)dp[i][j][o]=dp[i-1][j][o]+A[i];
//					else if(o==0) dp[i][j][o]=dp[i][j-1][o]+B[j];
//					else dp[i][j][o]=dp[i][j][o-1]+C[o];
//					maxx=max(maxx,dp[i][j][o]);
//				}
//			}
//		}
//		cout<<maxx<<endl;
//	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

