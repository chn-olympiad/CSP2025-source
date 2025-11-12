#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int sum;
const int N=1e5+10;
int af[N];//fist
int as[N];//second
int at[N];//third
int main(){
	//Don't forget freopen!!!
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		sum=0; 
		n=0;
		memset(af,0,sizeof(af));
		memset(as,0,sizeof(as));
		memset(at,0,sizeof(at));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>af[i]>>as[i]>>at[i];
		}
		int qq=n;
		int q=1;
		int qqq;
		for(int i=1;i<n;i++){
			q=1;
			while(q<=qq){
				if(af[q]<af[q+1]){
					qqq=af[q];
					af[q]=af[q+1];
					af[q+1]=qqq;
				}
				q++;
			}
			qq--;
		}
		for(int i=1;i<=n/2;i++){
			sum+=af[i];
		}
		cout<<sum<<endl;
	}
	return 0;
} 
//Just 7199.
