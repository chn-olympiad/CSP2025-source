#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string c;
	string d;
	cin>>s;
	int j = 0;
	int k = 0;
	for(int i = 0;i<s.size();i++){
		if(s[i] == 1){
			c[j] = s[i];
			j++;
		}
		else if(s[i] == 2){
			c[j] = s[i];
			j++;
		}
		else if(s[i] == 3){
			c[j] = s[i];
			j++;
		}
		else if(s[i] == 4){
			c[j] = s[i];
			j++;		
		}
		else if(s[i] == 5){
			c[j] = s[i];
			j++;
		}
		else if(s[i] == 6){
			c[j] = s[i];
			j++;
		}
		else if(s[i] == 7){
			c[j] = s[i];
			j++;
		}
		else if(s[i] == 8){
			c[j] = s[i];
			j++;
		}
		else if(s[i] == 9){
			c[j] = s[i];
			j++;
		}
		else if(s[i] == 0){
			d[k] = s[i];
			k++;
		}
	}
		for(int a = 0;a<c.size();a++){
		for(int b = 0;b<c.size()-1;b++){
			if(c[b]>c[b+1]){
				char h= c[b];
				c[b] = c[b+1];
				c[b+1] = h;
				
			}
				
		}
	}
	cout<<c<<d;
	fclose(stdin);
	fclose(stdout);
	return 0 ;
}

