//SN-J00458 戴思诚 西安市曲江第一学校
#include<bits/stdc++.h>
using namespace std;
string s;
long long cd,jl[110]={},c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	cd=s.size();
	for(int i=0;i<cd;i++){
		if(s[i]=='0'){
			jl[0]++;
			c++;
		}
		else if(s[i]=='1'){
			jl[1]++;
			c++;
		}
		else if(s[i]=='2'){
			jl[2]++;
			c++;
		}
		else if(s[i]=='3'){
			jl[3]++;
			c++;
		}
		else if(s[i]=='4'){
			jl[4]++;
			c++;
		}
		else if(s[i]=='5'){
			jl[5]++;
			c++;
		}
		else if(s[i]=='6'){
			jl[6]++;
			c++;
		}
		else if(s[i]=='7'){
			jl[7]++;
			c++;
		}
		else if(s[i]=='8'){
			jl[8]++;
			c++;
		}
		else if(s[i]=='9'){
			jl[9]++;
			c++;
		}}
	for(int i=9;i>=0;i--){
		if(jl[i]!=0){
			for(int j=jl[i];j>0;j--){
				cout<<i;
			}
		}
	}
	return 0;
} 
