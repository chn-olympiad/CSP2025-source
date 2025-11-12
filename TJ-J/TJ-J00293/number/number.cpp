//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int tong[N],a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int sum=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			tong[sum++]=s[i]-'0';
		}
	}
	//for(int i=0;i<=sum;i++) cout<<tong[i];
	//cout<<endl;
	for(int i=0;i<=sum;i++){
		for(int j=i;j<=sum;j++){
			if(tong[i]<tong[j]){
				swap(tong[i],tong[j]);
			}
		}
	}
	for(int i=0;i<sum;i++) cout<<tong[i];
	return 0;
} 
