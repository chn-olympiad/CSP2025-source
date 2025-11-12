//卜睿琛  SN-J00162 西安湖滨中学 
#include<bits/stdc++.h>
using namespace std;
string s;
int sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='1' && s[i]<='9'){
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
