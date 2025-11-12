#include<bits/stdc++.h>

using namespace std;

int n,T;
string s1,s2,t1,t2;

int main(){
	
	cin>>n>>T;
	if(n == 1){
		cin>>s1>>s2;
		int lens = s1.size();
		while(T--){
			bool flag = true;
			cin>>t1>>t2;
			int lent = t1.size();
			int cntt = -1;
			int cnts = -1;
			for(int i=0;i<lent;i++){
				if(t1[i] != t2[i]){
					cntt = i;
					for (int j=0;j<lens;j++){
						if (s1[j]==t1[i] && s2[j] == t2[j]){
							cnts = j;
							break;
						}
					}
					break;
				}
			}
			if(cnts!=-1 && cntt!=-1){
				for(int i=cntt;i<cntt+lens-cnts;i++){
					if(t1[i]!=s1[i-cntt+cnts] || t2[i]!=s2[i-cntt+cnts]){
						flag = false;
					}
				}
				if(flag){
					cout<<1<<endl;
				}
				else{
					cout<<0<<endl;
				}
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	else{
		return 0;
	}
	
	return 0;
} 
