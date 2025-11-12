#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[514],tmp[514],ton[514]={},num=0,numn=0,ne=0,numf=0;
char s[514];
bool check(){
	num=0;
	for(int i=1;i<=n;i++){
//		cout<<tmp[i];
		if(s[i]=='0'){
//			cout<<"se=0"<<endl;
			ne++;
			continue;
		}
		if(ne>=tmp[i]){
//			cout<<"ne>tmp"<<endl;
			ne++;
			continue;
		}
		num++;
	}
//	cout<<endl;
	if(num<m){
//		cout<<"num="<<num<<endl;
		return false;
	}else{
		return true;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.ans","w",stdout);
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ton[a[i]]++;
//		cout<<"ton[a[i]]="<<ton[a[i]]<<endl;
	}
//	cout<<"afi"<<endl;
	int pla=1;
	for(int i=0;i<=n;i++){
//		cout<<"fo1,i="<<i<<endl;
		if(ton[i]>0){
//			cout<<"ton>0,ton[i]="<<ton[i]<<endl;
			int x=ton[i];
			while(x>0){
				tmp[pla]=i;
				pla++;
				x--;
			}
//			numn%=998244353;
			numn++;
		}
	}
//	cout<<"afn,numn="<<numn<<endl;
	int sett=numn;
	while(sett>1){
		sett--;
//		numn%=998244353;
		numn*=sett;
	}
//	cout<<"numn="<<numn<<endl;
	pla=n;
	int x=1;
	for(int i=1;i<=numn;i++){
//		cout<<"fo2,i="<<i<<endl;
		if(check()){
//			for(int k=1;k<=n;k++){
//				cout<<tmp[k];
//			}
//			cout<<endl;
			numf%=998244353;
			numf++;
		}
		swap(tmp[pla],tmp[pla-x+1]);
		if(x==pla){
			pla--;
			x=1;
		}
		swap(tmp[pla],tmp[pla-x]);
		x++;
	}
//	cout<<"numf="<<numf<<endl;
	for(int i=1;i<=n;i++){
		if(ton[i]>0){
			numf=numf*ton[i]%998244353;
		}
	}
	cout<<numf%998244353;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19
*/
/*
LEX666
RP++
*/
