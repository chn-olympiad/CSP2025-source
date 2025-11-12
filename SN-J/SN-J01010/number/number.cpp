//SN-J01010,ZHAOWEIZE,25.11.1;
#include<bits/stdc++.h>
using namespace std;
int shu[10000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0),cout.tie(0);
	string x; 
	cin>>x;
	int num=x.length();
	int cnt=1;
	for(int i=0;i<num;i++){
		if(x[i]<='9'&&x[i]>='0'){
			shu[cnt]=x[i]-'0';
			cnt++;
		}
	}
	sort(shu+1,shu+cnt,cmp);
	for(int i=1;i<cnt;i++){
		cout<<shu[i];
	}
	//555,xia ku le
	return 0;
} 
