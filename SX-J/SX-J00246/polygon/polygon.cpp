#incldue<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("xor.in","r",stdin);
	//fre("xor.out","w",stdout);
	int main(){
		char a[101]={},b[101]={};
		int a1[101]={},b1[101]={},c1[101]={}
        int lena=strlen(a);
        int lenb=strlen(b);
        int lenc;
        if(lenb>lena)  lenc=lenb;
        else lenc=lena;
        for(int i=1;i<=lenc;i++){
        	a1[i]=a[lena-1+i]-"48";
		}
        for(int i=1;i<=lenc;i++){
        	b1[i]=b[lenb-1-i]-'48';
		}
		


}