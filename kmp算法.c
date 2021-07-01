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
	printf("ԭ�Ӵ�Ϊ��");
	for (int i = 0; i < T_LENGTH; i++) printf("%c", t[i]);
	printf("\nԭ����Ϊ��");
	for (int i = 0; i < S_LENGTH; i++) printf("%c", s[i]);
	printf("\n�������еĵ�%d��λ�ÿ�ʼ��", Index+1);
	for (int i = Index; i < S_LENGTH; i++) printf("%c", s[i]);
	return 0;
}
void GetNext(char string[], int next[]) {
	int i = 0;	// i λ�ô��� string �ַ����ĵ�ǰλ���±� 
	int j = -1;	// j ��ʾ��Ҫ���ݵ�λ��
	next[0] = -1;	//���ݹ�ʽ�����ַ��� next ֵΪ 0�����Ǵ˴�Ϊ -1 Ϊ�˺ͺ��汣��һ��	
	while (i < T_LENGTH) {
		// j����һ�κ������ȷ��ʼλ�� 0 
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