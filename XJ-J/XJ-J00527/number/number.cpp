#include<bits/stdc++.h>
using namespace std;
string s;
/*char c[1000005],f[1000005];
int i,j=1,d=1;*/
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=s.length();
	if(t==1)cout<<s;
	else if(t==2){
		if(int(s[1])>=48&&int(s[1])<=57&&int(s[2])>=48&&int(s[2])<=57){
			if(int(s[1])>int(s[2])){
				cout<<s[1]<<s[2];
			}
			else{
				cout<<s[2]<<s[1];
			}
		}
		else if(int(s[1])>=48&&int(s[1])<=57){
			cout<<s[1];
		}
		else{
			cout<<s[2];
		}
	} 
	else if(t==3){
		if(int(s[1])>=48&&int(s[1])<=57&&int(s[2])>=48&&int(s[2])<=57&&int(s[3])>=48&&int(s[3])<=57){
			if(int(s[1])>int(s[2])&&int(s[1])>int(s[3])&&int(s[2])>int(s[3])){
				cout<<s[1]<<s[2]<<s[3];
			}
			else if(int(s[1])<int(s[2])&&int(s[1])<int(s[3])&&int(s[2])<int(s[3])){
				cout<<s[3]<<s[2]<<s[1];
			}
			else if(int(s[1])>int(s[2])&&int(s[1])>int(s[3])&&int(s[2])<int(s[3])){
				cout<<s[1]<<s[3]<<s[2];
			}
			else if(int(s[1])<int(s[2])&&int(s[1])<int(s[3])&&int(s[2])>int(s[3])){
				cout<<s[2]<<s[3]<<s[1];
			}
			else if(int(s[1])>int(s[2])&&int(s[1])<int(s[3])&&int(s[2])<int(s[3])){
				cout<<s[3]<<s[1]<<s[2];
			}
			else if(int(s[1])<int(s[2])&&int(s[1])>int(s[3])&&int(s[2])>int(s[3])){
				cout<<s[2]<<s[1]<<s[3];
			}
		}
		else if(int(s[1])>=48&&int(s[1])<=57&&int(s[2])>=48&&int(s[2])<=57){
			if(int(s[1])>int(s[2])){
				cout<<s[1]<<s[2];
			}
			else{
				cout<<s[2]<<s[1];
			}
		}
		else if(int(s[1])>=48&&int(s[1])<=57&&int(s[3])>=48&&int(s[3])<=57){
			if(int(s[1])>int(s[3])){
				cout<<s[1]<<s[3];
			}
			else{
				cout<<s[3]<<s[1];
			}
		}
		else if(int(s[3])>=48&&int(s[3])<=57&&int(s[2])>=48&&int(s[2])<=57){
			if(int(s[2])>int(s[3])){
				cout<<s[2]<<s[3];
			}
			else{
				cout<<s[3]<<s[2];
			}
		}
		else if(int(s[3])>=48&&int(s[3])<=57){
			cout<<s[3];
		}
		else if(int(s[2])>=48&&int(s[2])<=57){
			cout<<s[2];
		}
		else{
			cout<<s[3];
		}
	} 
	return 0;
}
	/*getline(cin,s);
	for(i=1;i<=s.length();i++){
	if(int(s[i])>=48&&int(s[i])<=57){
		c[d]=s[i];
		d++;	
		}                	
	}
	char max='9';
	int t=d;
	while(d!=0){
		if(c[d]==max){
			f[j]=c[d];
			j++;
			d--;
		}
		if(d==0){
			max=char(int(max)-1);
			d=t;
		}
		else if(max=='0'||d==j){
			break;
		}
	}
	for(int z=1;z<=j;z++){
		cout<<f[z];
	}*/
