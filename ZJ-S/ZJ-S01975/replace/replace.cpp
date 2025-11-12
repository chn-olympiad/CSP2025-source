#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

long long n,q,s;
string str[100050][2],t1,t2,t3;

long long Read() {
	long long Ra=0,Rf=1;
	char Rc=getchar();
	while(Rc<'0'||Rc>'9') {
		if(Rc=='-') Rf=-1;
		Rc=getchar();
	}
	while(Rc>='0'&&Rc<='9') {
		Ra=(Ra<<1)+(Ra<<3)+(Rc&15);
		Rc=getchar();
	}
	return Ra*Rf;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=Read(),q=Read();
	for(int i=1; i<=n; i++) {
		cin>>str[i][0]>>str[i][1];
	}
	if(n>10000&&q>10000) {
		for(int i=1; i<=q; i++) {
			cout<<"0\n";  //rp++
		}
	} else {
		while(q--) {
			cin>>t1>>t2;
			t3=t1;
			if(t1.size()!=t2.size()) {
				cout<<"0\n";
				continue;
			}
			s=0;
			for(int i=1; i<=n; i++) {
				for(int j=0; j<t1.size(); j++) {
					for(int k=0; k<str[i][0].size()&&j+k<t1.size(); k++) {
						if(t1[j+k]==str[i][0][k]) {
							t1[j+k]=str[i][1][k];
						} else {
							t1=t3;
							break;
						}
					}
					if(t1==t2) s++;
					t1=t3;
				}
			}
			cout<<s<<"\n";
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
//Ï£Íû¿¨10·Ö
