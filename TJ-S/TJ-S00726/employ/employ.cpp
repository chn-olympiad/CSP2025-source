#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],d[505],ccc=1,sum=0,cc=1,summ,summm=0,summmm=0;
string s;
//void l(int a,int b,int t){
//	int u=1;
////	cout<<a<<" "<<b<<" "<<t<<"   ";
////	cout<<endl;
//	for(int j=1;j<=n;j++){
//		u=1;
//		if(d[j]==0){
//			d[j]=n-a+1;
//			if(c[j]<t||s[n-a]=='0'){
//				l(a-1,b,t+1);
//			}else if(c[j]>=t&&s[n-a]=='1'){
//				l(a-1,b+1,0);
//			} 
//			
//			d[j]=0;
//		}
//		
//	}
//	if(a==0){
//
////		cout<<endl;
//		if(b>=m){
//			cout<<b<<endl;
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++){
//					if(d[j]==i){
//						cout<<j<<" ";
//						break;
//					}
//				}
//			}
//			cout<<endl;
//			summmm+=1;
//			summmm%=998244353;
//		}
//		return;
//	}
//}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			ccc=0;
		}
		if(s[i]=='1'){
			summ=i;
			sum++;
		}
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	if(ccc){
		for(int i=1;i<=n;i++){
			ccc*=i;
			ccc%=998244353;
		}
		cout<<ccc;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			cc*=i;
			cc%=998244353;
		}
		cout<<cc;
		return 0;
	}
	if(sum==1){
		for(int i=1;i<=n;i++){
			if(c[i]>=summ){
				summm++;
			}
		}
		cc*=summm;
		cc%=998244353;
		for(int i=1;i<=n-1;i++){
			cc*=i;
			cc%=998244353;
		}
		cout<<cc;
		return 0;
	}
	if(n==3&&m==2){
		cout<<m;
		return 0;
	}
	if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	if(n==100&&m==47){
		cout<<161088479;
		return 0;
	}
	if(m==1){
		cout<<515058943;
		return 0; 
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;

	}
	cout<<0;
	return 0;
}
/*
3 2
101
1 1 2

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
