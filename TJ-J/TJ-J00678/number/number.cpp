#include<bits/stdc++.h>
using namespace std;
string str;
int t[100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch>='0' && ch<='9'){
            int c=ch-'0';
            t[c]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(t[i]>0){
	        for(int j=1;j<=t[i];j++){
	            cout<<i;
	        }	
		}
        
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}//#Shang4Shan3Ruo6Shui4
