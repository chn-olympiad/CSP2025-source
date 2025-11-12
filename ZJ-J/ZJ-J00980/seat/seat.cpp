#include<bits/stdc++.h>
using namespace std;

/*

ÎÞÓï£¬ÓÃvscode¸´ÖÆ³ÉÁËÕâÑù£º 

8ï¿½ï¿½27 ï¿½ï¿½Ê¼ï¿½ï¿½ï¿½ï¿½ 

ï¿½ï¿½Ñ¹ï¿½ï¿½ï¿½ë£º#Shang4Shan3Ruo6Shui4

ï¿½ï¿½Òªï¿½ï¿½ï¿½ï¿½return0ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½

freopen ï¿½ï¿½ÒªÐ´ï¿½ï¿½freeopen

ï¿½ï¿½Òª#include<bits\stdc++.h>

Ò²ï¿½Ç³É¹ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½fcï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ì«ï¿½ó£¬±È½Ï²ï¿½ï¿½ï¿½ï¿½ï¿½ 


C:\Users\Administrator>fc "E:\ZJ-J00980\number\number.out" "C:\Users\Administrator\Desktop\number\number4.ans"
ï¿½ï¿½ï¿½Ú±È½ï¿½ï¿½Ä¼ï¿½ E:\ZJ-J00980\NUMBER\number.out ï¿½ï¿½ C:\USERS\ADMINISTRATOR\DESKTOP\NUMBER\NUMBER4.ANS
FC: ï¿½Ò²ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½


C:\Users\Administrator>

8ï¿½ï¿½51 È·ï¿½Ï±ï¿½ï¿½æ£¬ï¿½ï¿½Ê¼É¾ï¿½ï¿½ï¿½ï¿½ï¿½Ð·ï¿½ï¿½ï¿½ï¿½ï¿½Ä¼ï¿½ 

ÒÔÏÂÎªT2¹ý³Ì£º---------------------------------------------------------------------------------------- 

8£º55 ¿ªÊ¼Ð´T2

T2±È½ÏÈÆ ËäÈ»ÊÇÒ»¸ö¼òµ¥µÄ·ÖÖ§½á¹¹µÄÌâÄ¿£¬»ñÈ¡ÁËÅÅÃûÖ®ºó¿ÉÒÔÍ¨¹ýÊýÑ§·½·¨Ö±½ÓÇó³ö´ð°¸£¬µ«ÊÇ
¹«Ê½±È½ÏÄÑÇó ¸ãÁË°ëÌì×ÜËãÃ»ÎÊÌâÁË

9£º19 T2Ð´Íê 

*/

int a[110];//(?)

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	int xiaor=a[0];
	sort(a,a+n*m);
	int paiming;
	for(int i=0;i<n*m;i++){
		if(a[i]==xiaor){
			paiming=n*m-i;
		}
	}
	
	int c=(paiming-1)/n+1;
	
	cout<<c<<" ";
	
	if(c%2==0){
		cout<<n-((paiming-1)%n);
	}
	else cout<<(paiming-1)%n+1;
	return 0;
}
