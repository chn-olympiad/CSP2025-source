#include<iostream>
#include<string>
using namespace std;
long long n,q,ans = 0;
string s[200100][2],s1,s2,s3,s4;
int main(){
	freopen("replace.in","w",stdin);
	freopen("replace.out","r",stdout);
	cin>>n>>q;
	long long i,j,k,o;
	for(i = 1;i <= n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(i = 1;i <= q;i++){
		cin>>s1>>s2;
		for(k = 1;k <= n;k++){	
			for(j = 0;j <= s1.size();j++){
				s4 = s1;
				s3 = s1.substr(j,s[k][1].size());
//				cout<<s3<<endl;
				if(s3 == s[k][1]){
					s3 = s[k][2];
				}
				s4.erase(j,s[k][2].size());
				s4.insert(j,s3);
//				cout<<s4<<endl;
				if(s4 == s2) ans++;
			}
		}
		cout<<ans<<endl;
		ans = 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb 
