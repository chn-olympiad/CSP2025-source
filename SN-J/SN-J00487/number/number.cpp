//西安经开第五学校
//朱梓豪
//SN-J00487 
#include<bits/stdc++.h>
using namespace std;
string s,s1;
int cc;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='9'){
			s1+=s[i];
			cc++;
		}
		else if(s[i]=='8'){
			s1+=s[i];
			cc++;
		}
		else if(s[i]=='7'){
			s1+=s[i];
			cc++;
		}
		else if(s[i]=='6'){
			s1+=s[i];
			cc++;
		}
		else if(s[i]=='5'){
			s1+=s[i];
			cc++;
		}
		else if(s[i]=='4'){
			s1+=s[i];
			cc++;
		}
		else if(s[i]=='3'){
			s1+=s[i];
			cc++;
		}
		else if(s[i]=='2'){
			s1+=s[i];
			cc++;
		}
		else if(s[i]=='1'){
			s1+=s[i];
			cc++;
		}
		else if(s[i]=='0'){
			s1+=s[i];
			cc++;
		}	
	}
	for(int i=0;i<cc;i++){
		for(int j=i;j<cc;j++){
			if(s1[i]<s1[j]){
				swap(s1[i],s1[j]);
			}
		}
		
	}
	cout<<s1;
	return 0;
} 
