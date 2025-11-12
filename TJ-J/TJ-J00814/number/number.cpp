#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	vector<int> n(10,0);
	cin>>s;
	for(int i = 0; i < s.size(); i++){
		if(s[i]=='0'){
			n[0]++;
		}if(s[i]=='1'){
			n[1]++;
		}if(s[i]=='2'){
			n[2]++;
		}if(s[i]=='3'){
			n[3]++;
		}if(s[i]=='4'){
			n[4]++;
		}if(s[i]=='5'){
			n[5]++;
		}if(s[i]=='6'){
			n[6]++;
		}if(s[i]=='7'){
			n[7]++;
		}if(s[i]=='8'){
			n[8]++;
		}if(s[i]=='9'){
			n[9]++;
		}
	}
	/*for(int i = 0; i < num.size(); i++){
		for(int j = i; j < num.size(); j++){
			if(num[j]<num[i]){
				swap(num[i],num[j]);
			}
		}
	}*/
	for(int i= n.size()-1; i>=0;i--){
		for(int j = 0; j< n[i]; j++){
			cout<<i;
		}
	}
    return 0;
}




