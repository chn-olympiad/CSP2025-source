#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0;
int a[10005][20010];

int main(){
	cin.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int ys=0,xt=0,bh=0;
	int yuanshen,xingtie,benghuai;
	for(int j=1;j<=t;j++){
		cin>>n;
		
		for(int g=1;g<=n;g++){//cout<<g<<"."<<endl;
		    int mihuyou=-10000;
		    //int ys=0,xt=0,bh=0;
			for(int i=1;i<=3;i++){
				int yuanshen=0,xingtie=0,benghuai=0;
				cin>>a[g][i];
				if(a[g][i]>=mihuyou){
					mihuyou=a[g][i];
					if(i==1)    yuanshen++;	  ys+=yuanshen;
					if(i==2)    xingtie++;    xt+=xingtie;
					if(i==3)    benghuai++;	  bh+=benghuai;
				}
				//cout<<yuanshen<<" "<<xingtie<<" "<<benghuai<<" "<<endl; 
			}
			//cout<<mihuyou<<"mihuyou"<<endl;
			//cout<<ys<<" "<<xt<<" "<<bh<<" "<<endl; 
			ans+=mihuyou;
		}
	cout<<ans<<endl;
	}
	return 0;
} 
//（拜托，一定要仔细阅读）
// DO NOT GIVE ME THE ZERO!!!! pleas... 
// I want to a Group S s' jiangzhuang
/*pleas don't give me 0 ........,I can give you many many money , Because I know 
€€￡ is very like monye.... just like my 510 RMB.......
*/ 