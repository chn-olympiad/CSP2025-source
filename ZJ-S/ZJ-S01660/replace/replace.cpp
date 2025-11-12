#include <bits/stdc++.h>
using namespace std;

int n,q;
string s[200005][3];
string t[200005][3];

long long ans=0;

string quick_read(){
	string p="";
	while (1){
		char c=getchar();
		if (c!=' ' && c!='\n'){
			p+=c;
			break;
		}
	}
	while (1){
		char c=getchar();
		if (c!=' ' && c!='\n'){
			p+=c;
		}
		else{
			break;
		}
	}
	return p;
}


int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	
	for (int i=1;i<=n;i++){
		s[i][1]=quick_read(); 
		s[i][2]=quick_read(); 
	}
	
	for (int j=1;j<=q;j++){
		ans=0;
		t[j][1]=quick_read(); 
		t[j][2]=quick_read(); 
		for (int cut=0;cut<=t[j][1].size();cut++){
			string x=t[j][1].substr(0,cut);
			for (int rep=1;rep<=n;rep++){
				if (cut+s[rep][1].size()<=t[j][1].size()){
					string y=t[j][1].substr(cut,s[rep][1].size());
					string z=t[j][1].substr(cut+s[rep][1].size(),t[j][1].size()-cut-s[rep][1].size());
					if (y==s[rep][1] && x+s[rep][2]+z==t[j][2]){
						ans+=1;
					}
				}
			}
		}
		
		
		printf("%lld\n",ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
