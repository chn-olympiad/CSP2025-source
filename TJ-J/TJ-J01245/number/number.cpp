#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=0x3f3f3f3f3f;
int n;
bool flag=0;
int cnt_num[10];
string s;
int main(){
	//#Shang4Shan3Ruo6Shui4
	//don't forget to delete the '//' 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt_num[(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		//cout<<cnt_num[i]<<endl;
		for(int j=1;j<=cnt_num[i];j++){
			cout<<i;
			if(i>0) flag=1;
			if(i==0&&!flag){
				break;
			} 
		}
	}
	cout<<endl; 
	return 0;	
}
