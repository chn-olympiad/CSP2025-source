//高子懿 SN-S00791 延安市安塞区初级中学
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club6.in","r",stdin);
	freopen("club6.out","w",stdout);
	long long t,flag=0;
	vector<int> rs(3);
	vector<int> myd(3);
	vector<int> sz(3);
	rs[0]=0,rs[1]=0,rs[2]=0;
	cin>>t;
	while(t--){
		long long sum1=0,sum2=0,sum3=0;
		long long n;
		cin>>n;
		for(int j=1;j<=n;j++){
			int _1,_2,_3;
			cin>>_1>>_2>>_3;
			if(_1>_2 and _1>_3 and rs[0]<n/2){
				rs[0]++;
				sum1+=_1;
			}
			else if(_2>_1 and _2>_3 and rs[1]<n/2){
				rs[1]++;
				sum2+=_2;
			}
			else if(_3>_1 and _3>_2 and rs[2]<n/2){
				rs[2]++;
				sum3+=_3;
			}
		}
	myd[flag]=sum1+sum2+sum3;
	flag++;
	}
	for(int i=0;i<myd.size();i++){
		cout<<myd[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
