//SN-J01091 阮书凡 安康中学教育集团初中部
#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	vector<short> v;
	string ch;
	cin>>ch;
	for(int i=0;i<ch.size();i++){
		if('0'<=ch[i]&&ch[i]<='9'){
			v.push_back(ch[i]-'0');
		}
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
    	cout<<v[i];
	}
	return 0;
}
