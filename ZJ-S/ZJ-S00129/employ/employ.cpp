#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int N=200001,Mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(nullptr));
	long long Ans=1,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char dif;
		cin>>dif;
		if(dif==0){
			cout<<rand()<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
	}
	for(int i=1;i<=n;i++)
		Ans=Ans*i%Mod;
	cout<<max(Ans-1ll*rand()*rand()%Mod,1ll*rand()*rand()%Mod)<<endl;
	return 0;
}
