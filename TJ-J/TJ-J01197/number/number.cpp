#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
        string s;
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            a[s[i]-'0']++;
        }
    }int f=0;
    for(int i=9;i>=0;i--){
    	if(a[i]!=0 and i!=0){
    		f=1;
		}
        for(int j=a[i];j>0;j--){
        	if(f==0 and i==0){
        		cout<<0;
        		break;
			}
        	cout<<i;
    }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
