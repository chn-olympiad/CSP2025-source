#include<bits/stdc++.h>
#include<string>
const int N=1e6+3;
 using namespace std;
 int main(){
 		freopen("xor.in","r",stdin);
	 	freopen("xor.out","w",stdout);
    int n,k,m=0,a[N];
    cin>>n>>k;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	int ans=0;
    	ans=a[i]|a[i+1];
    	m+=ans;
    	ans+=0;
	}
	cout<<m;
    return 0;
 }
 /*剧场1
   A:老C不在我就是无敌的，哈哈哈。
   B:真的吗？你看那。
   A:包真...他好像进城了。
   B：那你看看身后。
   A：WC！你不是去城里加班了吗？
   C：oh my god！宝贝，我只是去理个发。我说过，你在c++鸟村只能算个《萝莉》。
   A：不好 是不够野但一定“史”的野史中记载的GAY老！快跑啊！
   C：oh，宝贝，我是多么的爱你。我想要......自己掰开。
   B：Good luck,gey老和他的小娇妻 
   完 
   
   
   剧场2
   A:我很丑，但是我很温柔...的朋有。
   B:吉隆坡的天气还在翻云又赋雨...打火机。
   C：烦死了！信不信我直接一个法修散打给你砍成臊子。
   B:当心眼睛！
   A,C:啊，我的眼睛。
   B：没事吧？
   A,C：阿玛替拉斯。
   B:...
   B:六百六十六，演都不演了。
   A:咱来接歌吧！高峰期的街上堆满车子，长长的轨道堵塞max，ALSTOLAL纷飞中，患上了花粉症的ASKMALLOW
   B： KOKSO AND PLAKSO,AND CLAPKONG OR ASKMILOW ,KILOUMOSTERS FA XIU SAN DA,听着流行的歌 CLUP YOUR HANDS UP;
   C：我再来 我要带着我的旗帜我的奖章带上我的兄弟们在山顶上面摆造型- 
   A： 我要比你们看到过的听到过的那些所有花里胡哨加在一起还要顶
   B：我要把这天地之间全部染成红色我要化作一朵六千里的火烧云
   A,B,C:从武当燥到南少林，从武当燥到南少林 ，就像麒麟 ！
   宿管阿姨：半夜唱歌蹦迪，影响他人休息，-1分。
   A,B,C：啊.....
   完！ 
 */ 
