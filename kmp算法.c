#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 

#define T_LENGTH 10
#define S_LENGTH 22

void GetNext(char string[], int next[]);
int GetIndex(char s[], char t[], int next[]);

int main() {

	int next[T_LENGTH+1] = {};
	char s[S_LENGTH] = "ehgyababaaabaeeeeeeee";
	char t[T_LENGTH] = "ababaaaba";
	GetNext(t, next);
	int Index = GetIndex(s, t, next);
	printf("原子串为：");
	for (int i = 0; i < T_LENGTH; i++) printf("%c", t[i]);
	printf("\n原主串为：");
	for (int i = 0; i < S_LENGTH; i++) printf("%c", s[i]);
	printf("\n从主串中的第%d个位置开始：", Index+1);
	for (int i = Index; i < S_LENGTH; i++) printf("%c", s[i]);
	return 0;
}
void GetNext(char string[], int next[]) {
	int i = 0;	// i 位置代表 string 字符串的当前位置下标 
	int j = -1;	// j 表示需要回溯的位置
	next[0] = -1;	//根据公式，首字符的 next 值为 0。但是此处为 -1 为了和后面保持一致	
	while (i < T_LENGTH) {
		// j自增一次后才是正确初始位置 0 
		if ((j == -1) || (string[i] == string[j])) next[++i] = ++j;			
		else j = next[j];
	}
}
int GetIndex(char s[], char t[], int next[]) {

	int i = 0;
	int j = -1;
	while (i < S_LENGTH - 1 && j < T_LENGTH - 1) {
		if (j == -1 || s[i] == t[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j >= T_LENGTH - 1)  return i - T_LENGTH + 1;
	else return -1;
}