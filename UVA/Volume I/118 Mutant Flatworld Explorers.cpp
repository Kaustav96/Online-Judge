/* 118 Mutant Flatworld Explorers Accepted C++ 0.016 2011-01-29 06:56:23 */
#include<stdio.h>
#define LOST 0
#define SAFE 1
static int max_x,max_y;
static int scent[1000][2];
static int total;
char change_face(char face,char c){
	if(c=='R')
		switch(face){
			case 'E':
				return 'S';
			case 'S':
				return 'W';
			case 'W':
				return 'N';
			case 'N':
				return 'E';}
	else
		switch(face){
			case 'E':
				return 'N';
			case 'S':
				return 'E';
			case 'W':
				return 'S';
			case 'N':
				return 'W';}
}
bool forward(char face,int *x,int *y){
	int i;
	int temp_x,temp_y;
	temp_x=(*x);
	temp_y=(*y);
	switch(face){
		case 'N':
			temp_y++;	break;
		case 'E':
			temp_x++;	break;
		case 'W':
			temp_x--;	break;
		case 'S':
			temp_y--;   break;}
	if(temp_x>max_x||temp_x<0||temp_y<0||temp_y>max_y){
		for(i=0;i<total;i++)
			if((*x)==scent[i][0]&&(*y)==scent[i][1])
				return SAFE;
		return LOST;}
	else{
		(*x)=temp_x;
		(*y)=temp_y;
		return SAFE;
	}
}
int main(){	
	scanf("%d%d",&max_x,&max_y);
	char c=getchar();
	int x,y;
	char face;
	char str[20];	
	total=0;
	while(gets(str)){
		sscanf(str,"%d%d %c",&x,&y,&face);
		int i;
		bool lost;
		char command[200];
		gets(command);
		for(i=0,lost=false;command[i]!='\0'&&(!lost);i++){
			if(command[i]=='F'){
				if(!forward(face,&x,&y))				
					lost=true;}
			else
				face=change_face(face,command[i]);
		}
		if(lost){
			printf("%d %d %c LOST\n",x,y,face);
			scent[total][0]=x;
			scent[total++][1]=y;}
		else
			printf("%d %d %c\n",x,y,face);
	}
	return 0;
}
/*

給你一塊矩形土地的長寬，再依序給定每個機器人的初始位置狀況及一連串的指令集，你必須用你的程式求出每個機器人最後的位置狀況。

一個機器人的位置狀況包括了其坐標（ x 坐標， y 坐標），和它面向的方向（用 N , S , E , W 來分別代表北、南、東、西）。至於一個機器人所收到的指令集，是一個由字母 ' L ' ， ' R ' ， 和 ' F ' 所構成的字串，其分別代表： 

•左轉（Left）：機器人在原地往左轉 90 度。 
•右轉（Right）: 機器人在原地往右轉 90 度。 
•前進（Forward）: 機器人往其面向的方向向前走一格，且不改變其面向之方向。
從坐標 (x,y) 走至 (x,y+1) 的這個方向我們定義為北方。 

因為此矩形土地是有邊界的，所以一旦一個機器人走出邊界掉落下去，就相當於永遠消失了。不過這個掉下去的機器人會留下「標記 ( scent ) 」，提醒以後的機器人，避免他們從同一個地方掉下去。掉下去的機器人會把標記，留在他掉落之前所在的最後一個坐標點。所以對於以後的機器人，當他正位在有標記的地方時，這個機器人就會忽略會讓他掉下去的指令。

輸入說明 ：

輸入裡的第一列有2個正整數，代表這個矩形世界右上角頂點的坐標，其中假設這個世界的左下角頂點坐標為 ( 0 , 0 )。 

接下來是若干組有關機器人的初始位置狀況和指令集，每個機器人2列。第一列為位置狀況，包括了兩個整數和一個字元（ N , S , E 或 W ），代表機器人初始的位置坐標以及機器人最初所面對的方向。第二列則是指令集，是一個由 ' L ' ， ' R ' 和 ' F ' 所組成的字串。輸入以 end-of-file 作為結束。 

各機器人是依序動作的，也就是說，直到一個機器人作完他全部的動作，下一個機器人才會開始動作。 

所有機器人的初始位置皆會在矩形土地上，不會落在外面。任何坐標的最大值皆不會超過 50 。每個指令集的長度皆不會超過 100 個字元長。

輸出說明 ：

對於每一個機器人，你都必須輸出其最後所在的坐標和面對的方向。如果一個機器人會掉落出此世界外，你必須先輸出他在掉落前，最後的所在位置和面對的方向，再多加一個字： LOST 。

範例輸入 ： 

5 3
1 1 E
RFRFRFRF
3 2 N
FRRFLLFFRRFLL
0 3 W
LLFFFLFLFL

範例輸出 ：

1 1 E
3 3 N LOST
2 3 S

提示 ：

* 中文翻譯：Lucky 貓 英 中 

出處 ：

ACM 118 

*/