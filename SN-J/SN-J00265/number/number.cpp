//SN-J00265 孙辰熙   曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
bool scx(char scxz,char scxb){
	return scxz>scxb;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string c;
	cin>>c;
	string k;
	for(int j=0;j<c.size();j++){
		if(c[j]>='0'&&c[j]<='9'){
		k.push_back(c[j]);
		}
	}
	sort(k.begin(),k.end(),scx);
	cout<<k<<endl;
	return 0;
}
