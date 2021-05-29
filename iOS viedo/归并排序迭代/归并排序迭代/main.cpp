//
//  main.cpp
//  归并排序迭代
//
//  Created by 王天亮 on 2020/10/13.
//

#include <iostream>
#include <vector>
#include <stack>


using namespace std;

void merge(vector<int>&, int, int, int);
void mergesort(vector<int>&, int, int);
void merge(vector<int> &vec, int start, int end, int mid)
{
    vector<int> temp;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (vec[i] < vec[j])
        {
            temp.push_back(vec[i++]);//将vec[i]压入temp中，i++指向下一元素
        }
        else
        {
            temp.push_back(vec[j++]);//将vec[j]压入temp中，j++指向下一元素
        }
    }

    while (i <= mid)//防止还有未没合并的序列
    {
        temp.push_back(vec[i++]);
    }
    while (j <= end)//防止还有未没合并的序列
    {
        temp.push_back(vec[j++]);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        vec[start + i] = temp[i];
    }
}

void mergesort(vector<int> &vec, int start, int end)//拆分数组
{
    if (start < end)//迭代安全带
    {
        int mid = (start + end) / 2;
        mergesort(vec, start, mid);
        mergesort(vec, mid + 1, end);
        merge(vec, start, end, mid);
    }
}
int count = 0;


struct node {
    char s;
    int a;
    int b;
};
//1
//
bool isValid(string s) {
        stack<char> sta;
        int i = 0, j = 0;
        while(j < s.size()) {
            int flag = 0;
            for (i = j; i < s.size(); i++) {
                if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                    sta.push(s[i]);
                    flag++;
                } else {
                    break;
                }
            }
            if (flag == 0) {
                return false;
            }
            j = i;
            while(s[j] != '(' && s[j] != '[' && s[j] != '{' && !sta.empty()) {
                char ss = sta.top();
                sta.pop();
                if (ss == '(') {
                    if (s[j] == ')') {
                        j++;
                        continue;
                    } else {
                        return false;
                    }
                }
                if (ss == '[') {
                    if (s[j] == ']') {
                        j++;
                        continue;
                    } else {
                        return false;
                    }
                }
                if (ss == '{') {
                    if (s[j] == '}') {
                        j++;
                        continue;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
int main()
{
    string s = "()";
    printf("%d", isValid(s));
    
    
//    vector<int> num = { 7,0,2,1,3,5,8,6,9,4 };
//    int n = num.size();
//    mergesort(num, 0, n - 1);
//    vector<int>::iterator iter = num.begin();
//    cout << "排序后数组：" ;
//    for (iter; iter != num.end(); iter++)
//    {
//        cout << *iter << '\t';
//    }
}


