#include<bits/stdc++.h>
using namespace std;
string sss;
const int MMM=1e6+2;
int aaa[MMM];
long long lll;
bool cmp(int x,int y){
	return  x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>sss;
	for(int i=0;i<sss.size();i++){
		if(sss[i]>='0' && sss[i]<='9') {
			aaa[lll]=sss[i]-'0';
			lll++;
		}  
	}
	int llltt=lll;
	sort(aaa,aaa+lll,cmp);
	for(int i=0;i<llltt;i++){
		cout<<aaa[i];
	}
	return 0;
}//#Shang4Shan3Ruo6Shui4 
