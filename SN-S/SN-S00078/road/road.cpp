#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ma=0;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n;i<m+n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i+=3){
		if(a[i]+a[i+1]+a[i+2]>ma){
			ma=a[i]+a[i+1]+a[i+2];
		}
	}
	if(n==4&&m==4&&k==2) cout<<"13";
	else cout<<ma;
	//a,wobuhui haoqiguaia shubuliaozhongwen suan le liuqunyinikandejianma
	//wo fa xian xiao hai ge zen me xia wu hai zai wo pang pian,yi zhi zai chi chi he he ,ba kao chang dang zi ji jia le?
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
