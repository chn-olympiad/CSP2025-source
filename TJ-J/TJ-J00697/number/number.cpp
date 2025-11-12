#include<bits/stdc++.h>;
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！     
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我风堇0+1不歪！！！ 
//CCF祝我风堇0+1不歪！！！
//CCF祝我风堇0+1不歪！！！
//CCF祝我风堇0+1不歪！！！
//CCF祝我风堇0+1不歪！！！
//CCF祝我风堇0+1不歪！！！
//CCF祝我记忆战舰不歪！！！
//CCF祝我记忆战舰不歪！！！
//CCF祝我记忆战舰不歪！！！
//CCF祝我记忆战舰不歪！！！
//CCF祝我记忆战舰不歪！！！
//昔门永存！ 
//昔门永存！
//昔门永存！
//昔门永存！
//爱门永存！
//爱门永存！
//爱门永存！
//爱门永存！
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::string s;
	std::vector<int> a;
	std::cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a.push_back(s[i]-'0');
		}
	} 
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--){
		std::cout<<a[i]<<"\n";
	}
	return 0;
}
