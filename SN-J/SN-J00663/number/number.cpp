//SN-J00663  樊思航  西安高新一中沣东中学初中校区
#include <fstream>
#include <cstring>
std::ifstream cin("number.in");
std::ofstream cout("number.out");
int a[15];
int main(){
	string s;
	int ans;
	cin>>s;
		for(int i=1;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i];
			a[x]++;
		}
		
	}
	
    for(int i=9;i>=0;i--){
    	for(int k=1;k<=a[i];k++){
    		ans=i+ans*10;
		}
    	
    	
	}
	
	cout<<ans;
	
	
	
	
	
	return 0;
}
 
