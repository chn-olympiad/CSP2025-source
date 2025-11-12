#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	string ans="";
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			ans+=a[i];
		}
	}
	n=ans.size();
	string c="";
	int m=n;
	int num=-1;
    while(n--){
    	char temp;
    	int num=-1;
    	int flag;
    	for(int i=0;i<m;i++){
    		if(num<ans[i]-'0'&&ans[i]!=' '){
    		    num=ans[i]-'0';
                temp=ans[i];
                flag=i;
			}
		}
		ans[flag]=' ';
		c+=temp;
    }
    cout<<c;
	return 0;
} 
