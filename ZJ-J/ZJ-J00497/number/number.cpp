#include<bits/stdc++.h>

using namespace std;

vector<char> v;

bool cmp(char a,char b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen("number3.in","r",stdin);
//	freopen("ans.out","w",stdout);
	
	string num;
	
	cin>>num;
	
	int len=num.size();
	
//	cout<<len<<endl;
	bool fla=0;
	
	for(int i=0;i<len;i++){
		
		char ch=num[i];
		
		if(ch>='0'&&ch<='9'){//是数字 
			
			v.push_back(ch);
			if(ch!='0') fla=1;
			
		}
		
	}	
	
	if(fla!=1){
		cout<<0<<endl;
		fclose(stdin);
		fclose(stdout);
		
		return 0;
	}
	
	sort(v.begin(),v.end(),cmp);//排序
	
//	while(v.size()>1&&v[0]=='0') v.erase(v.begin()); //去除前导零
	
	for(auto i:v) cout<<i; //输出
	
	cout<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0; 
}

/*
T1 10分钟切掉了

大样例也过了 ，时间复杂度:O(N)

应该能过吧 
*/
