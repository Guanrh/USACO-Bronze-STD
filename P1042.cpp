//Luogu 1042 std by Marco
using namespace std;
#include<cstdio>
#include<cstring>

char s[2510][30];
int n=0,a=0,b=0;

int abs(int x,int y){return x-y>0?x-y:y-x;}//算绝对值

void init()
{
	while (1)//不断读入
	{
		scanf("%s",s[++n]+1);
		for (int i=1;i<=strlen(s[n]+1);i++)
			if (s[n][i]=='E') return;//检查每一个字符，碰到E时退出
	}
}

void judge(int x,int final)//处理第x行，获胜分为final
{
	for (int i=1;i<=strlen(s[x]+1);i++)//检查每一个字符
	{
		if (s[x][i]=='E')//碰到E就停掉
		{
			printf("%d:%d\n",a,b);
			return;
		}
		if (s[x][i]=='W') a++;//分别加分
		if (s[x][i]=='L') b++;
		if((a>=final || b>=final) && abs(a,b)>=2)//有人获胜就输出，清零计分
		{
			printf("%d:%d\n",a,b);
			a=b=0;
		}
	}
}

int main()
{
	init();//读入数据
	for (int i=1;i<=n;i++) judge(i,11);//处理第i行，获胜分为11
	printf("\n");
	a=b=0;
	for (int i=1;i<=n;i++) judge(i,21);//处理第i行，获胜分为21
}