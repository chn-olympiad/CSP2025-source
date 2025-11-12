#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int cnt;
int checknumber(string x,int y){
	while(y<x.size()){
			if(x[y]=='0'){
		a[0]++;
		y++;
	}else if(x[y]=='1'){
		a[1]++;
		y++;
	}else if(x[y]=='2'){
		a[2]++;
		y++;
	}else if(x[y]=='3'){
		a[3]++;
		y++;
	}else if(x[y]=='4'){
		a[4]++;
		y++;
	}else if(x[y]=='5'){
		a[5]++;
		y++;
	}else if(x[y]=='6'){
		a[6]++;
		y++;
	}else if(x[y]=='7'){
		a[7]++;
		y++;
	}else if(x[y]=='8'){
		a[8]++;
		y++;
	}else if(x[y]=='9'){
		a[9]++;
		y++;
	}else y++;
	}
	return 0;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    checknumber(s,0);
    for(int i=9;i>=0;i--){
    	int maxn=a[i];
        for(int j=1;j<=maxn;j++){
        	cout<<i;
		}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
