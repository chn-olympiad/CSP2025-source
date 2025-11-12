#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10; 
string line;
int num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>line;
	int len=0;
	for(int i=0;i<line.size();i++)
		if(line[i]>='0'&&line[i]<='9')
			num[++len]=line[i]-'0';
	sort(num+1,num+1+len);
	bool flag=true;
	for(int i=1;i<=len;i++){
		if(num[i]!=0){
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=len;i>=1;i--)
		cout<<num[i];
	return 0;
}
