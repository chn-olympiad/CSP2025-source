#include<bits/stdc++.h>
#define ei else if
#define ll long long
#define pend cout<<endl
//alert to the problem of ambigiousness
using namespace std;




string s;
//counting sort
int counting[10];//index to 0-9

int main(){
	
	
	freopen("number.in","r",stdin);//input
	
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'){
			counting[0]++;
		}
		if(s[i]=='1'){
			counting[1]++;
		}
		if(s[i]=='2'){
			counting[2]++;
		}
		if(s[i]=='3'){
			counting[3]++;
		}
		if(s[i]=='4'){
			counting[4]++;
		}
		if(s[i]=='5'){
			counting[5]++;
		}
		if(s[i]=='6'){
			counting[6]++;
		}
		if(s[i]=='7'){
			counting[7]++;
		}
		if(s[i]=='8'){
			counting[8]++;
		}
		if(s[i]=='9'){
			counting[9]++;
		}
		
	}
	freopen("number.out","w",stdout);//output
	for(int i=9;i>=0;i--){
		for(int j=1;j<=counting[i];j++){
			cout<<i;
		}
	}
	
	return 0;
}
