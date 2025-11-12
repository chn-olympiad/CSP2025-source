//SN-J01073 郭逸凡 西安滨河学校 
#include<bits/stdc++.h>
using namespace std;
char a[100005];
bool cmp(int x,int y){
	return x>y;
}
bool re(char s){
	if(s=='0') return 1;
	else if(s=='1') return 1;
	else if(s=='2') return 1;
	else if(s=='3') return 1;
	else if(s=='4') return 1;
	else if(s=='5') return 1;
	else if(s=='6') return 1;
	else if(s=='7') return 1;
	else if(s=='8') return 1;
	else if(s=='9') return 1;
	else return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int f=0,len=s.size();
	for(int i=0;i<=len;i++){
		if(re(s[i])){
			a[f]=s[i];
			f++;
		}
	}
	sort(a,a+f,cmp);
	for(int i=0;i<f;i++){
		cout<<a[i];
	}
	return 0;
} 
