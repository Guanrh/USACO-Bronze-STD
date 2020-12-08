//Luogu P1217 std by Marco
using namespace std;
#define ll long long//定义ll为long long（打出ll就等于打出long long）
#include<cstdio>

int a,b,cnt,temp,bl,digit[10];
ll num;

int isPrime(int x)//判断这个数是不是质数
{
	for (int i=2;i*i<=x;i++)
		if (x%i==0) return 0;
	return 1;
}

void gen(int pos)//生成回文数的第pos位
{
	init();
	if (( (bl%2==0) && (pos>bl/2) ) || ( (bl%2==1) && (pos>bl/2+1) ))//当我们生成了超过一半的数字之后（奇偶要分别判断）
	{																//因为是回文数，所以生成前一半的数就知道后面的了
		num=0;//num储存生成出来的回文数
		for (int i=1;i<=pos-1;i++) num=num*10+digit[i];//前半部分
		for (int i=pos-(bl%2)-1;i>=1;i--) num=num*10+digit[i];//后半部分
		if (num>=a && num<=b && isPrime(num)) printf("%lld\n",num);//假如说这个数在范围内而且是质数的话就输出
		return;
	}
	for (int i=(pos==1?1:0);i<=9;i++)//这位可以是0~9，分别枚举，但是第一位不能是0
	{
		digit[pos]=i;//把每一位的数字储存在digit数组里
		gen(pos+1);//生成下一位
	}
}

int main()
{
	scanf("%d%d",&a,&b);//a和b分别储存两个边界
	cnt=0;//cnt储存b这个数有多少位（我们就生成多少位的）
	temp=b;
	while(temp) cnt++,temp/=10;//算出b有多少位
	for (int i=1;i<=cnt;i++)
	{
		bl=i;//bl记录我们要生成i位的回文数
		gen(1);//开始生成第一位
	}
}