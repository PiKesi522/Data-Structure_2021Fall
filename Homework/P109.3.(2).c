#include<stdio.h>
#include<string.h>

void reverse(char* str)
{	
	char tmp = *str;//用tmp存入 字符串的第一个字符
	int len = strlen(str);//求当前字符串的长度 ps:每次递归，长度都会变化
	*str = *(str+len-1);//将'\0'的前一个元素赋给第一个
	*(str+len-1) = '\0';//将'\0'的前一个元素先赋成'\0'
	if(strlen(str)>1)//当字符串长度大于1，递归  ps:每次替换一直向中间逼近，当没有字符或只有一个字符的时候都不必继续
		reverse(str+1);//进行递归，首地址指针后移
	*(str+len-1) = tmp;//全部递归完成后，将'\0'还原成原来的中间元素	
}

