#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	string s;
	int ss[100000];
	int cc=0;
	cin>>s;
	for(int cf=0;cf<=s.size();cf++){
        if(s[cf]=='0'){
            ss[cc]=0;
            cc++;
        }
        if(s[cf]=='1'){
            ss[cc]=1;
            cc++;
        }
        else if(s[cf]=='2'){
            ss[cc]=2;
            cc++;
        }
        else if(s[cf]=='3'){
            ss[cc]=3;
            cc++;
        }
        else if(s[cf]=='4'){
            ss[cc]=4;
            cc++;
        }
        else if(s[cf]=='5'){
            ss[cc]=5;
            cc++;
        }
        else if(s[cf]=='6'){
            ss[cc]=6;
            cc++;
        }
        else if(s[cf]=='7'){
            ss[cc]=7;
            cc++;
        }
        else if(s[cf]=='8'){
            ss[cc]=8;
            cc++;
        }
        else if(s[cf]=='9'){
            ss[cc]=9;
            cc++;
        }

	}
	sort(ss,ss+cc+1);
	for(int cf=cc;cf!=0;cf--){
        cout<<ss[cf];
	}
fclose(stdin);
fclose(stdout);
	return 0;
}
