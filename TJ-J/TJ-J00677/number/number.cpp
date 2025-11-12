#include<bits/stdc++.h>
using namespace std;
long long num[10005];
string st;
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long im=1;
	cin>>st;
	long long len=sizeof(st);
	for(int i=0;i<len;i++){
        if(st[i]>='0'&&st[i]<='9'){
            num[im]=st[i]-48;
            im++;
        }
	}
	sort(num+1,num+1+im,cmp);
	for(int i=1;i<im;i++){
        cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
