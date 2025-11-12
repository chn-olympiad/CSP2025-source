#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,n,m,ans;
string s;
int aa[505],bb[505];
//祭天初一(10)班全体（尤其是我周围那几个)十年阳寿，换我S组AK！ 
void dfs(int aa,int x,int y,int xx,int yy){
	if(aa>a){
		if(y>=b){
			ans++;
			cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<" ";
		}
		return; 
	}
	if(x>=bb[aa]){
		dfs(aa+1,x+1,y,xx,yy);
	}else{
		if(xx>=1)dfs(aa+1,x+1,y,xx-1,yy);
		if(yy>=1)dfs(aa+1,x,y+1,xx,yy-1);
	}
	
	
}
int levelcheng(int x){
	int y=1;
	while(x){
		y*=x;
		x--;
	}
	return y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')c++;
		else{
			d++;
		}
	}
	for(int i=1;i<=a;i++){
		cin>>bb[i];
	}
	if(c==0)cout<<n;
	else if(b>d)cout<<0;
	else{
		cout<<levelcheng(n);
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
