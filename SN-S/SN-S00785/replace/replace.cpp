#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string qq[2];
struct p{
	string sa,sb;
};
map<int,string> n1;
map<string,int> np1;
map<int,string> n2;
map<string,int> np2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;//²»µ½ 
	for(int i=0;i<n;i++){
		cin>>n1[i];
		cin>>n2[i];
		np1[n1[i]]=i;
		np2[n2[i]]=i;
	}
	int cnt=0,cc=0;//°¥Ó´ ÎÒÈ¥µnØn·j½j»j¹jÊjÇjÀjëj¿jªjµjÄjËjÅj·jşjµjçj»jújÊjÇj·jñº£¿ÚÊĞÊÖ¶¯·§¿ª¸ö·¿¿ªÊ¼¹Å¿Æ¼¼Ê¦·¶ 
	string a,b;
	for(int i=0;i<q;i++){//±©Á¦ 
		cin>>qq[1]>>qq[2];
		for(int j=0;j<qq[1].size();j++){
			for(int k=0;k<j;k++){
				for(int l=j;l<k;l++){//²¹Ò©°¡hdfghiodio 
					a[cc++]=qq[1][l];
					b[cc++]=qq[2][l];//ÄãÊÇÒ»¸öÊÕÒøÔ± µã»÷ÊäÈëÎÄ±¾£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿ 
				}//6969Ë¯°ÉË¯°ÉË¯°ÉË¯°É 
				cc=0;//9178£¿ 
				if(np1.count(a)&&np2.count(b))cnt++;//¾ÈÃüÑ½        ÎÒÒª´ò¿¨µÄËÀ 
		}
		cout<<cnt;//9191 9191
		cnt=0;//7891//È«CSP×î¹îÒìµÄ´úÂë£¬¿´Íê²»¸ãÀû°Â²¨µÂµÄÊÇÕâ¸ö
	}//µã»÷ÊäÈëÎÄ±¾ ¶Ò¡£²¿¶Ó¡£ ¶Ò¡£Ó²¸ÇÊÂ¡£¾­µä£¬¡£ÍõÃÀÏÍ£¬£¡Ê²Ã´Ê÷Ö¦¡£ 
}
}
