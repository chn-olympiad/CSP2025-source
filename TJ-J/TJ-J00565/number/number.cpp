#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string str;
long long zero=1,ans,sum,flag=-1,m=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){	
			if(int(str[i]-48)==0){
				m++;
			}else{
				flag++;
				zero*=10;
				ans+=int(str[i]-48)*zero/10;
			}
		}
	}
	sum+=ans;
	for(int i=9;i>=0;i--){
		while(sum!=0){
			if(sum%10==i){
				cout<<sum%10;
			}
			sum/=10;
		}
		sum+=ans;
	}
	for(int i=0;i<m;i++){
		cout<<0;
	}
	return 0;
}
//baoyouyibianguo
//#Shang4Shan3Ruo6Shui4
