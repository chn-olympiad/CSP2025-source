#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000000];
int j=0,empty,k=0;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=10000;i++){
		if(s[i]=='1'){
			 a[j]=s[i];
			j++;
		}
		else if(s[i]=='2'){
			a[j]=s[i];
			j++;
		}
		else if(s[i]<='3'){
			a[j]=s[i];
			j++;
		}
		else if(s[i]=='4'){
			a[j]=s[i];
			j++;
		}
		else if(s[i]=='5'){
			a[j]=s[i];
			j++;
		}
		else if(s[i]=='6'){
			a[j]=s[i];
			j++;
		}
		else if(s[i]=='7'){
			a[j]=s[i];
			j++;
		}
		else if(s[i]=='8'){
			a[j]=s[i];
			j++;
		}
		else if(s[i]=='9'){
			a[j]=s[i];
			j++;
		}
		else
			break;

	}
	for(int i=0;i<1;i++)
		set<char>(a);
	cout<<a[0];
	while(++k){
		
		cout<<a[k];
		if(a[k]==empty)
		    break;
	}
	//fclose(stdout);
	//fclose(stdin);
	return 0;
}
