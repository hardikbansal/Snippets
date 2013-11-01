#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<set>
#include<dequeue>
#include<cmath>
using namespace std;




/////////////////////////////////////////Start from Here///////////////////////////////////////



#define ru read_unit()
#define BUF 4096 // block size on my disk is 4KBs
char ibuf[BUF];
int ipt = BUF;
int read_uint() {
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	if (ipt == BUF) {
	    fread(ibuf, 1, BUF, stdin);
	    ipt = 0;
	    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	}
	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	if (ipt == BUF) {
	    fread(ibuf, 1, BUF, stdin);
	    ipt = 0;
	    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}