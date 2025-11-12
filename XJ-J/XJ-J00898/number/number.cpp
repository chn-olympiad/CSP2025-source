#include <iostream>
using namespace std;
const int N=1e6+5;
long long times[10];	//¼ÆÊýÍ° 
char s[N]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<sizeof s;i++){
		if(s[i]>='0'&&s[i]<='9'){
			times[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=times[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
