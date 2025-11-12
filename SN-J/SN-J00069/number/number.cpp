#include<bits/stdc++.h>
using namespace std;

string s;
int t[20],a;//落魄谷中寒风吹，春秋蝉鸣少年归 

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'){
			t[0]++;
			a++;
		}
		else if(s[i]=='1'){//求AC 
			t[1]++;
			a++;
		}
		else if(s[i]=='2'){//求AC 
			t[2]++;
			a++;
		}
		else if(s[i]=='3'){//求AC 
			t[3]++;
			a++;
		}
		else if(s[i]=='4'){//求AC 
			t[4]++;
			a++;
		}
		else if(s[i]=='5'){//求AC 
			t[5]++;
			a++;
		}
		else if(s[i]=='6'){//求AC 
			t[6]++;
			a++;
		}
		else if(s[i]=='7'){//求AC 
			t[7]++;
			a++;
		}
		else if(s[i]=='8'){//求AC 
			t[8]++;
			a++;
		}
		else if(s[i]=='9'){//求AC 
			t[9]++;
			a++;
		}
	}
	for(int i=10;i>=0;i--){//求AC 
		for(int j=t[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}















