#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;
string s;
long long ans,numlst[N],cont;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			numlst[cont++]=s[i]-'0';
		}
	}
	sort(numlst,numlst+cont);
	for(int i=cont-1;i>=0;i--){
		cout<<numlst[i];
	}
	fclose(stdin);
	fclose(stdout);
}
