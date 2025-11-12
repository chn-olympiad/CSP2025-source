//考号：SN-J01165；姓名：马晨越； 学校：陕西延安中学 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ans=0,sum=0;
	ans=s.size();
	vector<int> v(ans);
	for(int i=0;i<ans;i++){		
		if(s[i]=='1'|| s[i]=='2' || s[i]=='3'|| s[i]=='4'|| s[i]=='5'|| s[i]=='6'|| s[i]=='7'|| s[i]=='8'|| s[i]=='9'|| s[i]=='0'){			
			sort(s.begin(),s.end(),greater<int>());
			cout<<s[i];
		}
				
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
