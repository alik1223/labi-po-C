#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char data[265];
	int len;
}LNum;

LNum mulN(LNum f, int n) {
	LNum res;
	char temp[265];
	int buf = 0, i, j;
	for (i = 0, res.len = 0; i < f.len; i++, res.len++) {
		buf += (f.data[f.len - i - 1] - '0') * n;
		temp[res.len] = (buf % 10) + '0';
		buf /= 10;
	}
	if (buf)
		temp[res.len++] = (buf % 10) + '0';
	buf /= 10;
	if (buf)
		_itoa(buf, res.data, 10);
	else
		res.data[0] = 0;
	for (i = 0, j = strlen(res.data); i < res.len; i++)
		res.data[i + j] = temp[res.len - 1 - i];
	res.len += j;
	res.data[res.len] = 0;
	return res;
}

int complN(LNum f, LNum s) {
	int i;
	if (f.len == s.len) {
		for (i = 0; i < f.len; ++i) {
			if (f.data[i] != s.data[i]) {
				if (f.data[i] < s.data[i])
					return -1;
				else
					return 1;
			}
		}
		return 0;
	}
	if (f.len > s.len)
		return 1;
	else
		return -1;
}

LNum sum(LNum f, LNum s) {
	LNum res;
	char temp[265];
	int buf = 0, i;
	for (i = 0, res.len = 0; f.data[i] != '\0' && s.data[i] != '\0'; i++, res.len++) {
		buf += (f.data[f.len - i - 1] - '0') + (s.data[s.len - i - 1] - '0');
		temp[res.len] = (buf % 10) + '0';
		buf /= 10;
	}
	if (f.len < s.len) {
		res = f;
		f = s;
		s = res;
	}
	for (i = s.len; i < f.len; i++, res.len++) {
		buf += (f.data[f.len - i - 1] - '0');
		temp[res.len] = (buf % 10) + '0';
		buf /= 10;
	}
	if (buf)
		temp[res.len++] = (buf % 10) + '0';
	for (i = 0; i < res.len; i++)
		res.data[i] = temp[res.len - 1 - i];
	res.data[res.len] = 0;
	return res;
}

LNum mult(LNum f, LNum s) {
	LNum res, nmult;
	int i;
	int shift;
	if (f.len < s.len) {
		res = f;
		f = s;
		s = res;
	}
	res = mulN(f, s.data[s.len - 1] - '0');
	for (i = 1; i < s.len; i++) {
		nmult = mulN(f, s.data[s.len - i - 1] - '0');
		for (shift = 1; shift <= i; shift++)
		{
			nmult.data[nmult.len] = '0';
			nmult.len = nmult.len + 1;
			nmult.data[nmult.len] = '\0';
		}
		res = sum(res, nmult);
	}
	return res;
}

LNum dif(LNum f, LNum s) {
	LNum res;
	char temp[265];
	int buf = 0, i, tbuf;
    int j=complN(f,s);
    if (j==-1)
    {
    res = f;
    f = s;
    s = res;
    }
	for (i = 0, res.len = 0; f.data[i] != '\0' && s.data[i] != '\0'; i++, res.len++) {
		tbuf = (f.data[f.len - i - 1] - '0') - (s.data[s.len - i - 1] - '0') - buf;
		if (tbuf < 0) {
			buf = 1;
			tbuf += 10;
		}
		else
			buf = 0;
		temp[res.len] = tbuf + '0';
	}
	for (i = s.len; i < f.len; i++, res.len++) {
		tbuf = (f.data[f.len - i - 1] - '0') - buf;
		if (tbuf < 0) {
			buf = 1;
			tbuf += 10;
		}
		else
			buf = 0;
		temp[res.len] = tbuf + '0';
	}
	while (temp[res.len - 1] == '0')
		res.len--;
	for (i = 0; i < res.len; i++)
		res.data[i] = temp[res.len - 1 - i];
	res.data[res.len] = 0;
	return res;
}

LNum divLN(LNum f, LNum s) {
	int i, j = 1;
	LNum res;
	for (i = 0; 1; i++) {
		j = complN(f, mulN(s, i));
		if (j == -1) {
			i--;
			break;
		}
		if (j == 0)
			break;
	}
	_itoa(i, res.data, 10);
	res.len = strlen(res.data);
	return res;
}

LNum calc(char sign, LNum f, LNum s) {
	switch (sign) {
	case '+':
		return sum(f, s);
	case '-':
		return dif(f, s);
	case '*':
		return mult(f, s);
	case '/':
		return divLN(f, s);
	}
}


int main() {
	LNum numbers[20];
	char signs[20];
	char input[200];
	LNum h, a = { "225", 3 }, b = { "2", 1 };
	int len, i, flag = 0, isNextNumber = 0;
	int nsize = 0, ssize = 0;
	h = divLN(a, b);
	numbers[nsize].len = 0;
	scanf("%s", input);
	for (i = 0; input[i] != 0; i++) {
		if (input[i] >= '0' && input[i] <= '9') {
			numbers[nsize].data[numbers[nsize].len] = input[i];
			numbers[nsize].len++;
			numbers[nsize].data[numbers[nsize].len] = 0;
			isNextNumber = 1;
		}
		else {
			if (i != 0 && isNextNumber) {
				++nsize;
				numbers[nsize].len = 0;
			}
			isNextNumber = 0;
			if (input[i] == '(') {
				flag = 0;
				signs[ssize++] = '(';
				continue;
			}
			if (input[i] == ')') {
				flag = 0;
				while (flag != 2) {
					ssize--;
					if (ssize < 0) {
						ssize = 0;
						break;
					}
					if (signs[ssize] == '(') {
						flag++;
					}
					else {
						numbers[nsize - 2] = calc(signs[ssize], numbers[nsize - 2], numbers[nsize - 1]);
						--nsize;
						numbers[nsize].len = 0;
					}
				}
				flag = 0;
				continue;
			}
			if (flag==1 &&(input[i]=='+' || input[i]=='-') ) {
				while (1) {
					ssize--;
					if (ssize < 0) {
						ssize = 0;
						break;
					}
					numbers[nsize - 2] = calc(signs[ssize], numbers[nsize - 2], numbers[nsize - 1]);
					--nsize;
					numbers[nsize].len = 0;
				}
			}
			if (input[i] == '*' || input[i] == '/') {
				flag = 1;
			}
			signs[ssize++] = input[i];
		}
	}
	if (i != 0 && isNextNumber) {
		++nsize;
	}
	while (1) {
		ssize--;
		if (ssize < 0)
			break;
		numbers[nsize - 2] = calc(signs[ssize], numbers[nsize - 2], numbers[nsize - 1]);
		--nsize;
	}
	printf("=%s", numbers[0].data);
}
