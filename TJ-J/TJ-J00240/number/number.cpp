#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int a[100006];
int biao[100006];
int t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;	
	if (s.size()==1 && s[0]>='0' && s[0]<='9'){
		cout << s[0];
		return 0;
	}
	for(int i=0;i<s.size();i++){	
		if(s[i]>='0' && s[i]<='9'){
			a[t]+=int(s[i]);
			biao[t]+=i;			
			t++;			
			
		}			
		
	}
	for (int i=0 ;i<sizeof(a);i++){
		int t=0;
		for(int j=1;j<=i;j++){
			if(a[j+1]>a[j]){
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
				t=biao[j+1];
				biao[j+1]=biao[j];
				biao[j]=t;
			}
		}
	}
	for(int i=1;i<=sizeof(biao);i++){
		cout  << s ;
	}
	
	
	return 0;
}
