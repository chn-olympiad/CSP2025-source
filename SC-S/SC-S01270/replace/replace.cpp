#include<bits/stdc++.h>
using namespace std;
long long n,q,ans;
int check[1711][1711];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string fir,sec;
		cin>>fir>>sec;
		int j=0,fl=(int)fir.length(),sl=(int)sec.length();
		for(;;j++){
			if(fir[j]!=sec[j]){
				break;
			}
		}
		for(;;sl--,fl--){
			if(fir[fl]!=sec[sl]){
				break;
			}
		}
		long long fh=0,sh=0;
		for(int k=j;k<=fl;k++){
			fh+=fir[k];
		}
		for(int k=j;k<=sl;k++){
			sh+=sec[k];
		}
		check[fh%1711][sh%1711]++;
	}
	for(int i=0;i<q;i++){
		ans=0;
		string fir,sec;
		cin>>fir>>sec;
		int j=0,fl=(int)fir.length(),sl=(int)sec.length();
		for(;;j++){
			if(fir[j]!=sec[j]){
				break;
			}
		}
		for(;;sl--,fl--){
			if(fir[fl]!=sec[sl]){
				break;
			}
		}
		long long fh=0,sh=0;
		for(int k=j;k<=fl;k++){
			fh+=fir[k];
		}
		for(int k=j;k<=sl;k++){
			sh+=sec[k];
		}
		cout<<check[fh%1711][sh%1711]<<"\n";
	}
	return 0;
}