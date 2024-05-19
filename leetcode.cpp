#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<string> letterCombinations(string digits) {
    map<int, string>m;
    vector<string>res;
    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[9] = "wxyz";
    int length = 1, size = digits.length();
    for (auto i : digits)
    {
        length *= m[i-'0'].length();
    }
    res.resize(length);
    int k = 0;
    if (k < size) {
        for (int a = 0; a < length; a++)
        {
            int i = digits[k]-'0';
            res[a] += m[i][a / (length / m[i].length())];
            if (k + 1 < size) {
                res[a] += m[digits[k+1]-'0'][a % (length / m[i].length()) / (length / m[i].length() / m[digits[k + 1]-'0'].length())];
                if (k + 2 < size) {
                    res[a] += m[digits[k+2]-'0'][a % (length / m[i].length() / m[digits[k + 1]-'0'].length()) / (length / m[i].length() / m[digits[k + 1]-'0'].length() / m[digits[k + 2]-'0'].length())];
                    if (k + 3 < size)
                    {
                        res[a] += m[digits[k+3]-'0'][a % (length / m[i].length() / m[digits[k + 1] - '0'].length() / m[digits[k + 2] - '0'].length()) / (length / m[i].length() / m[digits[k + 1] - '0'].length() / m[digits[k + 2] - '0'].length() / m[digits[k + 3] - '0'].length())];
                    }
                }

            }
        }
    }
    return res;
}

int main()
{
    vector<string>s=letterCombinations("23");
	return 0;
}