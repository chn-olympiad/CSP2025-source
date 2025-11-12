#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+3;
int n,k,ans;
struct In{
	int IN_[20];
	int num;
	bool ISUSE=false;
}a[maxn];
void GetIn(int num,int id){
	int Inpow[20]={524288,262144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};
	for(int i=19;i>=0;i--) if(num>=Inpow[i]) num-=Inpow[i],a[id].IN_[i]=1;else a[id].IN_[i]=0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;GetIn(k,0);
	for(int i=1;i<=n;i++) cin>>a[i].num,GetIn(a[i].num,i);
	if(k==0){
		for(int i=1;i<n;){
			if(a[i].num==a[i+1].num) ans++,a[i].ISUSE=true,a[i+1].ISUSE=true,i+=2;
			else if(a[i].num==0) ans++,a[i].ISUSE=true,i++;
			else i++;
		}
		cout<<ans;
	}
	return 0;
}