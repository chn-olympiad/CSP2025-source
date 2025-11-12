#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
 	int q=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='9'){
			a[q]=s[i]-'0';
			q++;
			continue;
		}else if(s[i]=='8'){
			a[q]=s[i]-'0';
			q++;
			continue;
		}else if(s[i]=='7'){
			a[q]=s[i]-'0';
			q++;
			continue;
		}else if(s[i]=='6'){
			a[q]=s[i]-'0';
			q++;
			continue;
		}else if(s[i]=='5'){
			a[q]=s[i]-'0';
			q++;
			continue;
		}else if(s[i]=='4'){
			a[q]=s[i]-'0';
			q++;
			continue;
		}else if(s[i]=='3'){
			a[q]=s[i]-'0';
			q++;
			continue;
		}else if(s[i]=='2'){
			a[q]=s[i]-'0';
			q++;
			continue;
		}else if(s[i]=='1'){
			a[q]=s[i]-'0';
			q++;
			continue;
		}else if(s[i]=='0'){
			a[q]=s[i]-'0';
			q++;
			continue;
		}
	}
	sort(a,a+q);
	for(int i=q-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}