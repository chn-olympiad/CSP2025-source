#include<bits/stdc++.h>
#define ll long long
#define mian main
#define ull unsigned long long
#define itn int
#define T true
#define F false
using namespace std;//#Shang4Shan3Ruo6Shui4
const int N=110000;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,part1[N],part2[N],part3[N];
	
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>part1[i]>>part2[i]>>part3[i];
		}
	}
	//-------------------------------------------------
	int maxn=n/2,sum=0,ma=0;//special1 compare with ma
	for(int i=1;i<=maxn;++i){
		for(int j=1;j<=n;++j){
			if(part1[j]>=ma){
				ma=part1[j];
				part1[j]=0;
			}
		}
		sum+=ma;
		ma=0;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
